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

#include "JetAreaCorrectionTool.hh"
#include "JetCore/JetCollection.hh"

using namespace std;

namespace SpartyJet { 

void JetAreaCorrectionTool::init(JetMomentMap* mmap)  {
  if (mmap != NULL) {
    if (!mmap->has_event_moment("ptDensity"))
      m_log << ERROR << "Event Moment array: ptDensity missing" << endl;
    else
      mmap->schedule_jet_moment<Double32_t>("JetAreaCorr");
  }
}

void JetAreaCorrectionTool::execute(JetCollection& theJets) {
  // retrieve the map of the collection :
  JetMomentMap * themap = theJets.get_JetMomentMap();

  if (!themap->has_jet_moment("area")) {
    m_log << INFO << "No area moment for this JetCollection.  Skipping JetAreaCorrection." << endl;
    return;
  }

  // Get ptDensity
  JetMomentMap::value_store_t rhoVec = themap->get_event_moment<JetMomentMap::value_store_t>("ptDensity");
  // Get Eta Bins
  JetMomentMap::value_store_t rhoBinVec = themap->get_event_moment<JetMomentMap::value_store_t>("ptDensityBins");

  // Loop on all jets
  JetCollection::iterator jit = theJets.begin(); 
  JetCollection::iterator jitE = theJets.end(); 
  for (; jit != jitE; ++jit) {
    double corr = 0.0;
    unsigned bin = GetRhoBin((*jit)->eta(), rhoBinVec);
    if (bin < rhoVec.size()) {
      double area = themap->get_jet_moment<Double32_t>("area", *jit);
      corr = rhoVec[bin] * area;
    }
    // Set moments into map
    themap->set_jet_moment<Double32_t>("JetAreaCorr", *jit, corr);
  }
}

unsigned int JetAreaCorrectionTool::GetRhoBin(double eta, const JetMomentMap::value_store_t& rhoBinVec) {
  unsigned int bin = 0;
  for (; bin < rhoBinVec.size()-1; ++bin) {
    if (eta > rhoBinVec[bin] && eta < rhoBinVec[bin+1]) break;
  }
  return bin;
}

}  // namespace SpartyJet
					                   	                
