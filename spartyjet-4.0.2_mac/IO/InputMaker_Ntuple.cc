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

#include "InputMaker_Ntuple.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/FourVecCollection.hh"

#include "TFile.h"
#include "TTree.h"
#include <vector>

namespace SpartyJet { 

NtupleInputBase::NtupleInputBase()  : InputMaker() {
  m_log.set_name("NtupleInputMaker");
  m_tree = 0; m_f = 0; 
  m_prefix = ""; m_suffix="";
  m_totalEvntN = 0;
  //  m_fastReading=false;
}

NtupleInputBase::~NtupleInputBase() {
  if (m_tree) delete m_tree;
  if (m_f) delete m_f;
}

bool NtupleInputBase::fillNextInput(JetCollection &inputList, int start_index){
  if (m_currentEvnt >= m_totalEvntN) return false;
  fillInput(m_currentEvnt, inputList, start_index);
  m_currentEvnt++;
  return true;
}

void NtupleInputBase::setFileTree(std::string filename, std::string treename) {
//   if(m_tree) delete m_tree;
//   if(m_f) {m_f->Close(); delete m_f;}
  m_f = TFile::Open(filename.c_str());  
  m_tree = (TTree*) m_f->Get(treename.c_str());
  if (!m_tree) {
    m_log << ERROR << "Could not find tree "<< treename << "  in file "<< filename<<std::endl;
  }
  m_totalEvntN = m_tree->GetEntries();
}



//NtupleInputMaker::NtupleInputMaker(NtupleInputType t){
NtupleInputMaker::NtupleInputMaker(int t) {
  m_name = "NtupleInput";
  m_readPdgId = false;
  m_pdgId_name = "pdgId";
  m_pdgIdArr = 0;
  if (t==0||t==1||t==4||t==5||t==8||t==9) {
    m_pdgIdVec = new BranchWrap_vector<int>("");
    m_pdgIdArr = NULL;
  } else {
    m_pdgIdArr = new BranchWrap_array<int,15000>("");
    m_pdgIdVec = NULL;
  }
  Constructor((NtupleInputType)t);
}

void NtupleInputMaker::set_masslessMode(bool m) {m_actualInput->set_massless(m);}
void NtupleInputMaker::set_prefix(std::string s) {m_actualInput->set_prefix(s); m_prefix=s;}
void NtupleInputMaker::set_suffix(std::string s) {m_actualInput->set_suffix(s); m_suffix=s;}
void NtupleInputMaker::set_variables(std::string p1,std::string p2,std::string p3,std::string p0)
  {m_actualInput->set_var_names(p1,p2,p3,p0);}
void NtupleInputMaker::set_n_name(std::string s) {m_actualInput->set_n_name(s);}


void NtupleInputMaker::fillInput(int eventn, JetCollection &inputList, int start_index) {
  int entry = m_tree->LoadTree(eventn);
  m_actualInput->fill_collection(entry, inputList.jet_list(), start_index);

  if (m_readPdgId) {
    JetMomentMap *map = inputList.get_JetMomentMap();
    JetCollection::iterator it = inputList.begin()+start_index;
    JetCollection::iterator itE = inputList.end();
    int jj=0;
    
    if (m_pdgIdVec) m_pdgIdVec->GetEntry(eventn);
    else if (m_pdgIdArr) m_pdgIdArr->GetEntry(eventn);
    
    for (; it != itE; ++it) {
      if(m_pdgIdVec) 		map->set_jet_moment("pdgId", *it , (*m_pdgIdVec)[jj]);
      else if(m_pdgIdArr) map->set_jet_moment("pdgId", *it , (*m_pdgIdArr)[jj]);
      jj++;
    }
  }
}
  
void NtupleInputMaker::init() {
  m_actualInput->SetBranchAddress(m_tree);
  if (m_readPdgId) 
  {
    TString branchName = m_prefix+m_pdgId_name;
    if (!m_tree->GetBranchStatus(branchName))
    {
      m_log << ERROR << "PDGID branch: " << branchName << " does not exist." << std::endl;
      exit (1);
    }
    
    if (m_pdgIdVec)
    {
      m_pdgIdVec->set_name(branchName);
      m_pdgIdVec->SetBranchAddress(m_tree);
    }
    else if (m_pdgIdArr)
    {
      m_pdgIdArr->set_name(branchName);
      m_pdgIdArr->SetBranchAddress(m_tree);
    }
    else m_log << ERROR << "PdgId variable not initialized correctly" << std::endl;
  }
}
  
void NtupleInputMaker::init_collection(JetCollection &coll) {
  if (m_readPdgId) coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
}

void NtupleInputMaker::reject_bad_input(bool v) {
  m_reject_bad_input = v;
  m_actualInput->set_reject_bad_input(v);
}

void NtupleInputMaker::Constructor(NtupleInputType t) {
  m_log.set_name("NtupleInputMaker");
  switch (t) {
    case PxPyPzE_vector_double:
      m_actualInput = new PxPyPzECollection< BranchWrap_vector< double > >("");
      break;
    case PxPyPzE_array_double:
      m_actualInput = new PxPyPzECollection< BranchWrap_array< double, 15000 > >("");
      break;
    case PxPyPzE_vector_float:
      m_actualInput = new PxPyPzECollection< BranchWrap_vector< float > >("");
      break;
    case PxPyPzE_array_float:
      m_actualInput = new PxPyPzECollection< BranchWrap_array< float, 15000 > >("");
      break;
    case EtaPhiPtE_vector_double:
      m_actualInput = new EtaPhiPtECollection< BranchWrap_vector< double > >("");
      break;
    case EtaPhiPtE_array_double:
      m_actualInput = new EtaPhiPtECollection< BranchWrap_array< double, 15000 > >("");
      break;
    case EtaPhiPtE_vector_float:
      m_actualInput = new EtaPhiPtECollection< BranchWrap_vector< float > >("");
      break;
    case EtaPhiPtE_array_float:
    	m_actualInput = new EtaPhiPtECollection< BranchWrap_array< float, 15000 > >("");
    	break;
    case EtaPhiPtM_vector_double:
      m_actualInput = new EtaPhiPtMCollection< BranchWrap_vector< double > >("");
      break;
    case EtaPhiPtM_array_double:
      m_actualInput = new EtaPhiPtMCollection< BranchWrap_array< double, 15000 > >("");
      break;
    case EtaPhiPtM_vector_float:
      m_actualInput = new EtaPhiPtMCollection< BranchWrap_vector< float > >("");
      break;
    case EtaPhiPtM_array_float:
      m_actualInput = new EtaPhiPtMCollection< BranchWrap_array< float, 15000 > >("");
      break;
    case EtaPhiPt_vector_double:
      m_actualInput = new EtaPhiPtCollection< BranchWrap_vector< double > >("");
      break;
    case EtaPhiPt_array_double:
      m_actualInput = new EtaPhiPtCollection< BranchWrap_array< double, 15000 > >("");
      break;
    case EtaPhiPt_vector_float:
      m_actualInput = new EtaPhiPtCollection< BranchWrap_vector< float > >("");
      break;
    case EtaPhiPt_array_float:
      m_actualInput = new EtaPhiPtCollection< BranchWrap_array< float, 15000 > >("");
      break;
    default:
      m_actualInput = 0;
      m_log <<  " WARNING unknown NtupleInputType !!  " << std::endl;
      break;
  }
  unitIsGeV(); // SpartyJet default
}

NtupleInputMaker::~NtupleInputMaker() {
  if (m_actualInput) delete m_actualInput;
}


}  // namespace SpartyJet
