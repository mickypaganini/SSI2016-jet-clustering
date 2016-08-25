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


/*
 * Wraps Peter Loch's RadialSmearing calorimeter simulation, defined in
 * DetectorModel.{h,cxx}.
 */

#ifndef _RADIAL_SMEARING_TOOL_HH_
#define _RADIAL_SMEARING_TOOL_HH_

#include "JetCore/JetTool.hh"
#include "JetCore/JetCollection.hh"
#include "DetectorModel.hh"

#include <iostream>

namespace SpartyJet {

class RadialSmearingTool : public JetTool {
public:
  RadialSmearingTool(std::string name="RadialSmearing")
    : JetTool(name) {
  }
  ~RadialSmearingTool() {}
  
  void init(JetMomentMap* mmap=0) {
    if (mmap) mmap->unschedule_jet_moments(); // since we're totally changing all the inputs
  }
  
  void execute(JetCollection& inputJets) {
    // copy input particles into a PJ vector
    std::vector<fastjet::PseudoJet> inputs;
    JetMomentMap* map = inputJets.get_JetMomentMap();
        
    for (size_t i = 0; i < inputJets.size(); ++i) {
      inputs.push_back(*inputJets[i]);
      int id = map->get_jet_moment<int>("pdgId", inputJets[i]);
      inputs[i].set_user_index(id);
    }
    inputJets.clear_and_delete();
    
    // create a RadialSmearing object to do smearing
    const std::vector<fastjet::PseudoJet>& smeared = m_smear.smear(inputs);
    for (size_t i = 0; i < smeared.size(); ++i)
      inputJets.push_back(new Jet(smeared[i]));
    
  }
  
protected:
  DetectorModel::RadialSmearing m_smear;
};


} // namespace SpartyJet

#endif
