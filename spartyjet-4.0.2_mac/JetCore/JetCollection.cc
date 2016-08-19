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

#include "JetCollection.hh"
#include "JetHistory.hh"
#include "JetStructure.hh"

#include "fastjet/ClusterSequence.hh"
using namespace fastjet;

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

namespace SpartyJet {

// Copy in a fastjet::ClusterSequence.  Assumes jets are found inclusively.
JetCollection::JetCollection(const ClusterSequence& cs) {
  vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());
  for (size_t i = 0; i < jets.size(); ++i)
    insert(jets[i], cs);
}

JetCollection& JetCollection::operator=(const JetCollection& coll) {
  // Call operator= for parent class
  m_jets = coll.jet_list();
  return *this;
}


// Copies jets (makes new Jet objects, doesn't just copy pointers) and history.
// If the leaves of the input history tree point to original input jets these
//   pointers are copied.
void JetCollection::deep_copy(const JetCollection& jcoll) {
  const JetMomentMap* tmpMap = &(jcoll.m_map);

  // Schedule moments from input Coll
  // Put input moments in the front to preserve order
  const JetMomentMap::moment_store_t& moments_in = tmpMap->get_jet_moments();
  JetMomentMap::moment_store_t::const_reverse_iterator it = moments_in.rbegin();
  JetMomentMap::moment_store_t::const_reverse_iterator itE = moments_in.rend();
  for(; it != itE; ++it) m_map.schedule_jet_moment_front(*it);

  // Do the copy
  Jet::jet_list_t::const_iterator jit  = jcoll.begin();
  Jet::jet_list_t::const_iterator jitE = jcoll.end();
  for(; jit != jitE; ++jit) {
    // copy in jets
    Jet* j = new Jet(*jit); // also sets up HE
    m_jets.push_back(j);
    //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
    
    // Copy the map correctly (associating values to new Jets)
    const JetMomentMap::moment_store_t& jet_moms = tmpMap->get_jet_moments(*jit);
    JetMomentMap::moment_store_t::const_iterator mit = jet_moms.begin();
    JetMomentMap::moment_store_t::const_iterator mitE = jet_moms.end(); 
    for(; mit != mitE; ++mit) m_map.set_jet_moment(j, *mit);
  }

  // Copy event moments
  const JetMomentMap::moment_store_t& evt_moms = tmpMap->get_event_moments();
  JetMomentMap::moment_store_t::const_reverse_iterator mit = evt_moms.rbegin();
  JetMomentMap::moment_store_t::const_reverse_iterator mitE = evt_moms.rend(); 
  for(; mit != mitE; ++mit) {
    m_map.schedule_event_moment_front(*mit);
    m_map.set_event_moment(*mit);
  }
}


void JetCollection::deep_copy(const Jet::jet_list_t& jcoll) {
  Jet::jet_list_t::const_iterator jit  = jcoll.begin();
  Jet::jet_list_t::const_iterator jitE = jcoll.end();
  for (; jit != jitE; ++jit) {
    m_jets.push_back(new Jet(*jit)); // copies history if any
    //back()->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(back(), this)));
  }
}


/// Load jets and substructure from a ClusterSequence.
/* Input particles to the ClusterSequence should correspond to constituents in
 *  the original input JetCollection -- an input PseudoJet should have a
 *  user_index() corresponding to a Jet's input_index() in inputJets.  The input
 *  jet can later be retrieved with
 *  inputJets.get_constituent(pseudojet.user_index())
 */
void JetCollection::insert(const ClusterSequence& cs) {
  vector<PseudoJet> output_jets = sorted_by_pt(cs.inclusive_jets());
  for (size_t i = 0; i < output_jets.size(); i++)
    insert(output_jets[i], cs);
}

/// Load just one jet from a CS
void JetCollection::insert(const PseudoJet& pj, const ClusterSequence& cs) {
  Jet *j = new Jet(pj);
  push_back(j);
  load_HistoryElement(j->history(), pj, cs);
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}

/// Load a jet with specific subjets
void JetCollection::insert(const PseudoJet& pj, const vector<PseudoJet>& subjets,
                         const ClusterSequence& cs) {  
  Jet *j = new Jet(pj);
  push_back(j);
  replace(j, pj, subjets, cs); // inefficient but saves code duplication
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}

/// Copies in a specific jet, with specific subjets, but no history!
///  top-level history element can have any number of parents, not nec. two
void JetCollection::insert(const PseudoJet& pj, const vector<PseudoJet>& subjets) {
  Jet *j = new Jet(pj);
  push_back(j);
  replace(j, pj, subjets); // inefficient but saves code duplication
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}

/// Replace one jet
void JetCollection::replace(Jet *j, const PseudoJet& pj, const ClusterSequence& cs) {
  *j = pj;
  j->clear_history();
  load_HistoryElement(j->history(), pj, cs);
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}

/// Replace a jet with specific subjets
void JetCollection::replace(Jet* j, const PseudoJet& pj, const vector<PseudoJet>& subjets,
                         const ClusterSequence& cs) {  
  *j = pj;
  j->clear_history();
  HistoryElement* he = j->history();
  
  for (size_t i = 0; i < subjets.size(); ++i) {
    HistoryElement* parent = new HistoryElement();
    parent->setChild(he);
    he->addParent(parent);
    load_HistoryElement(parent, subjets[i], cs); 
  }
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}

/// Replaces a specific jet, with specific subjets, but no history!
void JetCollection::replace(Jet* j, const PseudoJet& pj, const vector<PseudoJet>& subjets) {
  *j = pj;
  j->clear_history();
  HistoryElement* he = j->history();
  
  for (size_t i = 0; i < subjets.size(); ++i) {
    HistoryElement* parent = new HistoryElement();
    parent->setChild(he);
    he->addParent(parent);
    parent->adoptJet(new Jet(subjets[i])); 
  }
  //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
}


void JetCollection::swap(JetCollection& jcoll) {
  m_jets.swap(jcoll.m_jets);
  m_map.swap(jcoll.m_map);
}


void JetCollection::clear() {
  m_jets.clear();
  m_map.clear_event();  // clears out moments for specific jets, but not scheduled moments
}

// remove jets from this collection and delete them
void JetCollection::clear_and_delete() {
  for (size_t i = 0; i < m_jets.size(); ++i) {
    delete m_jets[i]->history();
    delete m_jets[i];
  }
  m_jets.clear();
  m_map.clear_event(); // clears out calculated moments, but leaves scheduled moments and event moments
}


void JetCollection::history_dump(Jet* j) const {
  cout << "JetCollection: dumping history" << endl;
  vector<HistoryElement*> history = full_history(j);
  for (size_t i = 0; i < history.size(); ++i) {
    if (i == 0) history[i]->print_banner();
    history[i]->print();
  }
  if (history.size() == 0) {
    cout << "  No history yet, printing jets:" << endl;
    for (size_t i = 0; i < size(); ++i)
      (*this)[i]->print();
  }
}


// contructs full, ordered history for jet j (all if j=0)
vector<HistoryElement*> JetCollection::full_history(Jet* j) const {
  vector<HistoryElement*> history;
  
  if (j != 0) {
    history = j->history()->fullHistory();
  } else {
    Jet::jet_list_t::const_iterator it  = begin();
    Jet::jet_list_t::const_iterator itE = end();
    for (; it != itE; ++it) {
      HistoryElement *he = (*it)->history();
      // get full history for each jet, add to history
      vector<HistoryElement*> jet_full_history = he->fullHistory();
      std::copy(jet_full_history.begin(), jet_full_history.end(), back_inserter(history));
    }
  }
  // sort history steps by hindex
  sort(history.begin(), history.end(), HistoryNode<HistoryElement>::history_index_sort());
  return history;
}


// -------------- Substructure methods -----------------------------------------

// Methods below work on final jets as well as subjets:

vector<const Jet*> JetCollection::get_constituents(const Jet* j) const {
  vector<const Jet*> constits;
  add_constituents(j, constits);
  return constits;
}

void JetCollection::add_constituents(const Jet* j, vector<const Jet*>& constits) const {
  vector<const Jet*> parents = get_parents(j);
  if (parents.size() == 0) constits.push_back(j);
  else for (size_t i = 0; i < parents.size(); ++i)
    add_constituents(parents[i], constits);
}

// Retrieve parents of Jet j; if none return an empty vector
vector<const Jet*> JetCollection::get_parents(const Jet* j) const {
  vector<const Jet*> parent_jets;
  const HistoryElement* he = j->history();
  if (he) {
    vector<HistoryElement*> parent_nodes = he->parents();
    for (size_t i = 0; i < parent_nodes.size(); ++i)
      parent_jets.push_back(parent_nodes[i]->getJet());
  }
  return parent_jets;
}
vector<Jet*> JetCollection::get_parents(const Jet* j) {
  vector<Jet*> parent_jets;
  const HistoryElement* he = j->history();
  if (he) {
    vector<HistoryElement*> parent_nodes = he->parents();
    for (size_t i = 0; i < parent_nodes.size(); ++i)
      parent_jets.push_back(parent_nodes[i]->getJet());
  }
  return parent_jets;
}


// Retrieve child of Jet j; if none return 0
const Jet* JetCollection::get_child(const Jet* j) const {
  const HistoryElement* he = j->history();
  if (he) {
    HistoryElement* child = he->child();
    if (child)
      return child->getJet();
  }
  return 0;
}

Jet* JetCollection::get_child(Jet* j) {
  const HistoryElement* he = j->history();
  if (he) {
    HistoryElement* child = he->child();
    if (child)
      return child->getJet();
  }
  return 0;
}

// Get jet that contains this subjet
//  Returns j if this jet has no children (ie, it is a top-level jet)
const Jet* JetCollection::get_child_jet(const Jet* j) const {
  const Jet *child=j,* tmp;
  while ((tmp = get_child(child)) != 0) child = tmp;
  return child;
}

Jet* JetCollection::get_child_jet(Jet* j) {
  Jet *child=j, *tmp;
  while ((tmp = get_child(child)) != 0) child = tmp;
  return child;
}

double JetCollection::get_dij(const Jet* j) const {return j->history()->dij();}


// Remove the subjet j (can be a subjet of any Jet) and adjust history
// The Jet* is deleted if it is owned by its history element
void JetCollection::remove_subjet(Jet* child, Jet* parent) {
  if (!child) {
    // top-level jet: remove from list and quit
    vector<Jet*> to_remove(1, parent);
    filter_out(to_remove);
    return;
  }
  HistoryElement* child_he = child->history();
  HistoryElement* he = parent->history();
  if (!child_he || !he) {
    cout << "JetCollection::remove_subjet: jets must have history!" << endl;
    return;
  }
  // unlink this node from child
  child_he->removeParent(he);
  delete he;
  // if we've left child with no parents, remove it
  if (child_he->nParents() == 0) {
    HistoryElement* grandchild = child_he->child();
    if (!grandchild) remove_subjet(0, child_he->getJet());
    else remove_subjet(grandchild->getJet(), child_he->getJet());
  }
  // clean things up, e.g. jets with only one parent
  cleanup_history(child_he);
}
// same, but removes more than one (TODO: scrap this duplicate version)
void JetCollection::remove_subjets(Jet* child, vector<Jet*>& subjets) {
  if (!child) {
    // top-level jets: remove from list and quit
    filter_out(subjets);
    return;
  }
  HistoryElement* child_he = child->history();
  for (size_t i = 0; i < subjets.size(); ++i) {
    HistoryElement* he = subjets[i]->history();
    if (!child_he || !he) {
      cout << "JetCollection::remove_subjet: jets must have history!" << endl;
      return;
    }
    // unlink this node from child
    child_he->removeParent(he);
    delete he;
  }
  
  // if we've left child with no parents, remove it
  if (child_he->nParents() == 0) {
    HistoryElement* grandchild = child_he->child();
    if (!grandchild) remove_subjet(0, child_he->getJet());
    else remove_subjet(grandchild->getJet(), child_he->getJet());
  }
  // clean things up, e.g. jets with only one parent
  cleanup_history(child_he);
}


// Add parent as a subjet of child
// If parent has no history, the Jet* is adopted
void JetCollection::add_subjet(Jet* child, Jet* parent) {
  if (get_child(parent)) {
    cout << "JetCollection::add_subjet: can't add a subjet that already has a child!" << endl;
    return;
  }
  HistoryElement* child_node = child->history();
  HistoryElement* parent_node = parent->history();
  child_node->addParent(parent_node);
  parent_node->setChild(child_node);
}

// This creates an intermediate merging in an N->1 merging
// The result is an n->1 merging followed by an (N-n)->1 merging, where n is
//  the size of parents_to_merge. 
void JetCollection::merge_subjets(std::vector<Jet*>& parents_to_merge) {
  if (parents_to_merge.size() < 2) return;
  Jet* child = get_child(parents_to_merge[0]);
  if (!child) {
    cout << "JetCollection::merge_subjets: can't merge subjets that don't have children!" << endl;
    return;
  }
  Jet* combined = new Jet(parents_to_merge);
  for (size_t i = 0; i < parents_to_merge.size(); ++i)
    child->history()->removeParent(parents_to_merge[i]->history());
  add_subjet(child, combined);
}


// Unclusters jet or subjet j.
//  If j is a subjet, j's parents are made parents of j's child.
void JetCollection::uncluster_jet(Jet* j) {
  HistoryElement* he_jet = j->history();
  HistoryElement* child = he_jet->child();
  vector<HistoryElement*> parents = he_jet->parents();
  if (parents.size() < 2) return;

  if (!child) {
    for (size_t i = 0; i < parents.size(); ++i) {
      he_jet->removeParent(parents[i]);
      // j was a top-level jet; make its parents jets now
      push_back(parents[i]->getJet());
      parents[i]->setChild(NULL);
    }
    // top-level jet; remove now
    vector<Jet*> to_remove(1, j);
    filter_out(to_remove);
  } else {
    for (size_t i = 0; i < parents.size(); ++i) {
      he_jet->removeParent(parents[i]);
      child->addParent(parents[i]);
      parents[i]->setChild(child);
    }
    child->removeParent(he_jet);
    if (!he_jet->own_jet()) delete j;
    delete he_jet;
  }
}


void JetCollection::cleanup_history(HistoryElement* he) {
  if (!he) return;
  vector<HistoryElement*> parents = he->parents();
  
  // Check for only 1 parent -- merge this node with parent
  if (parents.size() == 1) {
    HistoryElement* parent = parents[0];
    // descend to find grandparents:
    vector<HistoryElement*> grandparents = parent->parents();
    while (grandparents.size() == 1 && grandparents[0]->nParents() != 0) {
      grandparents = grandparents[0]->parents();
    }
    if (grandparents.size() != 0) { // NB: Chain of single parents can leave no grandparents
      // copy node info from last real merging
      he->setHindex(grandparents[0]->child()->hindex());
      he->setDij(grandparents[0]->child()->dij());
    }
    for (size_t i = 0; i < grandparents.size(); ++i) {
      he->addParent(grandparents[i]);
      grandparents[i]->child()->removeParent(grandparents[i]);
      grandparents[i]->setChild(he);
    }
    he->removeParent(parent);
    delete parent;
  }
  
  parents = he->parents();
  for (size_t i = 0; i < parents.size(); ++i)
    cleanup_history(parents[i]);
  // force jet update
  he->getJet();
}


void JetCollection::cleanup_history() {
  Jet::jet_list_t::const_iterator jit, jitE;
  jit = begin();
  jitE = end();
  for (; jit != jitE; ++jit) {
    cleanup_history((*jit)->history());
  }
}


Jet* JetCollection::getConstituent(int i) const {
  Jet::jet_list_t::const_iterator jit, jitE;
  jit = begin();
  jitE = end();
  for (; jit != jitE; ++jit) {
    Jet::constit_vect_t::const_iterator cit, citE;
    cit = (*jit)->first_constituent();
    citE = (*jit)->last_constituent();
    for (; cit != citE; ++cit) {
      if ((*cit)->input_index() == i)
        return *cit;
    }
  }
  cout << "JetCollection: no constituent with index " << i << endl;
  return 0;
}


// returns a pointer to the jet that contains the input with this index
Jet* JetCollection::child_jet(int input_index) const {
  JetCollection::const_iterator it, itE;
  it = begin();
  itE = end();
  for (; it != itE; ++it) {
    Jet::constit_vect_t::const_iterator cit, citE;
    cit = (*it)->first_constituent();
    citE = (*it)->last_constituent();
    for (; cit != citE; ++cit) {
      if ((*cit)->input_index() == input_index)
        return *it;
    }
  }
  return 0;
}


/// Load, into "he", the history corresponding to the jet "pj" in the
/*  ClusterSequence "cs".  Leaf nodes will have an input_index() corresponding
 *  to their index in the input JetCollection.
 */
void JetCollection::load_HistoryElement(HistoryElement* he, const PseudoJet& pj,
          const ClusterSequence& cs) {
  PseudoJet p1, p2;
  const vector<ClusterSequence::history_element>& fjHist = cs.history();
  // leaf node
  if (!cs.has_parents(pj, p1, p2)) {
    Jet *j = 0;
    if (he->jet()) {
      // one-particle jet, so this HE already has a Jet*
      j = he->jet();
    } else {
      j = new Jet(pj);
      delete j->history();
      j->set_history(he);
      he->adoptJet(j);
    }
    if (pj.user_index() != -1) j->set_index(pj.user_index());
    //j->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(j, this)));
  } else {
  // internal node        
    // create parents, links between
    HistoryElement* h1 = new HistoryElement();
    HistoryElement* h2 = new HistoryElement();
    he->addParent(h1);
    he->addParent(h2);
    h1->setChild(he);
    h2->setChild(he);
    
    // recurse
    load_HistoryElement(h1, p1, cs);
    load_HistoryElement(h2, p2, cs);
  }
  // set index, dij (after, since leaf case sets these to defaults).  These will be screwy if inputs had substructure
  int fjHistIndex = pj.cluster_sequence_history_index();
  const ClusterSequence::history_element& fjHE = fjHist[fjHistIndex];
  he->setDij(fjHE.dij);
  he->setHindex(fjHistIndex);

}


}  // namespace SpartyJet

