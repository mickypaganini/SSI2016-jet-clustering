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

#ifndef _PT_DENSITY_TOOL_HH_
#define _PT_DENSITY_TOOL_HH_

#include <string>
#include "JetCore/JetTool.hh"
#include "fastjet/JetDefinition.hh"
#include "fastjet/RangeDefinition.hh"
#include "fastjet/AreaDefinition.hh"

namespace SpartyJet { 

class JetMomentMap;

namespace FastJet { 

class PtDensityTool : public JetTool {
public:
  PtDensityTool(std::string name) : JetTool(name) {}
  
  PtDensityTool(std::string name, fastjet::JetAlgorithm densAlg, float R,
                fastjet::AreaType area, std::vector<float> etaBins);
                
  PtDensityTool(std::string name, fastjet::JetDefinition* densDef,
                fastjet::AreaType area, std::vector<float> etaBins);
                
  PtDensityTool(std::string name, fastjet::JetDefinition* densDef,
                fastjet::AreaType area,
                std::vector<fastjet::RangeDefinition>* rangeDefVec);
                
  virtual void init(JetMomentMap* mmap);
  virtual void execute(JetCollection& inputJets);

  void setDensityAlg(fastjet::JetDefinition* jDef) {m_densDef = *jDef;}
  void addRangeDef(fastjet::RangeDefinition* rDef) {m_rangeDefVec.push_back(*rDef);}
  void setEtaBins(std::vector<float> etaBins);

private:
  fastjet::JetDefinition  m_densDef;
  fastjet::AreaDefinition m_areaDef;
  std::vector<fastjet::RangeDefinition>	m_rangeDefVec;
};

}  // namespace FastJet
}  // namespace SpartyJet

#endif // _PT_DENSITY_TOOL_HH_
							
