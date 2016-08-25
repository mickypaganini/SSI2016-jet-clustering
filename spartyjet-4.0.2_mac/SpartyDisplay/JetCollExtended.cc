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


#include "JetCollExtended.hh"
#include <iostream>
using namespace std;

namespace SpartyJet {

void JetCollExtended::debug() {
  cout << " JetCollExtended : " << this << endl;
}

void JetCollExtended::set_algo_indices(size_t numC) {
  Jet::jet_list_t::iterator it  = begin();
  Jet::jet_list_t::iterator itE = end();
  m_algoIndices.clear();
  m_algoIndices.resize(numC, -1);    
  int jcount = 0;
  for ( ; it != itE; ++it) {
    Jet::constit_vect_t::iterator cit = (*it)->first_constituent();
    Jet::constit_vect_t::iterator citE = (*it)->last_constituent();
    for (; cit != citE; cit++) m_algoIndices[ (*cit)->input_index() ] = jcount;
    jcount++;
  }
}

}
