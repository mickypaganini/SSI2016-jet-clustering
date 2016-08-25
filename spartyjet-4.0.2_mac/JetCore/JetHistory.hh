// Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
//                 Brian Martin, and Christopher Vermilion
//
//----------------------------------------------------------------------
// This file is part of SpartyJet.
//
//  SpartyJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  SpartyJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with SpartyJet; if not, write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#ifndef _JETHISTORY_HH_
#define _JETHISTORY_HH_

/// Here is coded a history structure for jets.
/// There are 2 main goals behind this design
///  - code the structure and its feature only once and independently of any other class
///  - being able to provide this structure to any other class.
/// First part is coded in HistoryNode, the second in HistoryProvider.
/// To give history structure to class A make it inherit HistoryProvider<A>.

#include "Jet.hh"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <list>

namespace SpartyJet {

/// \class HistoryNode<T> defines a history structure
///
///  HistoryNode holds a a pointer to a arbitrary class T which needs history.
///  It expects the class T has a public function hindex() (returning an index in a history sequence)  
template<class T>
class HistoryNode  {
public:
  typedef std::vector<T*> hist_list_t;
  typedef std::vector<const T*> hist_list_const_t;
  typedef std::list<HistoryNode*> node_list_t;
  
  class history_index_sort {
  public:
    bool operator()(const T* o1, const T* o2) {
      // put unitialized indices (-1) at the end
      return (o1->hindex() < o2->hindex()) && (o1->hindex() != -1);
    }
  };
  
  HistoryNode() : child(0), item(0), dij(-1), jet(0), hindex(-1), m_ownjet(false), m_changed(false) {}
  virtual ~HistoryNode();
      
  /// a safe way to access the jet    
  Jet* getJet() const {if (!jet || m_changed) return buildJet(); else return jet;}
  void setJet(Jet* j) {if(jet && m_ownjet) delete jet; jet = j; m_ownjet = false;}
  void adoptJet(Jet* j) {if(jet && m_ownjet) delete jet; jet = j; m_ownjet = true;}
  bool own_jet() const {return m_ownjet;}
  void changed() {m_changed = true; if(child) child->changed();}

  void retrieveConstituentJets(Jet::constit_vect_t& constits) const;
  
  /// retrieve all parents of this node, putting them in nodes. Bool arguments control which node are added.
  void retrieveParentNodes(hist_list_t& nodes, bool addOrphan, bool addNonOrphan);
  void retrieveParentNodes(hist_list_const_t& nodes, bool addOrphan, bool addNonOrphan) const;
  /// shortcut for retrieveParentNodes(addOrphan=true,addNonOrphan=true)
  hist_list_t fullHistory();    
  hist_list_const_t fullHistory() const;    
  
  node_list_t parents;
  HistoryNode* child;
  T* item;
  
  double dij;
  mutable Jet* jet; // building the jet does not reflect a change in history
  int hindex;

protected:
  /// create a jet by adding up this node's constituents
  Jet* buildJet() const;

  mutable bool m_ownjet; // these track the Jet*, not the history structure
  mutable bool m_changed;
};


/// \class HistoryProvider
///
/// This class works together with HistoryNode to provide a history structure to a class
/// The intended use of it is 'class A : public HistoryProvider<A> '.
///
/// The advantage of this mechanism is A will inherit entirely the history structure 
/// from HistoryNode without having any code to implement on its side.

template<class T>
class HistoryProvider {
public:
  typedef typename HistoryNode<T>::hist_list_t hist_list_t;
  typedef typename HistoryNode<T>::hist_list_const_t hist_list_const_t;

protected: // never use HP other than via inheritance!
  HistoryProvider() {init();}
  HistoryProvider(const HistoryProvider& h) {init(); copy(h);}
  template <class Q>
  HistoryProvider(const HistoryProvider<Q>& h) {init(); copy(h);}

public:
  void init() {history.item = static_cast<T*>(this);}
  virtual ~HistoryProvider() {deleteParents();}
  
  virtual void deleteParents() {
    std::vector<T*> myParents = parents();
    for (size_t i = 0; i < myParents.size(); i++)
      delete myParents[i];
    history.parents.clear();
  }
  
  const HistoryProvider& operator=(const HistoryProvider<T>& h) {
    if (this == &h) return *this;
    // clear out jet, substructure if it already exists
    setJet(0);
    deleteParents();
    copy(h);
    return *this;
  }
  
  // can copy history from any other kind of HistoryProvider<Q>
  template<class Q>
  const HistoryProvider& operator=(const HistoryProvider<Q>& h) {
    if (dynamic_cast<Q*>(this) == &h) return *this;
    // clear out jet, substructure if it already exists
    setJet(NULL);
    deleteParents();
    copy(h);
    return *this;
  }
  
  template<class Q>
  void copy(const HistoryProvider<Q>& h);
        
  // load some basic history info from another HistoryProvider<T'>
  template<class HISTORY_t>
  void init(const HISTORY_t& hnode) {
    history.dij = hnode.dij();
    history.hindex = hnode.hindex();
    history.jet = hnode.jet();
  }
  
  void retrieveConstituentJets(Jet::constit_vect_t& constits) const
    {history.retrieveConstituentJets(constits);}
  
  void retrieveParentNodes(hist_list_t& nodes, bool addOrphan, bool addNonOrphan)
    {history.retrieveParentNodes(nodes, addOrphan, addNonOrphan);}
  void retrieveParentNodes(hist_list_const_t& nodes, bool addOrphan, bool addNonOrphan) const
    {history.retrieveParentNodes(nodes, addOrphan, addNonOrphan);}

  hist_list_t fullHistory() {return history.fullHistory();}
  hist_list_const_t fullHistory() const {return history.fullHistory();}
  
  std::vector<T*> parents() const {
    typename HistoryNode<T>::node_list_t::const_iterator it, itE;
    it = history.parents.begin();
    itE = history.parents.end();
    std::vector<T*> parentItems;
    for (; it != itE; ++it) parentItems.push_back((*it)->item);
    return parentItems;
  }
  size_t nParents() const {return history.parents.size();}
  T* child() const        {return history.child ? history.child->item : NULL;}
  
  void addParent(T* p)    {if(p) history.parents.push_back(&(p->history)); history.changed();}
  void removeParent(T* p) {history.parents.remove(&(p->history)); history.changed();}
  void setChild(T* p)     {history.child = p ? & (p->history) : NULL;}
  
  /// safe access to jet (including a rebuild if necessary)
  Jet* getJet()  const {return history.getJet();}
  /// direct access to jet 
  Jet* jet()     const {return history.jet;}
  bool own_jet() const {return history.own_jet();}
  
  double dij()   const {return history.dij;}
  int hindex()   const {return history.hindex;}
  double max_dij_so_far() const {
    double max_dij = dij();
    std::vector<T*> my_parents = parents();
    for (size_t i = 0; i < my_parents.size(); ++i)
        max_dij = std::max(max_dij, my_parents[i]->max_dij_so_far());
    return max_dij;
  }
  
  void setJet(Jet* j)        {history.setJet(j);}
  void adoptJet(Jet* j)      {history.adoptJet(j);}
  void setDij(float dij)     {history.dij = dij;}
  void setHindex(int hindex) {history.hindex = hindex;}

protected:
  HistoryNode<T> history;
  
public:
  /// banner to go at top of printout
  void print_banner() const;
  /// print a line corresponding to this history node
  void print() const;
  /// print full history from this node down
  void dumpHistory(int indent=0) const;
};



/// A super simple actual use of history node :
class HistoryElement : public HistoryProvider<HistoryElement> {
public:
  HistoryElement() {}
  HistoryElement(const HistoryElement& h) : HistoryProvider<HistoryElement>(h) {}
  const HistoryElement& operator=(const HistoryElement& h) {
    HistoryProvider<HistoryElement>::operator=((HistoryProvider<HistoryElement>&)(h));
    return *this;
  }
  virtual ~HistoryElement() {}
};



// *****************************************************************************
// Inline and template definitions

#ifndef __CINT__ // rootcint doesn't need to see this...

template<class T>
HistoryNode<T>::~HistoryNode() {
  if (m_ownjet) {
    // to protect against jet deleting this HN recursively...
    jet->set_history(0);
    delete jet;
  }
}


template<class T>
void HistoryNode<T>::retrieveConstituentJets(Jet::constit_vect_t& constits) const {
  typename HistoryNode::node_list_t::const_iterator it, itE;
  it = parents.begin();
  itE = parents.end();
  if (it == itE && jet) // this is a leaf node
    constits.push_back(jet);
  else for (; it != itE; ++it) {
    (*it)->retrieveConstituentJets(constits);
  }
}


template<class T>
typename HistoryNode<T>::hist_list_t
HistoryNode<T>::fullHistory() {
  hist_list_t hist;
  retrieveParentNodes(hist, true, true);
  std::sort(hist.begin(), hist.end(), history_index_sort());
  return hist;
}

template<class T>
typename HistoryNode<T>::hist_list_const_t
HistoryNode<T>::fullHistory() const {
  hist_list_const_t hist;
  retrieveParentNodes(hist, true, true);
  std::sort(hist.begin(), hist.end(), history_index_sort());
  return hist;
}

template<class T>
void HistoryNode<T>::retrieveParentNodes(std::vector<T*>& nodes, bool addOrphan, bool addNonOrphan) {
  typename HistoryNode::node_list_t::const_iterator it, itE;
  it = parents.begin();
  itE = parents.end();
  if (it == itE) { // this is a leaf node
    if (addOrphan) nodes.push_back(item);
    return;
  } else for (; it != itE; ++it)
      (*it)->retrieveParentNodes(nodes, addOrphan, addNonOrphan);
  if (addNonOrphan) nodes.push_back(item);
}

template<class T>
void HistoryNode<T>::retrieveParentNodes(std::vector<const T*>& nodes, bool addOrphan, bool addNonOrphan) const {
  typename HistoryNode::node_list_t::const_iterator it, itE;
  it = parents.begin();
  itE = parents.end();
  if (it == itE) { // this is a leaf node
    if (addOrphan) nodes.push_back(item);
    return;
  } else for (; it != itE; ++it)
      (*it)->retrieveParentNodes(nodes, addOrphan, addNonOrphan);
  if (addNonOrphan) nodes.push_back(item);
}

template <class T>
Jet* HistoryNode<T>::buildJet() const {
  m_changed = false;
  if (!jet) {
    // if jet does not exist yet, create one and adopt it
    jet = new Jet();
    m_ownjet = true;
    HistoryElement *h = dynamic_cast<HistoryElement*> (item);
    if(h) jet->set_history(h);
  }
  jet->reset_momentum(0., 0., 0., 0.);
  Jet::constit_vect_t constits;
  retrieveConstituentJets(constits);
  Jet::constit_vect_t::iterator it, itE;
  it = constits.begin();
  itE = constits.end();
  for (; it != itE; ++it)
    *jet += **it;
  return jet;
}


template<class T>
template<class Q>
void HistoryProvider<T>::copy(const HistoryProvider<Q>& h) {
  setDij(h.dij());
  setHindex(h.hindex());
  // add parents recursively and set links
  std::vector<Q*> p = h.parents();
  for (size_t i = 0; i < p.size(); i++) {
    T *parent = new T();
    *parent = *(p[i]);
    parent->setChild(static_cast<T*>(this)); // this happens in constructor; can't downcast
    addParent(parent);
  }
  // copy over jet if we are at a leaf
  if (p.size() == 0) {
    Jet *j = new Jet();
    if (h.jet()) *j = *(h.jet());
    adoptJet(j);
  }
}

// specialization to HP<HistoryElement>
template<>
template<class Q>
void HistoryProvider<HistoryElement>::copy(const HistoryProvider<Q>& h) {
  setDij(h.dij());
  setHindex(h.hindex());
  // add parents recursively and set links
  std::vector<Q*> p = h.parents();
  for (size_t i = 0; i < p.size(); i++) {
    HistoryElement* parent = new HistoryElement();
    *parent = *(p[i]);
    parent->setChild(static_cast<HistoryElement*>(this)); // this happens in constructor; can't downcast
    addParent(parent);
  }
  // copy over jet if we are at a leaf
  if (p.size() == 0) {
    Jet *j = new Jet();
    if (h.jet()) *j = *(h.jet());
    adoptJet(j);
    j->set_history(static_cast<HistoryElement*>(this));
  }
}

// banner to go at top of printout
template<class T>
void HistoryProvider<T>::print_banner() const {
  std::cout << "Ind Parents     Chld Jet Dij      Jet pt    (input?)" << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
}

template<class T>
void HistoryProvider<T>::print() const {
  Jet* j = getJet();
  std::cout << std::setw(4) << hindex();
  typename HistoryNode<T>::node_list_t::const_iterator it, itE;
  it = history.parents.begin();
  itE = history.parents.end();
  for (; it != itE; ++it) std::cout << std::setw(4) << (*it)->hindex;
  // pad out to 12 char. wide for parents (fits up to four)
  for (size_t i = history.parents.size(); i < 4; ++i) std::cout << std::setw(4) << "";
  int child_ind = history.child ? history.child->hindex : -3;
  std::cout << std::setw(4) << child_ind;
  // if one parent, print out parent's index
  std::cout << std::setw(4);
  if (history.parents.size() == 1) std::cout << (*(history.parents.begin()))->getJet()->input_index();
  else std::cout << j->input_index();
  printf("%10.3e %10.3f %6d\n", history.dij, j->perp(), j->is_input());
}

template<class T>
void HistoryProvider<T>::dumpHistory(int indent) const {
  Jet* j = getJet();
  Jet::constit_vect_t cvec;
  retrieveConstituentJets(cvec);
  if (indent == 0) {std::cout << "HistoryNode for Jet "; j->print();}
  else {
    std::cout << std::setw(3) << indent << ")";
    for (int i = 0; i < indent; i++) std::cout << "| ";
    j->print();
  }
  if (cvec.size() > 1) {
    for (int i = 0; i < indent; i++) std::cout << "  ";
    std::cout << "   Constituents are:" << std::endl;
    Jet::constit_vect_t::iterator it, itE;
    it = cvec.begin(); itE = cvec.end();
    for (; it != itE; ++it) 
      std::cout << std::setw(4) << (*it)->input_index();
    std::cout << std::endl;
  }
  std::vector<T*> p = parents();
  for (size_t i = 0; i < p.size(); i++) p[i]->dumpHistory(indent+1);
}

#endif // ifdef __CINT__


} // namespace SpartyJet
#endif
