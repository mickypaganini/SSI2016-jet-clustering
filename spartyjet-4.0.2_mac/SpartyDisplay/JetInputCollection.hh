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

#ifndef _JETINPUTCOLLECTION_H
#define _JETINPUTCOLLECTION_H


#include "JetCollExtended.hh"
#include <vector>

namespace SpartyJet { 

class JetInputCollection : public JetCollExtended {
public:
  JetInputCollection() : JetCollExtended() {}
  /// The vectors m_algoIndices[i] is the map of constituents to jets made by algo i
  ///  i.e. m_algoIndices[alg][c] == j if constituent c of this JetInputCollection is part of jet j from
  ///  jetcollection alg.
  std::vector<std::vector<int> > m_algoIndices;

  std::vector<int>& get_jetColl_indices(JetCollExtended* jcoll);
  std::vector<JetCollExtended*> m_jetcoll;
};
}  // namespace SpartyJet
#endif
