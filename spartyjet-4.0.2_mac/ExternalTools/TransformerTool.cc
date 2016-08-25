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

#include "TransformerTool.hh"
#include "JetCore/JetStructure.hh"
#include "JetCore/JetCollection.hh"

#include "fastjet/PseudoJet.hh"
using namespace fastjet;

#include <vector>
using namespace std;

namespace SpartyJet {
namespace FastJet {


// allows has_structure_of() call below...
struct fake {typedef JetStructure StructureType;};

// executes the transformer on each jet
void TransformerTool::execute(JetCollection& jc) {
  JetCollection::iterator it, itE = jc.end();
  for (it = jc.begin(); it != itE; ++it) {
    Jet* j = *it;
    execute(j, jc.get_JetMomentMap());
  }
}

void TransformerTool::execute(Jet* j, JetMomentMap* map) {
  // Don't bother if this jet has already failed a previous Transformer
  if (((PseudoJet)(*j) == 0)) return;

  *j = (*m_transformer)(*j);
  
  if (((PseudoJet)(*j) == 0)) {
    // transformer failed: clear history but leave blank jet for statistics, e.g.
    j->clear_history();
  } else {
    // set any moments associated with this transformer
    m_moment_handler->set_moments(j, map);
    
    // in general, transformers will yield jets with new structure
    // if so, clear out old history associated with jet
    if (!j->PseudoJet::has_structure_of<fake>())
      j->clear_history();
  }
}


}
} // namespace SpartyJet
