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

#include "EtaPhiMomentTool.hh"
#include "JetCore/JetDistances.hh"
#include "JetCore/JetCollection.hh"

namespace SpartyJet { 

void EtaPhiMomentTool::init(JetMomentMap* mmap) {
  if (mmap != NULL) {
    mmap->schedule_jet_moment("M2eta");
    mmap->schedule_jet_moment("M2phi");
    mmap->schedule_jet_moment("MomArea");
  }
}

void EtaPhiMomentTool::execute(JetCollection& theJets) {
  // retrieve the map of the collection :
  JetMomentMap * themap = theJets.get_JetMomentMap();
  if(themap->num_jet_moment() ==0) return;

  // Loop on all jets
  JetCollection::iterator jit = theJets.begin(); 
  JetCollection::iterator jitE = theJets.end(); 
  for(; jit!=jitE;++jit){
    
    double phi2=0, eta2=0, e=0;
    Jet * j = (*jit);
    // Loop on all constits
    Jet::constit_vect_t::iterator cit  = j->first_constituent();
    Jet::constit_vect_t::iterator citE = j->last_constituent();
    for(; cit != citE; ++cit){
      const Jet* constit = (*cit);
      e += constit->e();
      double deta = JetDistances::deltaEta(j, constit);
      eta2 += deta*deta*constit->e();
      double dphi = JetDistances::deltaPhi(j, constit);
      phi2 += dphi*dphi*constit->e();
    }
    phi2 = sqrt(phi2/e);
    eta2 = sqrt(eta2/e);
    // for homogenous elipse : 2ndmom = a/sqrt(3)
    // so area = a*b*pi = 3*2ndmom*2ndmom*pi
    double area= 3*phi2*eta2*M_PI;
    // Set moments into map
    themap->set_jet_moment("M2phi", j, phi2);
    themap->set_jet_moment("M2eta", j, eta2);
    themap->set_jet_moment("MomArea", j, area);
  } // Loop on jets
  
}





void MomentArrayTestTool::init(JetMomentMap* mmap) {
  if (mmap != NULL) {
    mmap->schedule_jet_moment<JetMomentMap::value_store_t>("momArr");    
    mmap->schedule_event_moment<JetMomentMap::value_store_t>("globArr");
  }
}

void MomentArrayTestTool::execute(JetCollection& theJets) {
  // retrieve the map of the collection :
  JetMomentMap* themap = theJets.get_JetMomentMap();

  int i = 0;
  JetCollection::iterator jit = theJets.begin(); 
  JetCollection::iterator jitE = theJets.end(); 
  for (; jit != jitE; ++jit) {
    Jet * j = (*jit);    
    JetMomentMap::value_store_t arr;
    arr.push_back(i+10.0);
    arr.push_back(i+100.0);
    arr.push_back(i+300.0);
    i++;
    themap->set_jet_moment("momArr", j, arr);
  }

  // Now fill global array
  JetMomentMap::value_store_t arr;
  arr.push_back(42);
  arr.push_back(43.42);
  arr.push_back(44);
  themap->set_event_moment("globArr", arr);
}

}  // namespace SpartyJet
