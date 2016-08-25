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

#ifndef _ECONVERSION_TOOL_HH_
#define _ECONVERSION_TOOL_HH_

#include <string>
#include "JetCore/JetTool.hh"
namespace SpartyJet { 

// Class to change Energy/Momentum units of Jets
class JetMomentMap;
class EConversionTool : public JetTool {
public:
  EConversionTool(std::string name) : JetTool(name), m_toGeV(true),m_MeV(0.001),m_GeV(1) {};
  EConversionTool(std::string name, bool toGeV) : JetTool(name), m_toGeV(toGeV),m_MeV(0.001),m_GeV(1) {};
	virtual void init(JetMomentMap *mmap);
  virtual void execute(JetCollection &inputJets);
	// Jets are assumed to be in GeV (i.e. setGeV(1.) )
  void setGeV(double unit){m_GeV=unit; m_MeV=m_GeV/1000.;}
protected:
  bool m_toGeV;
  double m_MeV;
  double m_GeV;

};
}  // namespace SpartyJet
#endif 
