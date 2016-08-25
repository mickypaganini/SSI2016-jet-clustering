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

#include "JetSelectorTool.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/JetHistory.hh"
#include <iostream>
using namespace std;

namespace SpartyJet {

void JetSelectorTool::execute(JetCollection& inputJets) {
  m_map = inputJets.get_JetMomentMap(); // now any tool can use the map in pass_cut()
  JetCollection::iterator it  = inputJets.begin();
  JetCollection::iterator itE = inputJets.end();  

  Jet::jet_list_t fail_list; 
  for (; it != itE; ++it)
    if (!pass_cut(*it))
      fail_list.push_back(*it);
    else
      // debug output
      if (m_debug) {
        if ((*it)->history()) (*it)->history()->dumpHistory();
      }

  inputJets.filter_out(fail_list);
}

void JetPtSelectorTool::execute(JetCollection& inputJets) {
  // first, do normal pT cut
  JetSelectorTool::execute(inputJets);

  // if m_N != -1, cut back to m_N jets
  if (m_N == -1) return;

  // if more than N jets are left, filter out softest
  while ((int)inputJets.size() > m_N) {
    double min_pt = inputJets[0]->pt();
    Jet* softest = inputJets[0];
    JetCollection::iterator it, itE;
    it = ++(inputJets.begin());
    itE = inputJets.end();
    for (; it != itE; ++it) {
      if ((*it)->pt() < min_pt) {
        min_pt = (*it)->pt();
        softest = *it;
      }
    }
    vector<Jet*> fail_list(1, softest);
    inputJets.filter_out(fail_list);
  }
}

bool JetInputPdgIdSelectorTool::pass_cut(Jet* jet) {
  bool passes = true;
  int id = m_map->get_jet_moment<int>("pdgId", jet);
  for (size_t p = 0; p < m_cutsI.size(); p++)
    passes &= ( m_cutsI[p] != id );
  return passes;
}

}  // namespace SpartyJet
