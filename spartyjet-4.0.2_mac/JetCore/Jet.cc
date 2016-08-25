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

#include "Jet.hh"
#include "JetHistory.hh"

using namespace fastjet;
using namespace std;

namespace SpartyJet { 

Jet::Jet(const Jet& jet) : PseudoJet(0,0,0,0), m_is_input(false), m_index(0) {
  *this = jet; // copies PJ and index
  m_history = new HistoryElement(*(jet.history()));
  m_history->setJet(this);
  set_user_info(new SpartyJetUserInfo(this));
}

Jet::Jet(const Jet* j) : PseudoJet(0,0,0,0), m_is_input(false), m_index(0) {
  *this = *j; // copies PJ and index
  m_history = new HistoryElement(*(j->history()));
  m_history->setJet(this);
  set_user_info(new SpartyJetUserInfo(this));
}

// construct a jet with given parents
Jet::Jet(vector<Jet*>& parents) : PseudoJet(0,0,0,0), m_is_input(false), m_index(0) {
  m_history = new HistoryElement();
  m_history->setJet(this);
  
  for (size_t i = 0; i < parents.size(); ++i) {
    *this += *parents[i];
    m_history->addParent((parents[i]->history()));
    parents[i]->history()->setChild(m_history);
  }
  set_user_info(new SpartyJetUserInfo(this));
}

// No history copying!
const Jet& Jet::operator=(const Jet& j) {
  if (this == &j) return *this;
  PseudoJet::operator=(j);
  m_is_input = j.is_input();
  m_index = j.input_index();
  return *this;
}

void Jet::set_defaults() {
  m_is_input = false;
  m_index = 0;
  m_history = new HistoryElement();
  m_history->setJet(this);
  set_user_info(new SpartyJetUserInfo(this));
}


// constituent access
// -- first build m_constituents if necessary
// for Jets with no history, constituent vector is just {this}
void Jet::build_constit_vect() const {
  m_constituents.clear();  
  if (has_constituents()) {
    vector<PseudoJet> constits = constituents();
    for (size_t i = 0; i < constits.size(); ++i) {
      m_constituents.push_back(constits[i].user_info<SpartyJetUserInfo>().jet());
    }
  } else {
    m_constituents.push_back(const_cast<Jet*>(this));
  }
}

int Jet::get_constituent_num() const {
  build_constit_vect();
  return m_constituents.size();
}

Jet::constit_vect_t::iterator Jet::first_constituent() {
  build_constit_vect();
  return m_constituents.begin();
}

Jet::constit_vect_t::iterator Jet::last_constituent() {
  // assume this is done by first_constituent
  //build_constit_vect();
  return m_constituents.end();
}

Jet::constit_vect_t::const_iterator Jet::first_constituent() const {
  build_constit_vect();
  return m_constituents.begin();
}

Jet::constit_vect_t::const_iterator Jet::last_constituent() const {
  //build_constit_vect();
  return m_constituents.end();
}


/// Clear out old history, replace with fresh one
void Jet::clear_history() {
  delete m_history;
  m_history = new HistoryElement();
  m_history->setJet(this);
}

SpartyJetUserInfo::~SpartyJetUserInfo() {
  if (m_ownjet) {
    bool history_owns_jet = m_ptr->history()->own_jet();
    delete m_ptr->history();
    if (!history_owns_jet)
      delete m_ptr;
  }
}

  
}  // namespace SpartyJet
