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


#include "JetInputCollection.hh"
#include <iostream>
using namespace std;

namespace SpartyJet { 

  vector<int> & JetInputCollection::get_jetColl_indices(JetCollExtended* jcoll) {
    for (size_t i = 0; i < m_jetcoll.size(); i++) {
      if (jcoll == m_jetcoll[i]) return m_algoIndices[i];
    }
    cout << "JetInputCollection::get_jetColl_indices did not find " << jcoll << endl;
    vector<int> *v = new vector<int>; return *v;
  }

}
