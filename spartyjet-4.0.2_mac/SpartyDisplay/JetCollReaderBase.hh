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

#ifndef _JETCOLLREADERBASE_H
#define _JETCOLLREADERBASE_H

#include "JetCore/JetCollection.hh"
#include "JetCore/FourVecCollection.hh"
#include "JetInputCollection.hh"

#include "TTree.h"

#include <string>
#include <vector>
#include <iostream>


namespace SpartyJet { 

class IJetCollReader {
public:
  virtual ~IJetCollReader() {}
  virtual void fill_collection(JetCollection& JetColl) = 0;
  
  virtual void fill_inputIndices(std::vector<int>& ind_vect, int num_input) = 0;
  virtual void fill_constituents(JetCollection& jets, JetInputCollection& constits) = 0;
  
  virtual void init(TTree* tree)= 0 ;

  virtual void set_var_names(std::string v1, std::string v2, std::string v3, std::string v4) = 0;

  virtual void set_name(std::string name) = 0;
  virtual std::string name() = 0;
  
  virtual void GetEntry(int i) = 0;
  
  virtual void set_reject_bad_input(bool) = 0;

};

#define NMAXJETS  10000
template<class BType, class BIndex>
class EtaPhiPtEReader_index : public EtaPhiPtECollection<BType>, public IJetCollReader {
public:
  EtaPhiPtEReader_index(TString base, TString suffix="") : EtaPhiPtECollection<BType> (base, suffix) {
    this->m_prefix += "_"; // Needed for gui !!
    this->set_var_names("eta", "phi", "pt", "e");
    this->set_n_name("N");
    m_ind.set_name(this->m_prefix + "ind" + this->m_suffix);
    this->add_var( &m_ind );
  }

  void set_ind_name(TString n) {m_ind.set_name(this->m_prefix + "ind" + this->m_suffix);}
  
  virtual void fill_collection(JetCollection& JetColl) {
    this->EtaPhiPtECollection<BType>::fill_collection(JetColl.jet_list());
  }
  
  virtual void fill_inputIndices(std::vector<int>& ind_vect, int num_input) {
    ind_vect.resize(num_input);
    for (int i = 0; i< num_input; i++) {ind_vect[i] = m_ind[i];}
  }
  
  virtual void fill_constituents(JetCollection& jets, JetInputCollection& constits) {
    // assume input collection has been correctly filled before
    size_t nconstit = constits.size();
    for (size_t i = 0; i < nconstit; i++) {
      if (m_ind[i] > -1) {
        *jets[m_ind[i]] = join(*jets[m_ind[i]], *constits[i]);
      }
    }
  }

  virtual void set_var_names(std::string v1, std::string v2, std::string v3, std::string v4) {
    this->EtaPhiPtECollection<BType>::set_var_names(v1, v2, v3, v4);
  }  
  virtual void init(TTree* tree) {this->SetBranchAddress(tree);} 
  virtual void set_name(std::string name) {this->m_prefix = name.c_str();}
  virtual std::string name() {return std::string((const char*)this->m_prefix);}

  virtual void GetEntry(int i) {this->EtaPhiPtECollection<BType>::GetEntry(i);}
  
  virtual void set_reject_bad_input(bool b) {this->EtaPhiPtECollection<BType>::set_reject_bad_input(b);}
  
protected:
  BIndex m_ind;
};


/// version with no index storage -- for the input collection
template<class BType>
class EtaPhiPtEReader : public EtaPhiPtECollection<BType>, public IJetCollReader {
public:
  EtaPhiPtEReader(TString base, TString suffix="") : EtaPhiPtECollection<BType> (base, suffix) {
    this->m_prefix += "_"; // Needed for gui !!
    this->set_var_names("eta", "phi", "pt", "e");
    this->set_n_name("N");
  }
  
  virtual void fill_collection(JetCollection& JetColl) {
    this->EtaPhiPtECollection<BType>::fill_collection(JetColl.jet_list());
  }
  
  virtual void fill_inputIndices(std::vector<int>& ind_vect, int num_input) {
    std::cout << "Error: Should not call fill_inputIndices for the input collection!\n";
  }
  
  virtual void fill_constituents(JetCollection& jets, JetInputCollection& constits) {
    std::cout << "Error: Should not call fill_constituents for the input collection!\n";    
  }

  virtual void set_var_names(std::string v1, std::string v2, std::string v3, std::string v4) {
    this->EtaPhiPtECollection<BType>::set_var_names(v1, v2, v3, v4);
  }  
  virtual void init(TTree* tree) {this->SetBranchAddress(tree);} 
  virtual void set_name(std::string name) {this->m_prefix = name.c_str();}
  virtual std::string name() {return std::string((const char*)this->m_prefix);}

  virtual void GetEntry(int i) {this->EtaPhiPtECollection<BType>::GetEntry(i);}
  
  virtual void set_reject_bad_input(bool b) {this->EtaPhiPtECollection<BType>::set_reject_bad_input(b);}
};


}  // namespace SpartyJet
#endif
