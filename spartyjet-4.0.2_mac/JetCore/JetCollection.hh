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

#ifndef _JETCOLLECTION_HH_
#define _JETCOLLECTION_HH_

#include "Jet.hh"
#include "JetHistory.hh"
#include "JetMomentMap.hh"
#include "CommonUtils.hh"

#include <vector>

// ROOT nonsense
#ifdef G__DICTIONARY
typedef SpartyJet::Jet Jet;
#endif

namespace fastjet {
  class ClusterSequence;
}

//////////////////////////////////////////////////////////////////
/// A JetCollection is a set of jets, together with a JetMomentMap.
///
/// If jets are found with a FastJetFinder, then they will be ordered by
///   decreasing pT.  Tools should maintain this order! (TODO: check this!)
/// Jet "moments" are associated to jets through a map (in JetMomentMap), which
///   allows fast retrieval/setting of moments for a given jet: see
///   JetMoment.hh and JetMomentMap.hh
/// Jets have an associated history (substructure), stored as a tree of
///   HistoryElements.  A JC holds a set of HistoryElement*'s corresponding to
///   the final jets.  Each Jet/HistoryElement pair points to each other, so
///   storing both is redundant (but easiest for now...).  HistoryElements have
///   parents and children representing links in the "merging tree".  The leaves
///   of the tree, the input particles, should store Jet*'s that point to Jets
///   in the original input set.  See Jet.hh and JetHistory.hh for more.
////////////////////////////////////////////////////////////////// 

namespace SpartyJet {

class HistoryElement;

class JetCollection {
public:

  JetCollection() {}
  JetCollection(const Jet::jet_list_t& jetlist) {deep_copy(jetlist);}
  JetCollection(const JetCollection& jetlist)   {deep_copy(jetlist);}
  JetCollection(const fastjet::ClusterSequence& cs);
  ~JetCollection() {clear_and_delete();}

  /// The = operation copies only the list of jets, not the map
  JetCollection& operator=(const JetCollection& coll);
    
  void deep_copy(const JetCollection&   jcoll);
  void deep_copy(const Jet::jet_list_t& jcoll);


  /// inserts jets and structure from a ClusterSequence
  void insert(const fastjet::ClusterSequence& cs);
  /// insert one jet from a CS
  void insert(const fastjet::PseudoJet& pj, const fastjet::ClusterSequence& cs);
  /// insert one jet, with specific subjets, from a CS
  void insert(const fastjet::PseudoJet& pj, const std::vector<fastjet::PseudoJet>& subjets,
            const fastjet::ClusterSequence& cs);  
  /// inserts a specific jet, with specific subjets, but no substructure
  void insert(const fastjet::PseudoJet& pj, const std::vector<fastjet::PseudoJet>& subjets);
  /// same funcs, but replace a current jet (keeps Moments)
  void replace(Jet* j, const fastjet::PseudoJet& pj, const fastjet::ClusterSequence& cs);
  void replace(Jet* j, const fastjet::PseudoJet& pj, const std::vector<fastjet::PseudoJet>& subjets,
            const fastjet::ClusterSequence& cs);  
  void replace(Jet* j, const fastjet::PseudoJet& pj, const std::vector<fastjet::PseudoJet>& subjets);


  /// swap content of collections, including history and moment map
  void swap(JetCollection& jcoll);

  
  /// Removes Jet*'s from list, and deletes corresponding history.
  /// Can accept any container of Jet*'s.
  template <class Cont>
  void filter_out(Cont& toremove);
  /// remove one jet
  void remove(Jet* j);

  /// Empty collection (without destroying jets) and history, but not moment map
  ///  Dangerous??!  Careful about history...
  void clear();
  /// Empty collection, destroying jets, and clear history and moment map
  void clear_and_delete();

  JetMomentMap* get_JetMomentMap() {return &m_map;}
  const JetMomentMap* get_JetMomentMap() const {return &m_map;}


  /// Methods below work on final jets as well as subjets:
  std::vector<const Jet*> get_constituents(const Jet* j) const; 
  void add_constituents(const Jet* j, std::vector<const Jet*>& constits) const;
  /// Retrieve parents of Jet j; if none return an empty vector
  std::vector<const Jet*> get_parents(const Jet* j) const;
  std::vector<Jet*> get_parents(const Jet* j);
  /// Retrieve child of Jet j; if none return 0
  const Jet* get_child(const Jet* j) const;
  Jet* get_child(Jet* j);
  /// Get jet that contains this subjet; if not found return 0
  const Jet* get_child_jet(const Jet* j) const;
  Jet* get_child_jet(Jet* j);
  double get_dij(const Jet* j) const;
  /// History modification -- use plural version if you're removing more than one subjet
  void remove_subjet(Jet* child, Jet* parent);
  void remove_subjets(Jet* child, std::vector<Jet*>&  parents);
  void add_subjet(Jet* child, Jet* parent);
  /// This creates an intermediate merging in an N->1 merging
  /// The result is an n->1 merging followed by an (N-n)->1 merging, where n is
  ///  the size of parents_to_merge. 
  void merge_subjets(std::vector<Jet*>& parents_to_merge);
  /// Unclusters jet or subjet j.
  ///  If j is a subjet, j's parents are made parents of j's child.
  void uncluster_jet(Jet* j);


  /// contructs full, ordered history for a jet (all jets if j=0)
  std::vector<HistoryElement*> full_history(Jet* j=0) const;
  /// print history for a jet (all if j=0)
  void history_dump(Jet* j=0) const;

  /// just forwards vector::size() because I can't seem to get CINT to generate a dictionary for the base class
//  size_t size() const {return Jet::jet_list_t::size();}
  size_t size() const {return m_jets.size();}

  /// provide a minimal copy of std::vector<Jet*> interface
  typedef Jet::jet_list_t::iterator iterator;
  typedef Jet::jet_list_t::const_iterator const_iterator;  
  iterator               begin()                    {return m_jets.begin();}
  const_iterator         begin() const              {return m_jets.begin();}
  iterator               end()                      {return m_jets.end();}
  const_iterator         end()   const              {return m_jets.end();}
  Jet*&                  operator[](size_t i)       {return m_jets[i];}
  Jet* const&            operator[](size_t i) const {return m_jets[i];}
  void                   push_back(Jet* const& j)   {m_jets.push_back(j);}
  Jet*&                  back()                     {return m_jets.back();}
  Jet* const&            back() const               {return m_jets.back();}
  Jet::jet_list_t const& jet_list() const           {return m_jets;}
  Jet::jet_list_t&       jet_list()                 {return m_jets;}

protected:

  Jet::jet_list_t m_jets;

  JetMomentMap m_map;

  /// Search through jets and find the input jet with index() i
  Jet* getConstituent(int i) const;
  /// returns a pointer to the jet that contains the input with this index
  Jet* child_jet(int input_index) const;
  
  /// Cleans up substructure under some jet/subjet after substructure has been
  ///  modified.  Nodes with only one parent are merged together (except at the
  ///  leaves).
  void cleanup_history(HistoryElement* he);
  void cleanup_history(); ///< runs for all jets' HE's
  
  /// loads substructure from a ClusterSequence recursively
  void load_HistoryElement(HistoryElement* he, const fastjet::PseudoJet& pj,
          const fastjet::ClusterSequence& cs);
};

#ifndef G__DICTIONARY
#include <algorithm>

template <class Cont>
void JetCollection::filter_out(Cont& toremove) {
  typename Cont::const_iterator it, itE;
  it  = toremove.begin();
  itE = toremove.end();
  for (; it != itE; ++it) {
    Jet* j = *it; 
    m_map.remove_jet(j);
    // remove jet from list; jet is deleted below
    m_jets.erase(std::remove(begin(), end(), j), end());
    delete j->history(); // Jets don't delete their own history
    delete j;
  }
}

#endif

inline void JetCollection::remove(Jet* j) {
  std::vector<Jet*> vec(1, j);
  filter_out(vec);
}


}  // namespace SpartyJet
#endif

