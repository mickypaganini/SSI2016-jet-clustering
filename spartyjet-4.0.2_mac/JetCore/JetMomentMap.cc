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

#include "JetMomentMap.hh"
#include "Jet.hh"

#include "fastjet/PseudoJet.hh"
using namespace fastjet;

#include <typeinfo>
#include <vector>
using namespace std;

namespace SpartyJet {

/// The input Moment should have its name set; a pointer to the corresponding moment
///  in jet's moment_store_t is returned.
const Moment* JetMomentMap::get_jet_moment(const Jet* jet, const Moment* m) const {
  jet_moment_map_t::const_iterator jit = m_jet_moment_map.find(jet);
  if(jit == m_jet_moment_map.end()) {
    m_log << DEBUG << "get_jet_moment: No such jet for moment " << m->GetName() << "!" << endl;
    return NULL;
  }
  const moment_store_t &moments = (*jit).second;
  return get_moment(moments, m);
}


/// User has created a Moment object, and passes it to us
/// We make a copy to store
void JetMomentMap::set_moment(moment_store_t& store, const Moment* m) {
  // See if we already have a moment with this name
  moment_store_t::iterator it = store.begin();
  moment_store_t::iterator itE = store.end();
  for (; it != itE; it++)
    if ((*it)->GetName() == m->GetName()) break;

  if (it == itE) {  // not found
    store.push_back(m->MakeCopy());
  } else { // found
    // check that we're not changing the type of this Moment
    if (typeid(*m) != typeid(**it)) {
      m_log << DEBUG << "Changing the type of Moment " << m->GetName() << "!  May not store correctly." << endl;
      m_log << DEBUG << "  (was " << typeid(*m).name() << ", now is " << typeid(**it).name() << ")" << endl;
    }
    delete (*it);  // delete old Moment
    (*it) = m->MakeCopy();
    m_log << DEBUG << "Set moment " << m->GetName() << endl;
  }
}

/// The input Moment should have its name set; a pointer to the corresponding moment
///  in jet's moment_store_t is returned.
const Moment* JetMomentMap::get_moment(const moment_store_t& store, const Moment* m) const {
  // Find the moment with this name
  moment_store_t::const_iterator it = store.begin();
  moment_store_t::const_iterator itE = store.end();
  for (; it != itE; it++)
    if ((*it)->GetName() == m->GetName()) break;

  if (it == itE) { // not found
    // note, this can happen in analyses where a Transformer fails
    // we keep the jets to 
    m_log << DEBUG << "JetMomentMap: No moment " << m->GetName() << endl;
    return NULL;
  } else { // found
    return *it;
  }
}

/// Same, but just give the name
const Moment* JetMomentMap::get_moment(const moment_store_t& store, string name) const {
  moment_store_t::const_iterator mit = store.begin();
  moment_store_t::const_iterator mitE = store.end();
  for (; mit != mitE; ++mit) if ((*mit)->GetName() == name) break;
  if (mit == mitE) return NULL; // Moment not found
  return *mit;
}

/// Find the jet moment with this name
const Moment* JetMomentMap::get_jet_moment(string name) const {
  jet_moment_map_t::const_iterator it = m_jet_moment_map.find(NULL);
  if (it == m_jet_moment_map.end()) return NULL;
  return get_moment((*it).second, name);
}


/// Note that some trickery is necessary for this to be const
///  m_jet_moment_map[jet] is not const access! (jet might not exist in map)
const JetMomentMap::moment_store_t& JetMomentMap::get_jet_moments(const Jet* jet) const {
  static const moment_store_t EMPTY_STORE;
  jet_moment_map_t::const_iterator it = m_jet_moment_map.find(jet);
  if (it == m_jet_moment_map.end()) return EMPTY_STORE;
  return (*it).second;
}


/// Deletes all moments and clears out the map.  Note that JMM owns its moments.
void JetMomentMap::clear() {

  jet_moment_map_t::iterator jit = m_jet_moment_map.begin();
  jet_moment_map_t::iterator jitE = m_jet_moment_map.end();
  for (; jit != jitE; ++jit) {
    clear_list((*jit).second);
  }
  m_jet_moment_map.clear();

  clear_list(m_event_moments);
}

// Clears all moments stored for jets; map[NULL] is saved, which represents
//   scheduled moments.  Event moments are also kept, since these are just
//   overwritten for each event (whereas jet moments are stored for each unique
//   Jet*).
void JetMomentMap::clear_event() {
  // we only want to keep map[NULL], which stores scheduled moments
  moment_store_t scheduled_moments = m_jet_moment_map[NULL];

  jet_moment_map_t::iterator jit = m_jet_moment_map.begin();
  jet_moment_map_t::iterator jitE = m_jet_moment_map.end();
  for (; jit != jitE; ++jit) {
    if ((*jit).first != NULL) // don't delete Moment*'s in map[NULL]
      clear_list((*jit).second);
  }
  m_jet_moment_map.clear();
  m_jet_moment_map[NULL] = scheduled_moments;
}

// this function copies the layout of the JetMoments in the map
// and explicitly the EventMoments in the map.  this is commonly
// used just before jet finding which breaks the jet moments, but
// leaves event moments entact
void JetMomentMap::copy_structure(const JetMomentMap& map) {
  clear();

  // Copy jet moments (only for NULL, so we have a set of prototypes)
  const moment_store_t &jet_moments = map.get_jet_moments();
  moment_store_t::const_iterator mit = jet_moments.begin();
  moment_store_t::const_iterator mitE = jet_moments.end();
  for (; mit != mitE; ++mit) m_jet_moment_map[NULL].push_back((*mit)->MakeCopy());

  // Copy event moments
  const moment_store_t &event_moments = map.get_event_moments();
  mit = event_moments.begin();
  mitE = event_moments.end();
  for (; mit != mitE; ++mit) m_event_moments.push_back((*mit)->MakeCopy());
  
  // HACK: copy HardProcess if it's there
  if (map.has_event_moment("HardProcess")) {
    Moment* tmp = new EventMoment<vector<PseudoJet> >("HardProcess");
    m_event_moments.push_front(map.get_event_moment(tmp)->MakeCopy());
    delete tmp;
  }
}

void JetMomentMap::swap(JetMomentMap& map){
  m_jet_moment_map.swap(map.m_jet_moment_map);
  m_event_moments.swap(map.m_event_moments);
}


bool JetMomentMap::has_jet_moment(std::string name, Jet* j) const {
  jet_moment_map_t::const_iterator it = m_jet_moment_map.find(j);
  if (it == m_jet_moment_map.end()) return false;
  const moment_store_t &moments = (*it).second;
  moment_store_t::const_iterator mit = moments.begin();
  moment_store_t::const_iterator mitE = moments.end();
  for (int i = 0; mit != mitE; ++mit, ++i)
    if ((*mit)->GetName() == name) return true;
  return false;
}

bool JetMomentMap::has_event_moment(std::string name) const {
  moment_store_t::const_iterator mit = m_event_moments.begin();
  moment_store_t::const_iterator mitE = m_event_moments.end();
  for (int i = 0; mit != mitE; ++mit, ++i)
    if ((*mit)->GetName() == name) return true;
  return false;
}

}  // namespace SpartyJet
