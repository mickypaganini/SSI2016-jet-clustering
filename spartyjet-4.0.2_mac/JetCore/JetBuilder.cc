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
#include "JetTool.hh"
#include "CommonUtils.hh"
#include "GhostBuilder.hh"
#include "JetNegEnergyTool.hh"
#include "JetBuilder.hh"
#include "InputMaker.hh"

#include "TRandom3.h"

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

namespace SpartyJet { 

JetBuilder::JetBuilder(MessageLevel ml)
  : m_GeV(1.0), m_MeV(.001), m_needInit(true), m_savingInput(true),
  m_ghost_builder(0), m_correct_neg_energy(false),
  m_neg_energyTool(new JetNegEnergyTool("NegEnergyTool")),
  m_updateOutput(false), m_inputMaker(0), m_writeTextOutput(false),
  m_nminbias(0), m_MBinput(0), m_MB_currentEvent(0), m_poisson(true),
  m_rand(0), m_measureTime(0), m_log("JetBuilder"), m_eventMod(1)
{
  Message::set_message_level(ml);
}


JetBuilder::~JetBuilder() {
  // First clear JetVars, before we clear the momentmaps:
  m_ntpmaker.clear_vars();
  // Clear algs and their associated JetCollections & JetMomentMaps
  jetanalysis_map_t::iterator it  = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();
  for (; it!= itE; ++it) {
    m_log << DEBUG << "Clearing "<< (*it).first << endl;
    analysis_info_t analysisInfo = (*it).second;
    if (analysisInfo.analysis != 0) { 
      if (analysisInfo.internAlg) delete analysisInfo.analysis; // don't delete user-given algos
      if (analysisInfo.jetlist != 0) { // this should not happen
        analysisInfo.jetlist->clear_and_delete();
        delete analysisInfo.jetlist;
      }
    }
  }
  m_analyses.clear();
  m_log << DEBUG << "Cleared algmap " << endl;
  m_inputList.clear_and_delete();
  m_log << DEBUG << "Cleared input " << endl;
  delete m_neg_energyTool;
}


void JetBuilder::configure_input(InputMaker* input, bool saveInput) {
  m_inputMaker = input;
  m_savingInput = saveInput;
  m_inputMaker->init();
  
  if (m_savingInput) { 
    string name = input->name();
    if (name == "") name = "Input";    
    // Add dummy alg of Input so it is saved in ntuple
    m_analyses[name] = analysis_info_t(0, &m_inputList, 0);
  }

  m_GeV = input->getGeV();
  m_MeV = input->getMeV();
}

void JetBuilder::configure_output(string treename, string filename, bool update) {
  m_treename = treename;
  m_filename = filename;
  m_updateOutput = update;
}

void JetBuilder::add_text_output(string filename) {
  m_writeTextOutput = true;
  m_textFilename = filename;
}


void JetBuilder::add_default_analysis(JetTool* jetfinder, bool withIndex) {
  JetAnalysis* analysis;
  string name;
  if (!jetfinder) {
    m_log << WARNING << "JetTool is null. Configuring only selectors " << endl;
    name = "NoJetFinder";
    analysis = new JetAnalysis(name);
  } else {
    name = jetfinder->name();
    if (m_analyses.find(name) != m_analyses.end()) {
      m_log << ERROR << "JetTool " << name << "already configured." << endl;
      return;
    }
    m_log << DEBUG << "Configuring default algorithm with finder " << name << endl;
    analysis = new JetAnalysis(name);
		
    // Now add the default tools around the jet finder
    if (m_correct_neg_energy) analysis->add_tool(m_neg_energyTool); // negative energy handler (if requested)
    analysis->add_tool(jetfinder);  // The jet finder !! ---------------------------------------
    if (m_correct_neg_energy) analysis->add_tool(m_neg_energyTool); // negative energy handler (if requested)
  }
  m_analyses[name] = analysis_info_t(analysis, new JetCollection(), withIndex);
  m_analysis_order.push_back(name);  
}


void JetBuilder::add_analysis(JetAnalysis* a, bool withIndex, bool saveOnlyMomentMap) {
  m_analyses[a->name()] = analysis_info_t(a, new JetCollection(), withIndex, saveOnlyMomentMap, false);
  m_analysis_order.push_back(a->name());
}


void JetBuilder::add_jetTool(JetTool* tool, string name) {
  jetanalysis_map_t::iterator it  = m_analyses.find(name);
  if (it != m_analyses.end()) {
    JetAnalysis *analysis = (*it).second.analysis;
    analysis->add_tool(tool);
  } else {
    m_log << ERROR << "No JetAnalysis '"<<name << "'. Did not insert JetTool "<< tool->name() <<endl;
  }
}


void JetBuilder::add_jetTool(JetTool* tool) {
  jetanalysis_map_t::iterator it  = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();
  for (; it != itE; ++it) {
    JetAnalysis* analysis = (*it).second.analysis;
    if (analysis != 0) analysis->add_tool(tool);
  }  
}

void JetBuilder::add_jetTool_front(JetTool* tool, string name) {
  jetanalysis_map_t::iterator it = m_analyses.find(name);
  if (it != m_analyses.end()) {
    JetAnalysis* analysis = (*it).second.analysis;
    analysis->add_tool_front(tool);
  } else {
    m_log << ERROR << "No JetAnalysis '"<<name << "'. Did not insert JetTool "<< tool->name() <<endl;
  }
}

void JetBuilder::add_jetTool_front(JetTool* tool) {
  jetanalysis_map_t::iterator it =  m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();
  for (; it != itE; ++it) {
    JetAnalysis* analysis = (*it).second.analysis;
    if (analysis == 0) continue;
    analysis->add_tool_front(tool);
  }  
}

void JetBuilder::add_jetTool_input(JetTool* tool) {
  m_inputToolList.push_back(tool);
}


void JetBuilder::process_events(int nevent, int start) {

  if (m_writeTextOutput) start_text_output(nevent, start);
  if (!m_inputMaker) {
    m_log << ERROR << "No input defined! Please use configure_input()." << endl;
    return;
  }
  if (m_needInit) init();
  m_inputMaker->moveToEventN(start);
  
  int i = 0;
  while (process_next_event()) {
    write_current_event();
    m_log << INFO << "************** End Event " << m_inputMaker->current_event() << "********************* " << endl;
    if (m_writeTextOutput) continue_text_output(i);
    i++;
    if (i % m_eventMod == 0) cout << "Events Processed: " << i << endl;
    if (i == nevent) break;
  }
  m_ntpmaker.finalize();
  if (m_writeTextOutput) finish_text_output();
}


bool JetBuilder::process_next_event() {
  m_inputList.clear_and_delete();

  // get Input
  bool cont = m_inputMaker->fillNextInput(m_inputList);

  // skip empty event at end of files for some input types
  if (!cont && m_inputList.size() == 0) return false;

  m_log << INFO << "************** Begin Event " << m_inputMaker->current_event() << "*******************" << endl;
  m_log << INFO << "Input size is: "<< m_inputList.size() << endl; 

  // Get min bias if requested
  get_minbias_events();
  if (m_nminbias > 0) m_log << INFO << "Added minbias events. Input size is now: " << m_inputList.size() << endl;
  
  // Add ghosts if any
  add_ghosts();
 
  // Run special jet tools that need to modify the global input
  if (!m_inputToolList.empty()) {
    m_log << INFO << "Executing input JetTool list" << endl;
    jettool_list_t::iterator it  = m_inputToolList.begin();	
    jettool_list_t::iterator itE = m_inputToolList.end();	
    m_log << INFO << "Initial input size: " << m_inputList.size() << endl;
    for (; it != itE; ++it) {
      m_log << INFO << "---- " << (*it)->name() << endl;
      (*it)->execute(m_inputList);
      m_log << INFO << "---- " << "remaining jets: "<< m_inputList.size() << endl;
    }
  }
  
  // After running input tools, reset indices so that m_inputList[i]->index() = i
  for (size_t i = 0; i < m_inputList.size(); ++i) m_inputList[i]->set_index(i);

  // Execute all algorithms *in order*
  for (size_t i = 0; i < m_analysis_order.size(); ++i) {
    string name = m_analysis_order[i];
    analysis_info_t& analysis_info = m_analyses[name];
    if (analysis_info.analysis == 0) continue;
    m_log << INFO << "==== Algorithm: " << name << " ====" << endl;
    m_log << INFO << "Initial input size: " << m_inputList.size() << endl;
    // Get the result list for this analysis...
    JetCollection* jetcoll = analysis_info.jetlist;
    // ... clear it...
    jetcoll->clear_and_delete();
    // ... and fill it
    m_log << INFO << "Executing JetTool list for  "<< name << endl;
    (analysis_info.analysis)->execute(m_inputList, *jetcoll);
    
  }
  return cont;
}


void JetBuilder::process_one_event(int n) {
  if (m_needInit) init();
  m_inputMaker->moveToEventN(n);
  process_next_event();
}


JetCollection* JetBuilder::get_jets(string analysis) {
  jetanalysis_map_t::iterator it = m_analyses.find(analysis);
  if (it != m_analyses.end()) return (*it).second.jetlist;
  return 0;
}


void JetBuilder::add_minbias_events(float n, InputMaker* input, bool on) {
  m_MBinput = input;
  m_MBinput->init();
  m_nminbias = n;
  m_poisson = on;
  if (m_poisson) m_rand = new TRandom3(abs(time(0)));
}


void JetBuilder::get_minbias_events() {
  if (m_nminbias == 0) return;
  bool c;
  m_MBjetList.clear();

  int temp_num;
  
  if (m_poisson) {
    temp_num = m_rand->Poisson(m_nminbias);
    m_log << INFO << "Poisson Minimum Bias selected " << temp_num << " minbias events." << endl;
  } else
    temp_num = int(m_nminbias);

  int numInputBefore = m_inputList.size();
  for (int MBi = 0; MBi < temp_num; MBi++) {
    m_MBinput->moveToEventN(m_MB_currentEvent);  
    int first_index = m_inputList.size();
    c = m_MBinput->fillNextInput(m_inputList,first_index); // directly fill input list
    if (!c) {                 // found no event
      m_MB_currentEvent = 0;  // start back over at beginning
      m_MBinput->moveToEventN(0);
      MBi--;                  // take one away to make up for empty event
    } else {
      m_MB_currentEvent++;
    }
  }
  m_inputList.get_JetMomentMap()->set_event_moment("nMBevents", temp_num);
  m_inputList.get_JetMomentMap()->set_event_moment("N_MB", m_inputList.size() - numInputBefore);
}


void JetBuilder::set_minbias_poisson(bool on, int seed, int firstMBevt) {
  if (m_rand != 0) delete m_rand;
  m_poisson = on;  
  if (seed == 0) seed = abs(time(0));
  if (m_poisson) m_rand = new TRandom3(seed);
  m_MB_currentEvent = firstMBevt;
}


void JetBuilder::adding_active_ghosts(int nghosts) {
  if (m_ghost_builder) {delete m_ghost_builder; m_ghost_builder = 0;}
  if (nghosts > 0) m_ghost_builder = new GhostBuilderRandom(nghosts);
}

void JetBuilder::reconfigure_ghosts(int nghosts, float rapmin, float rapmax, float phimin, float phimax) {
  if (!m_ghost_builder) adding_active_ghosts(nghosts);
  m_ghost_builder->reconfigure(nghosts, rapmin, rapmax, phimin, phimax);
}

void JetBuilder::add_ghosts() {
  if (!m_ghost_builder) return;
  m_ghost_builder->add_ghosts(&m_inputList);
}  


void JetBuilder::init() {
  // allow the input maker to add moments
  m_log << DEBUG << "Initializing InputMaker" << endl;
  m_inputMaker->init_collection(m_inputList);

  // Loop over and init input tool list
  jettool_list_t::iterator tit  = m_inputToolList.begin();	
  jettool_list_t::iterator titE = m_inputToolList.end();	
  for (; tit != titE; ++tit) {
    m_log << DEBUG << "Initializing input tool: " << (*tit)->name() << endl;
    (*tit)->init(m_inputList.get_JetMomentMap());	
  }
  // first register output variables of input collection
  if (m_savingInput) { 
    string name = m_inputMaker->name();
    if (name == "") name = "Input";    

    // Schedule MB-overlay-related event moments
    if (m_nminbias > 0) {
      m_inputList.get_JetMomentMap()->schedule_event_moment<int>("nMBevents");
      m_inputList.get_JetMomentMap()->schedule_event_moment<int>("N_MB");
    }
    m_ntpmaker.addInputJetVar(m_output_var_style.get_inputjet_var(name, m_inputList.get_JetMomentMap()));
  }

  // Loop over analyses and register output
  jetanalysis_map_t::iterator it  = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();
  for (; it != itE; ++it) {
    JetAnalysis * analysis = (*it).second.analysis;
    if (analysis == 0) continue;
    if (m_measureTime) analysis->do_time_measure();

    analysis->init();

    // Register this JetAnalysis in NtupleMaker
    IGenericJetVar* jv = create_jet_var(analysis->name(), (*it).second);
    m_ntpmaker.addJetVar(jv);
  }  

  m_ntpmaker.init(m_treename, m_filename, m_updateOutput);
  m_needInit = false;
}


void JetBuilder::write_current_event() {
  // First set Input data if needed:
  string inputName = m_inputMaker->name();
  jetanalysis_map_t::iterator it = m_analyses.find(inputName);
  if (m_savingInput) {
    m_ntpmaker.set_data((*it).first, *(*it).second.jetlist);
  } else {
    inputName = "";
  }
  // Now save all other jet collections:
  it = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();
  for (; it != itE; ++it) {
    if (inputName == (*it).first) continue; // (was done above)
    m_ntpmaker.set_data((*it).first, *(*it).second.jetlist);
  }
  m_ntpmaker.fillJets();
}


void JetBuilder::start_text_output(int nevent, int start) {
  m_textfile << left;

  jetanalysis_map_t::iterator it  = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();

  m_textfile.open(m_textFilename.c_str());
  if (!m_textfile.is_open()) m_log << ERROR << "Output text file \"" << m_textFilename << "\" not created!\n";

  m_textfile << "***********************************************************************" << endl;
  m_textfile << "***********************************************************************" << endl;
  m_textfile << "***** SpartyJet Text Output File                                  *****" << endl;
  m_textfile << "*****-------------------------------------------------------------*****" << endl;
  m_textfile << "*****-------------------------------------------------------------*****" << endl;
  m_textfile << "*****                   Current Job Description                   *****" << endl;
  m_textfile << "*****-------------------------------------------------------------*****" << endl;
  m_textfile << "*****   Input File Info:                                          *****" << endl;
  m_textfile << "*****     Object Name:  " << setw(42) << m_inputMaker->name()  << "*****" << endl;
  m_textfile << "*****-------------------------------------------------------------*****" << endl;
  m_textfile << "*****   Algorithms:                                               *****" << endl;
  for (; it != itE; ++it) {
    if (it->first == m_inputMaker->name()) continue;
    m_textfile << "*****      " << setw(55) << it->first << "*****" << endl;
  }
  m_textfile << "*****-------------------------------------------------------------*****" << endl;
  m_textfile << "*****   Orders:                                                   *****" << endl;
  m_textfile << "*****     Process " << setw(7) << nevent <<  " events, starting at event " 
             << setw(7) << start << "       *****" << endl;
  if (m_nminbias > 0) {
    m_textfile << "*****   Add Minimum Bias Events : " << setw(10) << m_nminbias << "                      *****" << endl;
    if (m_poisson) m_textfile << "*****     Poisson Option Turned on                              *****" << endl;
    m_textfile << "*****     From object name:  " << setw(37) << m_MBinput->name()  << "*****" << endl;
  }
  m_textfile << "***********************************************************************" << endl;
  m_textfile << "***********************************************************************" << endl;
}


void JetBuilder::continue_text_output(int i) {
  jetanalysis_map_t::iterator it  = m_analyses.begin();
  jetanalysis_map_t::iterator itE = m_analyses.end();

  m_textfile << "\n\n\n***********************************************************************" << endl;
  m_textfile << "Event " << i << endl;
  for (; it != itE; ++it)
    if (it->first == m_inputMaker->name()) 
      m_textfile << "  " << it->second.jetlist->size() << " four vectors" << endl;
  m_textfile << "***********************************************************************" << endl;

  it = m_analyses.begin();
  for (; it != itE; ++it) {
    if (it->first == m_inputMaker->name()) continue;

    m_textfile << it->first << " Jets\n";
    m_textfile << "           Pt          eta          phi     n      mass\n";
    m_textfile << right;
    JetCollection* jc = it->second.jetlist;
    JetCollection::iterator jit  = jc->begin();
    JetCollection::iterator jitE = jc->end();
    for (; jit != jitE; ++jit) {
      Jet *j = (*jit);
      m_textfile << setw(13) << j->pt()
                 << setw(13) << j->eta()
                 << setw(13) << j->phi()
                 << setw(6)  << j->get_constituent_num()
                 << setw(13) << j->mass() << endl;
    }
    m_textfile << "\n\n";
  }
}


IGenericJetVar* JetBuilder::create_jet_var(string name, analysis_info_t an_info) {

  IGenericJetVar* inputvar = m_ntpmaker.getJetVar(m_inputMaker->name());
  if (!an_info.saveIndex || !m_savingInput) inputvar = 0;  // we don't save index of constituents

  JetAnalysis* analysis = an_info.analysis;
  return m_output_var_style.get_jet_var(name, analysis->get_jet_moment_map(), 
                                      inputvar, an_info.saveOnlyMomentMap);
}


}  // namespace SpartyJet
