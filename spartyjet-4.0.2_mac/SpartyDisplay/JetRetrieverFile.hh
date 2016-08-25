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

#ifndef _JETRETRIEVERFILE_H
#define _JETRETRIEVERFILE_H

#include "JetInputCollection.hh"
#include "JetCollReaderBase.hh"

#include "TFile.h"
#include "TTree.h"

#include <vector>
#include <string>


const int MAXJETS  = 300;
const int MAXALGS  = 100;
const int MAXINPUT = 10000;


namespace SpartyJet { 

class JetCollExtended;


class JetRetrieverFile {
public:
  JetRetrieverFile();

  void fill_collections(JetInputCollection& jet_input_coll, std::vector<SpartyJet::JetCollExtended >& jet_coll_v, int event);

  void get_collection(JetInputCollection& jet_input_coll, JetCollExtended& jcoll, int numC, int event);

  void fill_inputColl(JetInputCollection& inputColl, int event);


  void init(std::string treename, std::string filename, int input_type=0);
  void set_tree_file(std::string treename, std::string filename, int input_type=0);

  /// retrieve jet algorithm variables in the current tree. Fill the m_names array
  void retrieve_algs();
  /// Retrieve the jet moment variables for algorithm alg_name
  std::vector<std::string> get_alg_moments(std::string alg_name);
  
  std::vector<std::string> getAlgNames() ;
  size_t get_num_algs() {return m_jetreaders.size();}

  std::string get_alg_name(int i) {return m_jetreaders[i]->name();}
  int get_numevents() {return m_nEvents;}

  void set_input_name();
  void set_input_name(std::string n) {m_input_name = n;}
  void set_input_isGeV(bool isGeV) {m_input_isGeV = isGeV;}
  bool get_input_isGeV() {return m_input_isGeV;}
  void set_inputvar_names(std::string v1, std::string v2, std::string v3, std::string v4) {m_input_v1 = v1; m_input_v2 = v2; m_input_v3 = v3; m_input_v4 = v4;}
  void set_jetvar_names(std::string v1, std::string v2, std::string v3, std::string v4) {m_jet_v1 = v1; m_jet_v2 = v2; m_jet_v3 = v3; m_jet_v4 = v4;}

  std::vector<SpartyJet::IJetCollReader*> get_jetreaders() {return m_jetreaders;}
  IJetCollReader* get_inpureader() {return m_inputreader;}

  TTree* get_tree() {return m_tree;}

  int test_first_event();

  void add_jetcoll_reader(std::string name, bool alsosetname=false);
  int get_current_event() {return m_currentEvent;}
  
protected:
  std::vector<IJetCollReader*> m_jetreaders;
  IJetCollReader* m_inputreader;

  void init_inputReader(IJetCollReader* reader);


  std::string m_treename;
  std::string m_filename;
  int m_nAlgs;

  int m_input_type;

  TFile* m_file;
  TTree* m_tree;
  int m_nEvents;
  std::vector<std::string> m_names;
  std::string m_input_name;
  bool m_input_isGeV;
  std::string m_input_v1, m_input_v2, m_input_v3, m_input_v4;
  std::string m_jet_v1, m_jet_v2, m_jet_v3, m_jet_v4;

  int m_currentEvent;
};

}  // namespace SpartyJet
#endif
