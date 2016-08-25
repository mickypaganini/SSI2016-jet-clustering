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


#include "JetRetrieverFile.hh"
#include "JetCollExtended.hh"
#include "IO/InputMaker_Ntuple.hh"

#include <iostream>
#include <algorithm>
using namespace std;

namespace SpartyJet { 

JetRetrieverFile::JetRetrieverFile() {
  m_input_name = "";
  m_input_isGeV = false;
  m_inputreader = 0;
  m_input_v1 = "eta"; m_input_v2 = "phi"; m_input_v3 = "pt"; m_input_v4 = "e";
  m_jet_v1 = "eta"; m_jet_v2 = "phi"; m_jet_v3 = "pt"; m_jet_v4 = "e";
  m_currentEvent = -1;
  m_nEvents = 0;
}

void JetRetrieverFile::get_collection(JetInputCollection& jet_input_coll, JetCollExtended& jcoll, int numC, int entry) {
  int l_entry = m_tree->LoadTree(entry);
  if (entry != m_currentEvent) {
    l_entry=m_tree->LoadTree(entry);
    //int nb=m_tree->GetEntry(l_entry);
    m_currentEvent = entry;

    jet_input_coll.clear_and_delete();
    m_nAlgs = m_jetreaders.size();

    //jet_input_coll.m_algoIndices.resize(m_nAlgs);
    // Fill input 
    m_inputreader->GetEntry(l_entry);

    m_inputreader->fill_collection(jet_input_coll);
    //cout << "Loaded event "<< m_currentEvent << ".  N input psuedo jets: "<< jet_input_coll.size() << endl;
  }

  jcoll.clear_and_delete();

  //cout << numC << " Fillling collection " << m_jetreaders[numC]->name() << endl;
  m_jetreaders[numC]->GetEntry(l_entry);
  m_jetreaders[numC]->fill_collection(jcoll); // constituents are not filled yet
  m_jetreaders[numC]->fill_inputIndices(jcoll.m_algoIndices, jet_input_coll.size());
  m_jetreaders[numC]->fill_constituents(jcoll, jet_input_coll);
  //cout << numC << " Filled collection num=" << jcoll.size() << "  num ind=" << jcoll.m_algoIndices.size() << " input size=" << jet_input_coll.size() << endl;
}


void JetRetrieverFile::fill_inputColl(JetInputCollection& inputColl, int entry) {

  int l_entry=m_tree->LoadTree(entry);
  if (entry != m_currentEvent) {

    m_inputreader->GetEntry(l_entry);
    m_currentEvent = entry;
    cout << "Loading event "<< m_currentEvent << "  input size nb "<< inputColl.size() << endl;
    inputColl.clear_and_delete();
    inputColl.m_algoIndices.resize(m_jetreaders.size());
    //jet_coll_v.resize(Ncoll);

    // Fill input 
    m_inputreader->fill_collection(inputColl);
  }
}


void JetRetrieverFile::fill_collections(JetInputCollection& jet_input_coll, vector<JetCollExtended>& jet_coll_v, int entry) {

  // Load a new event :
  int l_entry=m_tree->LoadTree(entry);
  if (entry != m_currentEvent) {
    l_entry=m_tree->LoadTree(entry);
    //int nb=m_tree->GetEntry(l_entry);
    m_currentEvent = entry;
    cout << "Loaded event " << m_currentEvent << "  nb=" << endl;
  }

  // clean collections 
  size_t Ncoll = jet_coll_v.size();
  jet_input_coll.clear_and_delete();
  for (size_t i = 0; i < Ncoll; i++) jet_coll_v[i].clear_and_delete();
  
  // adapt size if necessary
  if (Ncoll != m_jetreaders.size()) {
    Ncoll = m_jetreaders.size();
  }
  jet_input_coll.m_algoIndices.resize(Ncoll);
  jet_coll_v.resize(Ncoll);

  // Fill input 
  m_inputreader->GetEntry(l_entry);
  m_inputreader->fill_collection(jet_input_coll);

  // Fill algs : 
  for (size_t i = 0; i < Ncoll; i++) {
    cout << i << " Fillling collection " << m_jetreaders[i]->name() << endl;
    m_jetreaders[i]->GetEntry(l_entry);
    m_jetreaders[i]->fill_collection(jet_coll_v[i]); // constituents are not filled yet
    m_jetreaders[i]->fill_inputIndices(jet_input_coll.m_algoIndices[i], jet_input_coll.size());
    m_jetreaders[i]->fill_constituents(jet_coll_v[i], jet_input_coll);
  }
}


int JetRetrieverFile::test_first_event() {
  m_tree->LoadTree(0);
  //m_tree->GetEntry(0);
  m_inputreader->GetEntry(0);
  cout << "test_first_event " << m_inputreader->name() << endl;
  JetCollection coll;
  
  m_inputreader->fill_collection(coll);  
  if (coll.size() > 0) return 0;
  else return 1;
}

vector<string> JetRetrieverFile::get_alg_moments(string alg_name) {
  int nbranches = m_tree->GetNbranches();
  TBranch* br;
  TString tempname;
  string tempstring;
  string name = alg_name+"_";

  vector<string> algmoments;

  for (int b = 0; b < nbranches; b++) {
    br = (TBranch*)m_tree->GetListOfBranches()->At(b);
    tempname = br->GetName();
    tempstring = tempname;
    //cout << "finding alg_moments, current branch : " << tempstring << endl;
    //cout << "the substring is " << tempstring.substr(0,alg_name.size()) << endl;
    if (tempstring.substr(0, name.size()) == name) {
      cout << "Found moment " << tempstring.substr(name.size()) << " for alg " << alg_name << std::endl;
      algmoments.push_back(tempstring.substr(name.size()));
    }
  }
  return algmoments;
}

void JetRetrieverFile::init(string treename, string filename, int input_type) {
  cout << " JetRetrieverFile initing " << treename << " in file "<< filename << endl;
  set_tree_file(treename, filename, input_type);

  retrieve_algs();

  set_input_name();
  cout << "input name is " << m_input_name << endl;
  cout << "input unit is " << ((m_input_isGeV) ? "GeV" : "MeV") << endl;
	cout << "Found nalgs =  " << m_names.size() << endl;

  m_nAlgs = m_names.size();
  for (int i = 0; i < m_nAlgs; i++) {
    cout << "Variable " << m_names[i] << endl;
    if (m_names[i] != m_input_name) add_jetcoll_reader(m_names[i]);
  }

}

void JetRetrieverFile::set_tree_file(string treename, string filename, int input_type) {
  m_file = new TFile(filename.c_str());
  if (m_file->IsZombie()) {
    cout << "JetRetrieverFile: Failed to open file " << filename << "!" << endl;
    exit(1);
  }
  m_tree = (TTree*)m_file->Get(treename.c_str());
  if (m_tree == 0) {
    cout << "JetRetrieverFile: Could not find TTree " << treename << " in file " << filename << "!" << endl;
    exit(1);
  }

  m_nEvents = m_tree->GetEntries();

  if(input_type == -1) input_type = (int) NtupleInputMaker::EtaPhiPtE_array_float;
  m_input_type = input_type;
  
  cout << " JetRetrieverFile set " << treename << " in file "<< filename << "  :  "<< m_tree <<  "   input type="<< m_input_type << endl;
}

void JetRetrieverFile::add_jetcoll_reader(string name, bool alsosetname) {
  typedef BranchWrap_array<int, NMAXJETS>   array_int;
  typedef BranchWrap_array<float>           array_float;
  typedef BranchWrap_array<float, NMAXJETS> array_float_big;
  typedef BranchWrap_vector<int>            vector_int;
  typedef BranchWrap_vector<float>          vector_float;

  if (alsosetname) m_names.push_back(name);

  IJetCollReader* reader = 0;
  switch (m_input_type) {
    case NtupleInputMaker::EtaPhiPtE_array_float: {    
      reader = new EtaPhiPtEReader_index<array_float, array_int>(name); 
      if (m_inputreader == 0) {
        init_inputReader(new EtaPhiPtEReader<array_float_big>(m_input_name));
      }
      break;
    }
    case NtupleInputMaker::EtaPhiPtE_vector_float: {    
      reader = new EtaPhiPtEReader_index<vector_float, vector_int>(name); 
      if (m_inputreader == 0) {
        init_inputReader(new EtaPhiPtEReader<vector_float>(m_input_name));
      }
      break;
    }
    default: break;
  }
  reader->set_reject_bad_input(false);
  reader->set_var_names(m_jet_v1, m_jet_v2, m_jet_v3, m_jet_v4);
  reader->init(m_tree);
  cout << "Adding Jet Collection: " << reader->name() << endl;
  m_jetreaders.push_back(reader);
}


void JetRetrieverFile::init_inputReader(IJetCollReader *reader){
  m_inputreader = reader;
  m_inputreader->set_reject_bad_input(false);
  m_inputreader->set_var_names(m_input_v1, m_input_v2, m_input_v3, m_input_v4);
  m_inputreader->init(m_tree);
}


void JetRetrieverFile::set_input_name() {  
  if (m_input_name == ""){
    if (m_names.size()==0) return; // in this case there is no point doing anything
    // test first name : 
    m_input_name = m_names[0];
    cout << "\n\nIs the input name \"" << m_input_name << "\"? (y/n)" << endl;
    char r; cin >> r;
    if (r == 'y' || r== 'Y') return; // we're done
    cout << "What is the input variable ? "<< endl;
    cin >> m_input_name;
		cout << "Are the units in GeV? (y => GeV, n => MeV)" << endl;
		cin >> r;
		m_input_isGeV = (r == 'y' || r== 'Y');
  }
}



void JetRetrieverFile::retrieve_algs() {

  m_nAlgs = 0;
  int nbranches = m_tree->GetNbranches();
  
  TBranch* br;
  
  map<string, int> var_branches;
  
  // Loop on branches
  for (int b = 0; b < nbranches; b++) {
    br = (TBranch*)m_tree->GetListOfBranches()->At(b);
    string tempstring(br->GetName());
    size_t p =  tempstring.find_last_of("_");
    if( p == string::npos ) continue;

    TString var_s(tempstring.substr(p + 1).c_str()); // get yy in xxx_yy
    var_s.ToLower();
    if (( var_s =="eta" ) || ( var_s =="phi" )) {
      string bname = tempstring.substr(0,p); // get xxx in xxx_yy
      // store xxx counting occurence
      if (var_branches.find(bname) == var_branches.end()) var_branches[bname] = 1; 
      else var_branches[bname] = 2;
    }
  }

  m_names.clear();
  map<string, int>::iterator it = var_branches.begin();
  for (; it != var_branches.end(); ++it){
    if ((*it).second > 1) m_names.push_back((*it).first);
  }
}



vector<string> JetRetrieverFile::getAlgNames() {
  vector<string> tmp;
  for (size_t i = 0; i < m_names.size(); i++) { 
    if (m_names[i] != m_input_name ) tmp.push_back(m_names[i]); 
  }
  return tmp;
} 
}; // namespace SpartyJet
