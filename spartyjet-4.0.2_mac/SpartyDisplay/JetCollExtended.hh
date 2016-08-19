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

#ifndef _JETCOLLEXTENDED_H
#define _JETCOLLEXTENDED_H

#include "JetCore/JetCollection.hh"

#include <string>
#include <vector>

namespace SpartyJet { 

class JetCollExtended : public JetCollection {
public:

  JetCollExtended() : JetCollection() {
    m_algname = ""; m_colorCode = 0; m_radius = 0.0;}

  JetCollExtended(const JetCollExtended& t) : JetCollection(t) {
    m_algname = ""; m_colorCode = 0; m_radius = 0.0;}

  std::string name()   {return m_algname;}
  int    color()  {return m_colorCode;}
  float  radius() {return m_radius;}

  void debug();

  void clear_and_delete() {m_algoIndices.clear(); JetCollection::clear_and_delete();}
  std::vector<int> m_algoIndices;

  void set_algo_indices(size_t num);

protected:
  std::string m_algname;
  int m_colorCode;
  float m_radius;

};
}  // namespace SpartyJet
#endif
