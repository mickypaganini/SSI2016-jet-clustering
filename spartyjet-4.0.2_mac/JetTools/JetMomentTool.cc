// Copyright 2010, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
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

#include "JetMomentTool.hh"

#include <iostream>
using namespace std;

namespace SpartyJet {

void JetMomentTool::execute(JetCollection& inputJets) {
  JetMomentMap* map = inputJets.get_JetMomentMap();

  JetCollection::iterator it = inputJets.begin();
  JetCollection::iterator itE = inputJets.end();
  for (; it != itE; ++it) {
    m_moment->CalculateMoment(*it, inputJets);
    m_log << DEBUG << "Setting moment " << m_moment->GetName() << endl;
    map->set_jet_moment(*it, m_moment);
  }
}

void EventMomentTool::execute(JetCollection& inputJets) {
  JetMomentMap* map = inputJets.get_JetMomentMap();
  m_moment->CalculateMoment(NULL, inputJets);
  map->set_event_moment(m_moment);
}


}
