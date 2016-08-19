// Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
//                 Brian Martin, and Christopher Vermilion
//
//----------------------------------------------------------------------
// This file is part of SpartyJet.
//
//  SpartyJet is free software you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation either version 3 of the License, or
//  (at your option) any later version.
//
//  SpartyJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with SpartyJet if not, write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#include "JetStructure.hh"
#include "JetCore/JetCollection.hh"

using namespace fastjet;
using namespace std;

const PseudoJet zeroJet;

namespace SpartyJet { 

/// check if it has been recombined with another PseudoJet in which
/// case, return its partner through the argument. Otherwise,
/// 'partner' is set to 0.
bool JetStructure::has_partner(const PseudoJet& reference, PseudoJet& partner) const {
  partner = zeroJet; // zero out partner; will be set if we successfully find a partner

  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = dynamic_cast<const Jet*>(&reference);
  const Jet* child = m_jetCollection->get_child(refJet);
  if (child == NULL) return false;
  vector<const Jet*> parents = m_jetCollection->get_parents(child);
  if (parents.size() != 2) {
    m_log << WARNING << "Trying to get partner of jet with more than one sibling." << endl;
    return false;
  }
  if (parents[0] == refJet)
    partner = *parents[1];
  else
    partner = *parents[0];

  return true;
}

/// check if it has been recombined with another PseudoJet in which
/// case, return its child through the argument. Otherwise, 'child'
/// is set to 0.
bool JetStructure::has_child(const PseudoJet& reference, PseudoJet& child) const {
  child = zeroJet;
  
  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = dynamic_cast<const Jet*>(&reference);
  const Jet* childJet = m_jetCollection->get_child(refJet);

  if (childJet == NULL) return false;
  child = *childJet;

  return true;
}

/// check if it is the product of a recombination, in which case
/// return the 2 parents through the 'parent1' and 'parent2'
/// arguments. Otherwise, set these to 0.
bool JetStructure::has_parents(const PseudoJet& reference, PseudoJet& parent1, PseudoJet& parent2) const {
  parent1 = zeroJet;
  parent2 = zeroJet;
  
  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = dynamic_cast<const Jet*>(&reference);
  vector<const Jet*> parents = m_jetCollection->get_parents(refJet);
  if (parents.size() != 2) {
    m_log << WARNING << "Trying to get parents of jet with" << parents.size() << " parents." << endl;
    return false;
  }
  parent1 = *parents[0];
  parent2 = *parents[1];

  return true;
}

/// retrieve the constituents. 
vector<PseudoJet> JetStructure::constituents(const PseudoJet& reference) const {
  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = dynamic_cast<const Jet*>(&reference);
  vector<const Jet*> constits = m_jetCollection->get_constituents(refJet);
  
  vector<PseudoJet> pjs;
  for (unsigned int i = 0; i < constits.size(); ++i)
    pjs.push_back(*constits[i]);

  return pjs;
}

bool JetStructure::has_pieces(const fastjet::PseudoJet& reference) const {
  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = reference.user_info<SpartyJetUserInfo>().jet();
  vector<const Jet*> parents = m_jetCollection->get_parents(refJet);
  return parents.size() > 0;
}


/// retrieve the pieces building the jet. 
vector<PseudoJet> JetStructure::pieces(const PseudoJet& reference) const {
  // PseudoJet must be a Jet (which inherits from PseudoJet)
  const Jet* refJet = reference.user_info<SpartyJetUserInfo>().jet();
  vector<const Jet*> parents = m_jetCollection->get_parents(refJet);
  
  vector<PseudoJet> pieces;
  for (unsigned int i = 0; i < parents.size(); ++i)
    pieces.push_back(*parents[i]);

  return pieces;
}


}  // namespace SpartyJet
