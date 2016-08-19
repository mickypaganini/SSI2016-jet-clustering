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

#include "GetJets.hh"
#include "JetMomentMap.hh"

using namespace std;

namespace SpartyJet {

JetCollection getjets(JetTool* tool, Jet::jet_list_t& inputJets) {
  // first create a JetAnalysis and add the jet tool
  JetAnalysis analysis;
  analysis.make_silent();
  analysis.add_tool(tool);
  analysis.init();

  JetCollection outputJets;
  analysis.execute(inputJets, outputJets);
  return outputJets;
}

vector<TLorentzVector> getjets(JetTool* tool, vector<TLorentzVector>& input) {
  vector<TLorentzVector> output;
  SpartyJetTool sparty;
  output = sparty.getjets(tool, input);
  return output;
}

vector<simplejet> getjets(JetTool* tool, vector<simplejet>& input) {    
  vector<simplejet> output;
  SpartyJetTool sparty;
  output = sparty.getjets(tool, input);
  return output;
}

vector<TLorentzVector> getjets(JetTool* tool, vector<TLorentzVector>& input,
                               vector<vector<int> >& constituents) {
  vector<TLorentzVector> output;
  SpartyJetTool sparty;
  output = sparty.getjets(tool, input, constituents);
  return output;
}


// ********************************************************************
// New tool
// ********************************************************************

JetCollection SpartyJetTool::getjets(JetTool* tool, Jet::jet_list_t& inputJets) {
  init_analysis(tool);
  JetCollection outputJets;
  m_analysis->execute(inputJets, outputJets);
  return outputJets;
}


vector<TLorentzVector> SpartyJetTool::getjets(JetTool* tool, vector<TLorentzVector>& input) {
  JetCollection inputJets;
  for (unsigned i = 0; i < input.size(); i++) {
    Jet* temp = new Jet(input[i]); // uses template<class v> PseudoJet(const somevector& v)
    inputJets.push_back(temp);
  }
  
  init_analysis(tool);
  JetCollection outputJets;
  m_analysis->execute(inputJets, outputJets);
  
  // convert outputJets back to vector<TLorentzVector>
  vector<TLorentzVector> output;
  for (unsigned i = 0; i < outputJets.size(); i++)
    output.push_back(TLorentzVector(outputJets[i]->px(), outputJets[i]->py(),
				    outputJets[i]->pz(), outputJets[i]->E()));
  return output;
}


vector<TLorentzVector> SpartyJetTool::getjets(JetTool* tool,
					       vector<TLorentzVector>& input,
					       vector<vector<int> >& constituents) {
  // convert input to Jet::jet_list_t
  JetCollection inputJets;
  int num = 0;
  for (unsigned i = 0; i < input.size(); i++) {
    Jet* temp = new Jet(input[i][0], input[i][1], input[i][2], input[i][3], num);
    num++;
    inputJets.push_back(temp);
  }
  
  init_analysis(tool);
  JetCollection outputJets;
  m_analysis->execute(inputJets, outputJets);
  
  // convert outputJets back to vector<TLorentzVector>
  vector<TLorentzVector> output;
  constituents.clear();
  for (unsigned i = 0; i < outputJets.size(); i++) {
    output.push_back(TLorentzVector(outputJets[i]->px(), outputJets[i]->py(),
				    outputJets[i]->pz(), outputJets[i]->E()));
    
    // convert constituents to vector< vector<int> >
    vector<int> tempvect;
    Jet::constit_vect_t::iterator citer  = outputJets[i]->first_constituent();
    for (; citer != outputJets[i]->last_constituent(); citer++) {
      const Jet* cjet = *citer;
      tempvect.push_back(cjet->input_index());
    }
    constituents.push_back(tempvect);
  }
  return output;
}


vector<simplejet> SpartyJetTool::getjets(JetTool* tool, vector<simplejet>& input) {    
  JetCollection inputJets;
  int num = 0;
  for (unsigned i = 0; i < input.size(); i++) {
    Jet* temp = new Jet(input[i].jet[0], input[i].jet[1], input[i].jet[2], input[i].jet[3], num);
    inputJets.push_back(temp);
    num++;
  }
  
  init_analysis(tool);
  JetCollection outputJets;
  m_analysis->execute(inputJets, outputJets);

  JetMomentMap* moment_map = outputJets.get_JetMomentMap();
  // convert outputJets back to vector<TLorentzVector>
  vector<simplejet> output;
  simplejet tempsimplejet;
  for (unsigned i = 0; i < outputJets.size(); i++) {
    TLorentzVector* temp2 = new TLorentzVector(outputJets[i]->px(), outputJets[i]->py(),
			                                outputJets[i]->pz(), outputJets[i]->E());
    // convert constituents to vector< vector<int> >
    tempsimplejet.constituents.clear();

    tempsimplejet.area = moment_map->get_jet_moment("area", outputJets[i]);
    tempsimplejet.area_error = moment_map->get_jet_moment("area_erro", outputJets[i]);
    
    Jet::constit_vect_t::iterator citer  = outputJets[i]->first_constituent();
    for (; citer != outputJets[i]->last_constituent(); citer++) {
      const Jet* cjet = *citer;
      TLorentzVector* consttemp = new TLorentzVector(cjet->px(), cjet->py(), cjet->pz(), cjet->E());
      tempsimplejet.constituents.push_back(*consttemp);
      delete consttemp;
    }
    
    tempsimplejet.jet = *temp2;
    output.push_back(tempsimplejet);
    delete temp2;
  }  
  return output;
}


void SpartyJetTool::add_tool(JetTool* tool, bool beforeFinder) { 
  if (beforeFinder) m_frontTools.push_back(tool);
  else m_backTools.push_back(tool);
}


void SpartyJetTool::remove_tool(JetTool* tool){
  vector<JetTool*>::iterator it = m_frontTools.begin();
  while (it != m_frontTools.end()) {
    if (*it == tool) {
      m_frontTools.erase(it);
      break;
    }
    ++it;
  }
  if (it !=  m_frontTools.end()) return; // we found and removed the tool
  
  // search tool in the other tool list
  it = m_backTools.begin();
  while (it != m_backTools.end()) {
    if (*it == tool) {
      m_backTools.erase(it);
      break;
    }
    ++it;
  }
}


void SpartyJetTool::clear_additional_tools(bool do_delete) {
  if (do_delete) {
    clear_list(m_frontTools);
    clear_list(m_backTools);
  } else {
    m_frontTools.clear();
    m_backTools.clear();
  }
}


void SpartyJetTool::init_analysis(JetTool* tool) {
  if (m_analysis) {
    delete m_analysis;
    m_analysis = 0;
  }
  m_analysis = new JetAnalysis();
  m_analysis->make_silent();

  // add front tools:
  vector<JetTool*>::iterator it = m_frontTools.begin();
  for (; it != m_frontTools.end(); ++it) m_analysis->add_tool(*it);

  m_analysis->add_tool(tool);
  
  // add back tools:
  it = m_backTools.begin();
  for (; it != m_backTools.end(); ++it) m_analysis->add_tool(*it);

  m_analysis->init();    
}

}  // namespace SpartyJet
