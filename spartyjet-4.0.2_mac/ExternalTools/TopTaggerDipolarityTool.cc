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



#include "TopTaggerDipolarityTool.hh"
#include "Dipolarity.hh"

using namespace std;
using namespace fastjet;

namespace SpartyJet {
namespace FastJet {

void TopTaggerDipolarityTool::execute(Jet* j, JetMomentMap* map) {
  // store all constituents before top tagging
  std::vector<fastjet::PseudoJet> all_constits = j->constituents();
  TransformerTool::execute(j, map);

  Double32_t dipolarity = 0.;
  if ((fastjet::PseudoJet)(*j) != 0.0) {
    fastjet::PseudoJet W = j->structure_of<fastjet::TopTaggerBase>().W();
    fastjet::PseudoJet b = j->structure_of<fastjet::TopTaggerBase>().non_W();
    std::vector<fastjet::PseudoJet> subjets = W.pieces();
    if (subjets.size() == 2) {
      // size of b subjet
      double b_cone = 0.0;
      std::vector<fastjet::PseudoJet> b_constits = b.constituents();
      for (size_t i = 0; i < b_constits.size(); ++i) {
        if (b.delta_R(b_constits[i]) > b_cone)
          b_cone = b.delta_R(b_constits[i]);
      }
      
      // allowable distance to one of the W subjets
      double W_cone = subjets[0].delta_R(subjets[1])/2.0;
      
      // now, get all particles that contribute to dipolarity.
      std::vector<fastjet::PseudoJet> W_constits;
      for (size_t i = 0; i < all_constits.size(); ++i) {
        const fastjet::PseudoJet& p = all_constits[i];
        if (((p.delta_R(subjets[0]) < W_cone) || (p.delta_R(subjets[1]) < W_cone))
            && (p.delta_R(b) > b_cone))
          W_constits.push_back(p);
      }
      dipolarity = Dipolarity(subjets[0], subjets[1], W_constits);
    } else {
      m_log << DEBUG << "Dipolarity assumes two W subjets found; found " << subjets.size() << std::endl;
    }
  }
  map->set_jet_moment<Double32_t>("dipolarity", j, dipolarity);
}

}
} // namespace SpartyJet
