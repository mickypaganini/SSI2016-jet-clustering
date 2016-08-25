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

#ifndef _HULLMOMENT_TOOL_HH_
#define _HULLMOMENT_TOOL_HH_

#include <string>
#include "JetCore/JetTool.hh"
namespace SpartyJet { 

class JetMomentMap;
class HullMomentTool : public JetTool {
public:
  HullMomentTool(std::string name) : JetTool(name) {}
  virtual void init(JetMomentMap* mmap);
  virtual void execute(JetCollection& inputJets);
};

}  // namespace SpartyJet
#endif 
