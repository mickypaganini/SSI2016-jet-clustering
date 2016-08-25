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

#include "JetAnalysis.hh"
#include "JetCollection.hh"

#include "fastjet/PseudoJet.hh"
using namespace fastjet;

#include <iostream>
#include <vector>
using namespace std;

namespace SpartyJet { 


string JetAnalysis::name() {return m_name;}

void JetAnalysis::set_name(string name) {
  m_name = name;
  m_log.set_name(name);
}

void JetAnalysis::add_tool(JetTool* tool) {
  m_toolList.push_back(tool);
}

void JetAnalysis::add_tool_front(JetTool* tool) {
  m_toolList.push_front(tool);
}

void JetAnalysis::init() {
  jettool_list_t::iterator it  = m_toolList.begin();
  jettool_list_t::iterator itE = m_toolList.end();

  for (; it != itE; ++it) {
    (*it)->init(&m_mmap);
    m_log << DEBUG << "Initialized tool: " << (*it)->name() << endl;
    if (m_measureTime) prepare_time(*it);
  }
}


void JetAnalysis::execute(const Jet::jet_list_t& inputJets, JetCollection& outputJets) const {
  // copy the structure of JetMoments from JetAnalysis into output collection
  outputJets.get_JetMomentMap()->copy_structure(m_mmap);
  
  // copy Jets completely (not just pointers)
  outputJets.deep_copy(inputJets);

  execute(outputJets);
}


void JetAnalysis::execute(const JetCollection& inputJets, JetCollection& outputJets) const {
  // copy the structure of JetMoments from JetAnalysis into output collection
  JetMomentMap* outputMap = outputJets.get_JetMomentMap();
  outputMap->copy_structure(m_mmap);  

  // if inputJets have the event moment HardProcess, copy it
  const JetMomentMap* inputMap = inputJets.get_JetMomentMap();
  if (inputMap->has_event_moment("HardProcess")) {
    outputMap->schedule_event_moment<vector<PseudoJet> >("HardProcess");
    outputMap->set_event_moment<vector<PseudoJet> >("HardProcess", inputMap->get_event_moment<vector<PseudoJet> >("HardProcess"));
  }
  
  // copy Jets completely (not just pointers)
  outputJets.deep_copy(inputJets.jet_list());

  execute(outputJets);
}


void JetAnalysis::execute(JetCollection& outputJets) const {
  stopwatch watch;
  // Loop over tools:
  jettool_list_t::iterator it  = m_toolList.begin();
  jettool_list_t::iterator itE = m_toolList.end();
  for (; it != itE; ++it) {
    watch.start();
    
    m_log << INFO << "---- " << (*it)->name() << endl;
    (*it)->execute(outputJets);
    m_log << INFO << "---- " << "remaining jets: "<< outputJets.size() << endl;

    // save times if needed:
    float t = watch.stop();
    if (m_measureTime) record_time(*it, t, outputJets.get_JetMomentMap()); 
  }

  // REMOVED: Preserve FastJet ordering, so you can compare different analysis chains
  // sort by Et by default
  //sort_list_et(outputJets);
}


void JetAnalysis::finalize() {
  jettool_list_t::iterator it  = m_toolList.begin();
  jettool_list_t::iterator itE = m_toolList.end();
  for (; it != itE; ++it) (*it)->finalize();
}


void JetAnalysis::prepare_time(JetTool* jt) {
  string name = jt->name();
  if (name == "selector") return; // not interesting.
  m_mmap.schedule_event_moment(name+"Time");  
}

void JetAnalysis::record_time(JetTool* jt, float t, JetMomentMap* map) const {
  string name = jt->name();
  if (name == "selector") return; // not interesting.
  map->set_event_moment(name+"Time", t);
}

void JetAnalysis::print_tools() const {

  cout << "JetAnalysis " << m_name << ", consisting of:" << endl;
  jettool_list_t::iterator it  = m_toolList.begin();
  jettool_list_t::iterator itE = m_toolList.end();
  for (; it != itE; ++it)
    cout << "  " << (*it)->name() << endl;
  cout << "----------------------------------------------" << endl;
}

}  // namespace SpartyJet
