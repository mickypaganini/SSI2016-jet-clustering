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

#ifndef _GETJETS_HH_
#define _GETJETS_HH_

#include "JetCollection.hh"
#include "JetAnalysis.hh"
#include "CommonUtils.hh"

#include "TLorentzVector.h"

#include <vector>
#include <list>


// old functions for backwards compatibility
namespace SpartyJet {

class JetTool;

struct simplejet {
  TLorentzVector jet;
  double area;
  double area_error;
  std::vector<TLorentzVector> constituents;
};

JetCollection getjets(JetTool* tool, Jet::jet_list_t& inputJets);
std::vector<TLorentzVector> getjets(JetTool* tool, std::vector<TLorentzVector>&);
std::vector<TLorentzVector> getjets(JetTool* tool, std::vector<TLorentzVector>&, std::vector<std::vector<int> >&);
std::vector<SpartyJet::simplejet> getjets(JetTool* tool, std::vector<SpartyJet::simplejet>& input);


// new class
class SpartyJetTool {
public:
  SpartyJetTool(): m_analysis(NULL) {}
  ~SpartyJetTool() {if (m_analysis) delete m_analysis;}
  
  JetCollection                     getjets(JetTool* tool, Jet::jet_list_t& inputJets);
  std::vector<TLorentzVector>       getjets(JetTool* tool, std::vector<TLorentzVector>&);
  std::vector<TLorentzVector>       getjets(JetTool* tool, std::vector<TLorentzVector>&, std::vector<std::vector<int> >&);
  std::vector<SpartyJet::simplejet> getjets(JetTool* tool, std::vector<SpartyJet::simplejet>& input);
  
  void add_tool(JetTool* tool, bool beforeFinder = false);
  void remove_tool(JetTool* tool);
  void clear_additional_tools(bool do_delete = true );
  
protected:
  JetAnalysis* m_analysis;
  void init_analysis(JetTool* tool);
  std::vector<JetTool*> m_frontTools;
  std::vector<JetTool*> m_backTools;
};
  
}  // namespace SpartyJet
#endif
