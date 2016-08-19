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

#ifndef _JETINPUTMAKERNTUPLE_HH_
#define _JETINPUTMAKERNTUPLE_HH_



#include "JetCore/InputMaker.hh"
#include "JetCore/JetMoment.hh"
#include "JetCore/BranchWrap.hh"
#include "JetCore/CommonUtils.hh"

#include <string>
#include <cstdlib>

namespace SpartyJet {   

class NtupleInputMaker;
// *************************************************************
// NtupleInputBase
// A base class to read 4 vectors into SpartyJet.
// 
// It's an interface, don't use it. Use a derived class.
// *************************************************************
class NtupleInputBase : public InputMaker {
public:

  NtupleInputBase();
  virtual ~NtupleInputBase();
  virtual void init() {}
  virtual void setFileTree(std::string filename, std::string treename);
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index = 0) {}
  virtual bool fillNextInput(JetCollection &inputList, int start_index = 0);

  virtual void moveToEventN(int n) {m_currentEvnt = std::min(n, m_totalEvntN);}

  virtual void set_prefix(std::string s) {m_prefix = s;}
  virtual void set_suffix(std::string s) {m_suffix = s;}
  virtual void set_variables(std::string p1, std::string p2, std::string p3, std::string p0) {}
  virtual void set_n_name(std::string s) {m_s_n = s;}
  void read_pdgId(bool b) {m_readPdgId = b;}
  void set_pdgId_name(std::string s) {m_pdgId_name = s; m_readPdgId = true;}
  
  // This is experimental. Don't ship it by default.
  //virtual void doFastRead(int max_mem = 1000000){m_maxmem = max_mem;m_fastReading=true;};

  virtual TTree* get_tree() {return m_tree;}
  virtual TFile* get_file() {return m_f;}

protected:
  std::string m_prefix;
  std::string m_suffix;
  int m_totalEvntN;

  int m_n;
  TBranch* m_b_n;
  std::string m_s_n;
  bool m_readPdgId;
  std::string m_pdgId_name;

  TTree* m_tree;  
  TFile* m_f;


  //bool m_fastReading;
  int m_maxmem;
};



// *************************************************************
// NtupleInputMaker
// A generic class to read 4 vectors into SpartyJet.
// 
// This class is intended to be a wrapper for internal
// templated class. The reason is that rootcint doesn't handle
// correctly templates. This also allows to give a unique interface to
// the user.
// *************************************************************
class IFourVecCollection;

class NtupleInputMaker : public NtupleInputBase {
public:

  // enumerate different ways input can be stored in a ROOT file
  enum NtupleInputType { 
    PxPyPzE_vector_double = 0,  
    PxPyPzE_vector_float,
    PxPyPzE_array_double,
    PxPyPzE_array_float,
    EtaPhiPtE_vector_double,  
    EtaPhiPtE_vector_float,
    EtaPhiPtE_array_double,
    EtaPhiPtE_array_float,
    EtaPhiPtM_vector_double,
    EtaPhiPtM_vector_float,
    EtaPhiPtM_array_double,
    EtaPhiPtM_array_float,
    EtaPhiPt_vector_double,
    EtaPhiPt_vector_float,
    EtaPhiPt_array_double,
    EtaPhiPt_array_float
  } ;

  //NtupleInputMaker(NtupleInputType t = PxPyPzE_vector_double);
  NtupleInputMaker(int input_type = PxPyPzE_vector_double); // we use a int because of enum bug in ROOT 5.18
  ~NtupleInputMaker();

  // Wrap all base functions
  virtual void Constructor(NtupleInputType t); // generic constructor called by other constructors
  virtual void init();
  virtual void fillInput(int eventn, JetCollection &inputList, int start_index=0);
  
  virtual void set_prefix(std::string s);
  virtual void set_suffix(std::string s);
  virtual void set_variables(std::string p1, std::string p2, std::string p3, std::string p0="E");
  virtual void set_n_name(std::string s);
  virtual void init_collection(JetCollection &coll);

  /// If input is in the form EtaPhiPtE one can set massless mode to true. In this case only Eta,Phi and E variables will be used
  void set_masslessMode(bool m);
  
  void reject_bad_input(bool v);


protected:
  IFourVecCollection* m_actualInput;
  BranchWrap_vector<int>* m_pdgIdVec; 
  BranchWrap_array<int, 15000> * m_pdgIdArr; 
};


// A simple wrapper for Delphes output files; right now just reads calorimeter
//  info (eta, phi, E, m=0)
class DelphesInputMaker : public NtupleInputMaker {
public:
  DelphesInputMaker(std::string filename) : NtupleInputMaker(EtaPhiPtE_array_float) {
    setFileTree(filename, "Analysis");
    set_masslessMode(true);
    set_n_name("CaloTower"); // set this before setting prefix
    set_prefix("CaloTower.");
    set_variables("Eta", "Phi", "ET", "E");
  }
  void init() {
    m_tree->SetMakeClass(1); // allows access to sub-object branches, I think
                             //  see TBranchElement::SetAddress(void*)
    NtupleInputMaker::init();
  }

};

}  // namespace SpartyJet
#endif
