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

#include "HullMomentTool.hh"
#include "cyl_geom.hh"
#include "JetCore/JetCollection.hh"

namespace SpartyJet { 

void HullMomentTool::init(JetMomentMap* mmap) {
  if (mmap != NULL) {
    mmap->schedule_jet_moment<Double32_t>("HullL");
    mmap->schedule_jet_moment<Double32_t>("HullA");
  }
}


void HullMomentTool::execute(JetCollection& theJets) {

  // retrieve the map of the collection :
  JetMomentMap* themap = theJets.get_JetMomentMap();
  if (!themap->has_jet_moment("HullA")) return;

  // Loop on all jets
  JetCollection::iterator jit  = theJets.begin(); 
  JetCollection::iterator jitE = theJets.end(); 
  for (; jit != jitE; ++jit) {    
    Jet* j = (*jit);
    point_set_t constits, constits_tmp;
    point_vect_t hull;
    // Loop on all constits
    Jet::constit_vect_t::iterator cit  = j->first_constituent();
    Jet::constit_vect_t::iterator citE = j->last_constituent();
    for (; cit != citE; ++cit){
      const Jet* constit = (*cit);
      constits_tmp.insert(point_t(constit->rapidity(), constit->phi()));
    }
    
    recenter_set(constits_tmp, constits);
    findConvexHull(constits, hull);
    // Set moments into map
    themap->set_jet_moment<Double32_t>("HullL", j, polygon_length(hull));
    double a = fabs(polygon_area(hull));    
    themap->set_jet_moment<Double32_t>("HullA", j, a);
    // m_log << " lenght=" <<  << "   phi2="<< phi2 << std::endl;
  } // Loop on jets
  
}  // namespace SpartyJet
}
