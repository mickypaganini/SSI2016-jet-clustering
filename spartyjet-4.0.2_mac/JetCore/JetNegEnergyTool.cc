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

#include "JetNegEnergyTool.hh"
#include "JetCore/JetCollection.hh"

using namespace std;

namespace SpartyJet { 

void JetNegEnergyTool::execute(JetCollection& inputJets){
  if (m_acquiring) acquisition(inputJets);
  else             correction(inputJets);
}


void JetNegEnergyTool::acquisition(JetCollection& inputJets){

  JetCollection::iterator it  = inputJets.begin();
  JetCollection::iterator itE = inputJets.end();
  for (; it != itE; ++it) {
    Jet::constit_vect_t::iterator constit_it = (*it)->first_constituent();
    if (constit_it == (*it)->last_constituent()) {
      // Ill formed jet !!! Before jet finding one expects 1 constituent per jet!
      m_log << "WARNING !!! jet has no constituent !" << endl;
      continue;
    }
    Jet* constit = *constit_it;
    if (constit->e() < 0) {
      m_log << " Found " << constit->e() << endl;
      constit->setE(-constit->e());
      m_neg_constits.insert(constit);
    }
  }
  m_acquiring = false;
}


void JetNegEnergyTool::correction(JetCollection& inputJets){

  JetCollection::iterator it  = inputJets.begin();
  JetCollection::iterator itE = inputJets.end();

  jet_list_t::iterator end_neg = m_neg_constits.end();

  for (; it != itE; ++it) {
    Jet::constit_vect_t::iterator constit_it  = (*it)->first_constituent();
    Jet::constit_vect_t::iterator constit_itE = (*it)->last_constituent();
    for (; constit_it != constit_itE; ++constit_it) {
      jet_list_t::iterator pos = m_neg_constits.find(*constit_it);
      if (pos != end_neg) {
        // We have to correct the jet
        Jet *jet = *it;
        Jet *constit = *constit_it;
        constit->setE(-constit->e());
        m_log << " correcting "<< constit->e() << endl;
        jet->setE(jet->e() - 2* constit->e());
        m_neg_constits.erase(pos);
      }
    }
  }  
  
  m_acquiring = true;
}

}  // namespace SpartyJet
