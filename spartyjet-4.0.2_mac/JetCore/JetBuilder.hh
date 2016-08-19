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

#ifndef _JETBUILDER_HH_
#define _JETBUILDER_HH_

#include "CustomMessage.hh"
#include "Jet.hh"
#include "JetCollection.hh"
#include "OutputVarUtils.hh"
#include "NtupleMaker.hh"

#include <string>
#include <map>
#include <fstream>

class TTree;
class TRandom3;

namespace SpartyJet { 

class InputMaker;
class IGenericJetVar;
class JetAnalysis;
class JetTool;
class GhostBuilder;
class JetNegEnergyTool;


class JetBuilder {
public:
  JetBuilder(MessageLevel ml=INFO);
  ~JetBuilder();
  
  /// A pack of info related to a JetAnalysis
  struct analysis_info_t {
    analysis_info_t() {}
    analysis_info_t(JetAnalysis* a, JetCollection* list, bool ind, bool onlymap=false, bool intern=true)
      : analysis(a), jetlist(list), saveIndex(ind), saveOnlyMomentMap(onlymap), internAlg(intern) {}
    
    JetAnalysis* analysis;  ///< the jet analysis
    JetCollection* jetlist; ///< the jet list that will be passed to the jet analysis
    bool saveIndex;         ///< save jet constituents indices in final ntuple
    bool saveOnlyMomentMap; ///< if true don't save jets kinematics (used for eventshape analyses, e.g.)
    bool internAlg;         ///< Mark this as owned by a JetBuilder (otherwise it will not be deleted)
  };
  
  typedef std::map<std::string, analysis_info_t> jetanalysis_map_t;
  typedef std::list<JetTool*>                    jettool_list_t;
  typedef std::map<std::string, jettool_list_t>  jettool_map_t; 



  /// Set the input class.
  /// @param saveInput if true, the input jets will be save in the final ntuple.
  void configure_input(InputMaker* input, bool saveInput=true);

  /// Set the name of the result ntuple (treename) and its file name (filename) by default the 
  /// file is overwritten (update=false)
  void configure_output(std::string treename, std::string filename, bool update=false);

  /// Add output text file that displays all of the jets for each event
  void add_text_output(std::string filename);
  
  
  /// Build & schedule a JetAnalysis with the JetTool jetfinder.
  /* This analysis will include the default set of pre- and post-tools,
   * currently JetNegEnergyTools.
   * If @param withIndex is true, an array relating input constituents with jets
   * is saved in the output ntuple.
   * The jet collection will be named as jetfinder->name()
   */
  void add_default_analysis(JetTool* j, bool withIndex=true);
  
  /// Correction of negative energy of inputs through JetNegEnergyTool 
  void do_correct_neg_energy(bool v) {m_correct_neg_energy = v;}

  /// Schedule a full JetAnalysis, with no default pre/post tools
  void add_analysis(JetAnalysis* analysis, bool withIndex=true, bool saveOnlyMap=false);

  /// Add an eventshape-like algorithm 
  /// (actually configure it not to produce jet vars, only moment map vars)
  void add_eventshape_analysis(JetAnalysis* a) {add_analysis(a, false, true);}


  /// Add a generic tool to a given analysis
  void add_jetTool(JetTool* jetTool, std::string name);
  /// Add a tool to all analyses
  void add_jetTool(JetTool* jetTool);
  /// Add a tool to the front of an analysis
  void add_jetTool_front(JetTool* jetTool, std::string name);
  /// Add a tool to the front of all analyses
  void add_jetTool_front(JetTool* jetTool);
  /// Add an input tool that is run on input particles before they are passed to JetAnalyses
  void add_jetTool_input(JetTool* jetTool);


  void process_events(int nevent=-1, int start=0);
  bool process_next_event();
  void process_one_event(int n);


  /// turn off message system (equivalent to set_message_level(ERROR))
  void silent_mode() const {Message::silent_all();}
  /// set message system to level 'l'; lower levels will not be printed
  void set_message_level(MessageLevel l) const {Message::set_message_level(l);}
  /// Set frequency of event number printing
  void print_event_every(int n) {m_eventMod = n;}

  /// Access the input jet collection
  JetCollection* get_input_jets() {return &m_inputList;}
  /// Access the jet collection corresponding to analysis
  JetCollection* get_jets(std::string analysis);

  /// Add Minimum-Bias events to data set
  /// @param poisson if true means number of min bias events is Poisson-distributed with mean n
  void add_minbias_events(float n, InputMaker* input, bool poisson=false);
  void get_minbias_events();
  void set_minbias_poisson(bool on, int seed=0, int firstMBevt=0);
  void set_minbias_num(float n) {m_nminbias = n;}

  void adding_active_ghosts(int nghosts);
  void reconfigure_ghosts(int nghosts, float rapmin, float rapmax, float phimin, float phimax);


  void do_time_measure() {m_measureTime = true;}
  
  /// Add conversion of jet's phi to [0.2Pi] in ROOT output
  void add_phi_conversion() const {IGenericJetVar::do_phiconversion = true;}

  double GeV() const {return m_GeV;}
  double MeV() const {return m_MeV;}


  void change_jet_ouptut_var(std::string eta, std::string phi, std::string pt,
                             std::string e, std::string mass, std::string ind, std::string numc) {
    m_ntpmaker.set_var_names(eta, phi, pt, e, mass, ind, numc);
  }

  void set_output_type(ArrayType a_type, BaseType b_type) {
    m_output_var_style.set_array_type(a_type);
    m_output_var_style.set_base_type(b_type);
  }

protected:

  /// Init all JetAnalyses and register them (or not) with the NtupleMaker class
  void init();
  
  /// Write all current jet collection into the associated TTree
  void write_current_event();
  void save_ntuple() {m_ntpmaker.finalize();}

  double m_GeV;
  double m_MeV;

  /// Holds configuration of output variable 
  OutputVarFactory m_output_var_style;

  // make text output file
  void start_text_output(int nevent, int start);
  void continue_text_output(int i);
  void finish_text_output() {m_textfile.close();}

  /// build jet var
  IGenericJetVar* create_jet_var(std::string name, analysis_info_t alg_i);

  bool m_needInit;
  bool m_savingInput;

  void add_ghosts();
  GhostBuilder* m_ghost_builder;

  /// Manage input particle with negative energy (calorimeter clusters....)
  bool m_correct_neg_energy;
  JetNegEnergyTool* m_neg_energyTool;
  
  jetanalysis_map_t m_analyses;              ///< stores JetAnalyses
  std::vector<std::string> m_analysis_order; ///< keep track of which order to run analyses (TODO: OrderedMap instead?)
  
  jettool_list_t  m_inputToolList; ///< stores input Tools

  JetCollection m_inputList;       ///< input jets

  NtupleMaker m_ntpmaker;          ///< manage final ntuple output
  bool m_updateOutput;
  InputMaker* m_inputMaker;        ///< manage input, given by user

  std::string m_treename;
  std::string m_filename;

  // for text output
  std::string m_textFilename;
  bool m_writeTextOutput;
  std::ofstream m_textfile;
 
  // for minbias events TODO: factor this out!
  float m_nminbias;
  InputMaker* m_MBinput;
  int m_MB_currentEvent;
  Jet::jet_list_t m_MBjetList;  /// minbias jets
  bool m_poisson;
  TRandom3* m_rand;

  bool m_measureTime;

  Message m_log;
  int m_eventMod;
};


}  // namespace SpartyJet
#endif
