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

#include "HardProcessMatchTool.hh"
#include "JetCore/JetCollection.hh"
#include "fastjet/PseudoJet.hh"
using namespace fastjet;

#include <vector>
using namespace std;

namespace SpartyJet { 

void HardProcessMatchTool::init(JetMomentMap* mmap) {
  if (mmap != NULL) {
    mmap->schedule_jet_moment<Double32_t>("PartonMatchDistance");
  }
}


void HardProcessMatchTool::execute(JetCollection& jc) {

  // retrieve the map of the collection:
  JetMomentMap* map = jc.get_JetMomentMap();
  if (!map->has_jet_moment("PartonMatchDistance")) return;

  vector<PseudoJet> hardProcess = map->get_event_moment<vector<PseudoJet> >("HardProcess");
  //for (unsigned i = 0; i < hardProcess.size(); ++i)
  //  m_log << ERROR << " Hard parton with id, E: " << hardProcess[i].user_index() << " " << hardProcess[i].e() << endl;

  // Loop on all jets
  JetCollection::iterator jit  = jc.begin(); 
  JetCollection::iterator jitE = jc.end(); 
  for (; jit != jitE; ++jit) {    
    Jet* j = (*jit);
    // find closest hardProcess parton, store distance, and remove parton from set
    double min_dr = 1000000.0;
    int min_i = -1;
    for (unsigned i = 0; i < hardProcess.size(); ++i) {
      if (j->squared_distance(hardProcess[i]) < min_dr) {
        min_dr = j->squared_distance(hardProcess[i]);
        min_i = i;
      }
    }
    map->set_jet_moment<Double32_t>("PartonMatchDistance", j, min_dr);
    
    // TODO: erasing from a vector is not very efficient...
    if (min_i != -1) {// found a match
      //m_log << DEBUG << "Found a match for jet, parton:" << endl << "  ";
      //j->print();
      //const PseudoJet& p = hardProcess[min_i];
      //cout << "  " << p.px() << " " << p.py() << " " << p.pz() << " " << p.E() << " " << p.user_index() << endl;
      hardProcess.erase(hardProcess.begin()+min_i);
    }
  } // Loop on jets
  
}  // namespace SpartyJet
}
