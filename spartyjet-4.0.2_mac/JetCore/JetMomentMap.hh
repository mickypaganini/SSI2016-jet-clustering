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

#ifndef _JETMOMENT_MAP_HH_
#define _JETMOMENT_MAP_HH_

#include "JetMoment.hh"
#include "CommonUtils.hh"
#include "CustomMessage.hh"

#include <map>
#include <vector>
#include <deque>
#include <string>

/////////////////////////////////////////////////////////////////////////////
/// \class JetMomentMap
///
/// \brief associate additional data to jets
///
/// A JetMomentMap is meant to be associated to a JetAnalysis, and is used to
/// relate any additional quantities ("moments") to the jets produced by the JetAnalysis.
/// It also allows to keep additional quantities associated to the algorithm itself.
///
/// To use, a tool should do two things to write, or one to read:
///
/// Write:
/// 1) Inside init(), call map->schedule_jet_moment<int>("momentName").
/// 2) Inside execute(), call map->set_jet_moment("momentName", Jet*, val);
/// Read:
/// 3) Call val = map->get_jet_moment<int>("momentName", Jet*);
///
/// "int" is just an example; you can store a moment of any type, including
///  classes like vector<float> or your own classes.
/// Event moments work similarly, but without the Jet* argument.
/// Note that the template argument is not necessary for set_jet_moment, since
///  the type of "val" determines the template type.  If no argument is given
///  to schedule or get, Double32_t is assumed.  This is a ROOT type that is
///  treated as double everywhere except writing output, when it is float.
///
/////////////////////////////////////////////////////////////////////////////////

namespace SpartyJet {

class Jet;

class JetMomentMap {
public:

  // deque so we can push_front()
  typedef std::deque<const Moment*> moment_store_t;  // we never mess with the Moments, so store as const ptrs
  typedef std::map<const Jet*, moment_store_t> jet_moment_map_t; // jet_map[NULL] should always hold the right set of Moment*'s

  typedef std::vector<Double32_t> value_store_t; // for backward compatability
  typedef JetMoment<Double32_t> float_moment; // these four are shortcuts used in the backward-compatible code
  typedef JetMoment<value_store_t> vec_moment;
  typedef EventMoment<Double32_t> float_evt_moment;
  typedef EventMoment<value_store_t> vec_evt_moment;

  JetMomentMap() {m_log.set_name("JetMomentMap");}
  JetMomentMap(const JetMomentMap& m) {copy_structure(m); m_log.set_name("JetMomentMap");}
  JetMomentMap& operator=(const JetMomentMap &m) {if(this != &m) copy_structure(m); return *this;}
  ~JetMomentMap() {clear();}

  // Simpler interface functions, using templates instead of Moment objects
  //  With no template parameter, use float (below)
  template<class T>
  void schedule_jet_moment(std::string name) {if (!has_jet_moment(name)) m_jet_moment_map[NULL].push_back(new JetMoment<T>(name));}
  template<class T>
  void set_jet_moment(std::string name, const Jet* jet, T value);
  std::string moment_name(int i) const;
  template<class T>
  T get_jet_moment(std::string name, const Jet* jet) const;


  // Simpler interface functions, using templates instead of Moment objects
  //  With no template parameter, use float (below)
  template<class T>
  void schedule_event_moment(std::string name) {if (!has_event_moment(name)) m_event_moments.push_back(new EventMoment<T>(name));}
  template<class T>
  void set_event_moment(std::string name, T value);
  template<class T>
  T get_event_moment(std::string name) const;


  // Misc information
  void unschedule_jet_moments() {clear_list(m_jet_moment_map[NULL]);}
  int num_jet_moment() const {return size(m_jet_moment_map);}
  int num_jets() const {return m_jet_moment_map.size();}
  int num_event_moment() const {return m_event_moments.size();}
  bool has_jet_moment(std::string name, Jet *j = NULL) const;
  bool has_event_moment(std::string name) const;
   
  // Moment-based access for internal implementation
  // schedule/set/get jet moments
  // NB: accessing map[NULL] creates an empty vector<Moment*> there if it does not exist yet!
  void schedule_jet_moment(const Moment *m) {if (!has_jet_moment(m->GetName())) m_jet_moment_map[NULL].push_back(m->MakeCopy());}
  void schedule_jet_moment_front(const Moment *m) {if (!has_jet_moment(m->GetName())) m_jet_moment_map[NULL].push_front(m->MakeCopy());}
  void set_jet_moment(const Jet* jet, const Moment *m) {set_moment(m_jet_moment_map[jet], m);}
  // add/get global values
  void schedule_event_moment(const Moment *m) {if (!has_event_moment(m->GetName())) m_event_moments.push_back(m->MakeCopy());}
  void schedule_event_moment_front(const Moment *m) {m_event_moments.push_front(m->MakeCopy());}
  void set_event_moment(const Moment *m) {set_moment(m_event_moments, m);}
  // Direct access for output routines    
  const moment_store_t& get_jet_moments(const Jet* jet = NULL) const;
  moment_store_t get_event_moments() const; // HACK: makes a copy that doesn't include HardPartons, which we don't know how to write
  //const moment_store_t& get_event_moments() const {return m_event_moments;}
  const Moment* get_jet_moment(const Jet* jet, const Moment *m) const;
  const Moment* get_event_moment(const Moment* m) const {return get_moment(m_event_moments, m);}
  

  // Specializations to float
  void schedule_jet_moment(std::string name) {if (!has_jet_moment(name)) schedule_jet_moment<Double32_t>(name);}
  float get_jet_moment(std::string name, const Jet* jet) const {return get_jet_moment<Double32_t>(name, jet);}
  void schedule_event_moment(std::string name) {if (!has_event_moment(name)) schedule_event_moment<Double32_t>(name);}


  // clear out everything, including scheduled moments
  void clear();
  // clear out all calculated JetMoments for this event
  void clear_event();
  // remove all moments for a specific jet
  void remove_jet(const Jet* j) {clear_list(m_jet_moment_map[j]); m_jet_moment_map.erase(j);}
  void swap(JetMomentMap& map);
  void copy_structure(const JetMomentMap& map);

protected:

  jet_moment_map_t m_jet_moment_map;
  moment_store_t m_event_moments;

  void set_moment(moment_store_t& store, const Moment* m);
  const Moment* get_moment(const moment_store_t& store, const Moment* m) const;
  const Moment* get_moment(const moment_store_t& store, std::string name) const;
  const Moment* get_jet_moment(std::string name) const;

  static int size(const jet_moment_map_t& m);

  mutable Message m_log;
};

inline JetMomentMap::moment_store_t JetMomentMap::get_event_moments() const {
  moment_store_t moments;
  moment_store_t::const_iterator it, itE = m_event_moments.end();
  for (it = m_event_moments.begin(); it != itE; ++it) {
    if ((*it)->GetName() != "HardProcess") // HACK: Don't include HardProcess, which is vector<PseudoJet>, since we don't know how to write this!
      moments.push_back(*it);
  }
  return moments;
}

/// Returns the number of moments scheduled, which should be the moments for Jet* NULL
///  NB: this is a *const* way to find m[NULL].size()  (m[NULL] may not exist).
inline int JetMomentMap::size(const jet_moment_map_t& m) {
  jet_moment_map_t::const_iterator it = m.find(NULL);
  if (it == m.end()) return 0;
  return (*it).second.size();
}

// template functions

template<class T>
void JetMomentMap::set_jet_moment(std::string name, const Jet* jet, T value) {
  JetMoment<T> m(name);
  m.SetValue(value);
  set_jet_moment(jet, &m);
}

template<class T>
T JetMomentMap::get_jet_moment(std::string name, const Jet* jet) const {
  JetMoment<T> named_blank(name);
  const Moment* m = get_jet_moment(jet, &named_blank);
  const JetMoment<T>* f = dynamic_cast<const JetMoment<T>*>(m);
  return f ? f->GetValue() : T();
}

template<class T>
void JetMomentMap::set_event_moment(std::string name, T value) {
  EventMoment<T> m(name);
  m.SetValue(value);
  set_event_moment(&m);
}


template<class T>
T JetMomentMap::get_event_moment(std::string name) const {
  EventMoment<T> named_blank(name);
  const Moment* m = get_event_moment(&named_blank);
  const EventMoment<T>* f = dynamic_cast<const EventMoment<T>*>(m);
  return f ? f->GetValue() : T();
}


}  // namespace SpartyJet
#endif
