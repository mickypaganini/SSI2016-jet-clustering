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

#ifndef SJ_FOURVECCOLLECTION_h
#define SJ_FOURVECCOLLECTION_h

#include "Jet.hh"
#include "BranchWrap.hh"

#include "TTree.h"
#include "TString.h"

#include <vector>
#include <iostream>
#include <list>

namespace SpartyJet {

typedef std::list<BranchWrap*> branchlist_base_t;

////////////////////////////////////////////////////////////////
/// \class IFourVecCollection 
/// \brief an interface to represent a collection of 4vec stored as flat variables in a TTree
///
/// An interface to represent a collection of 4vec stored as flat variables in a TTree
/// It provide functions to set the name of the TTree variables
/// To associate variable addresses with TBranches (SetBranchAddress)
/// to read the the collection from TTree (fill_collection)
////////////////////////////////////////////////////////////////
class IFourVecCollection {
public:
  virtual ~IFourVecCollection() {}
  virtual void set_prefix(TString p) = 0;
  virtual void set_suffix(TString s) = 0;
  virtual void set_n_name(TString s) = 0;
  virtual void set_var_names(TString v1, TString v2, TString v3, TString v4) = 0;
  virtual void add_var(TString name) = 0;
  virtual void set_massless(bool m) = 0;
  virtual void set_mass(double M) = 0;
  virtual void set_reject_bad_input(bool m) = 0;
  virtual void SetBranchAddress(TTree* t ) = 0;
  virtual void GetEntry(int i) = 0;
  
  virtual void fill_collection(Jet::jet_list_t& inputList, int start_index=0) = 0;
  virtual void fill_collection(int eventn, Jet::jet_list_t& inputList, int start_index=0) = 0;

protected:
  static bool check_4vector(const Jet* j);
};


////////////////////////////////////////////////////////////////
/// \class FourVecCollection 
/// \brief A templated generic implementation of IFourVecCollection
///
/// A templated generic implementation of IFourVecCollection.
/// The template parameter BType is expected to be BranchWrap_array 
///  or BranchWrap_vector
////////////////////////////////////////////////////////////////
template<class BType>
class FourVecCollection : public branchlist_base_t, public IFourVecCollection{
public:
  FourVecCollection(TString prefix, TString suffix="") : branchlist_base_t() ,m_prefix(prefix), m_suffix(suffix) {
    push_back(&m_n);
    m_n.set_name(prefix+"N"+suffix);
    push_back(&m_v1); push_back(&m_v2); push_back(&m_v3); push_back(&m_v4);
    m_masslessMode = false;
    m_userMass = 0.;
    m_reject_bad_input = true;
  }
  virtual ~FourVecCollection() {}

  void set_prefix(TString p) {m_prefix = p;}
  void set_suffix(TString s) {m_suffix = s;}
  void set_n_name(TString s) {m_n.set_name(m_prefix+s+m_suffix);}
  void set_var_names(TString v1, TString v2, TString v3, TString v4) {
    m_v1.set_name(m_prefix+v1+m_suffix);
    m_v2.set_name(m_prefix+v2+m_suffix);
    m_v3.set_name(m_prefix+v3+m_suffix);
    m_v4.set_name(m_prefix+v4+m_suffix);
  }

  void add_var(TString name)   {push_back(static_cast<BranchWrap*>(new BType(name)));}
  void add_var(BranchWrap* bw) {push_back(bw);}

  virtual void set_massless(bool m)         {m_masslessMode = m;}    
  virtual void set_mass(double M)           {m_userMass = M;}
  virtual void set_reject_bad_input(bool m) {m_reject_bad_input = m;}

  virtual void SetBranchAddress(TTree* t) {
    branchlist_base_t::iterator it = begin(), itE = end();
    for (; it != itE; ++it) (*it)->SetBranchAddress(t);
  }

  virtual void GetEntry(int i) {
    branchlist_base_t::iterator it = begin(), itE = end();
    for (; it != itE; ++it) (*it)->GetEntry(i);
  }

  
  virtual void fill_collection(Jet::jet_list_t& inputList, int start_index=0) {}
  virtual void fill_collection(int eventn, Jet::jet_list_t& inputList, int start_index=0) {
    this->GetEntry(eventn);
    this->fill_collection(inputList, start_index);
  }

  TString m_prefix;
  TString m_suffix;
  BranchWrap_simple<int> m_n;
  
  bool m_masslessMode;
  double m_userMass;
  bool m_reject_bad_input;
  BType m_v1;
  BType m_v2;
  BType m_v3;
  BType m_v4;
};


////////////////////////////////////////////////////////////////
/// \class EtaPhiPtECollection
/// \brief FourVecCollection where the variables are eta,phi,pt,e
///
/// FourVecCollection where the variables are eta,phi,pt,e
////////////////////////////////////////////////////////////////
template<class BType>
class EtaPhiPtECollection : public FourVecCollection<BType>  {
public:
  EtaPhiPtECollection(TString base, TString suffix="") : FourVecCollection<BType>(base, suffix) {
    this->set_var_names("Eta", "Phi", "Pt", "E");
  }
  
  virtual void fill_collection( Jet::jet_list_t& inputList, int start_index=0) {
    BType& eta = this->m_v1; BType& phi = this->m_v2; BType& pt = this->m_v3; BType& e = this->m_v4;
    int index = start_index;
    
    // Safe to use take number of input particles from var size?
    int N = 0;
    if (is_vector_type<BType>()) N = this->m_v1.size();
    else                         N = this->m_n;

    for (int i = 0; i < N; i++) {
      double pti;
      if (this->m_masslessMode) pti = e[i]/cosh(eta[i]);
      else                      pti = pt[i];
      double px = pti * cos(phi[i]);
      double py = pti * sin(phi[i]);
      double pz = pti * sinh(eta[i]);
      
      Jet* j = new Jet(px, py, pz, e[i], index);  
      if (!this->m_reject_bad_input || this->check_4vector(j)) {
        inputList.push_back(j);
        index++;
      } else delete j;
    }
  } 
};


////////////////////////////////////////////////////////////////
/// \class PxPyPzECollection
/// \brief FourVecCollection where the variables are px,py,pz,e
///
/// FourVecCollection where the variables are px,py,pz,e
////////////////////////////////////////////////////////////////
template<class BType>
class PxPyPzECollection : public FourVecCollection<BType>  {
public:
  PxPyPzECollection(TString base,TString suffix="") : FourVecCollection<BType>(base, suffix) {
    this->set_var_names("Px", "Py", "Pz", "E");
  }
  
  virtual void fill_collection( Jet::jet_list_t &inputList, int start_index =0 ) {
    BType& px = this->m_v1; BType& py = this->m_v2; BType& pz = this->m_v3; BType& e = this->m_v4;
    int index = start_index;

    // Safe to use take number of input particles from var size?
    int N = 0;
    if (is_vector_type<BType>()) N = this->m_v1.size();
    else                         N = this->m_n;

    for (int i = 0; i < N; i++) {
      Jet* j = new Jet(px[i], py[i], pz[i], e[i], index);
      if (!this->m_reject_bad_input || this->check_4vector(j)) {
        inputList.push_back(j);
        index++;
      } else delete j;
    }
  }
};


////////////////////////////////////////////////////////////////
/// \class EtaPhiPtMCollection
/// \brief FourVecCollection where the variables are eta,phi,pt,m
///
/// FourVecCollection where the variables are eta,phi,pt,m
////////////////////////////////////////////////////////////////
template<class BType>
class EtaPhiPtMCollection : public FourVecCollection<BType>  {
public:
  EtaPhiPtMCollection(TString base,TString suffix="") : FourVecCollection<BType>(base, suffix) {
    this->set_var_names("Eta", "Phi", "Pt", "M");
  }
  
  virtual void fill_collection( Jet::jet_list_t &inputList, int start_index = 0) {
    BType& eta = this->m_v1; BType& phi = this->m_v2; BType& pt = this->m_v3; BType& m = this->m_v4;
    int index = start_index;

    // Safe to use take number of input particles from var size?
    int N = 0;
    if (is_vector_type<BType>()) N = this->m_v1.size();
    else                         N = this->m_n;

    for (int i = 0; i < N; i++) {
      if (fabs(eta[i]) > 500) continue; // this will produce nan
      
      double px = pt[i] * cos(phi[i]);
      double py = pt[i] * sin(phi[i]);
      double pz = pt[i] * sinh(eta[i]);
      double p  = pt[i] * cosh(eta[i]);
      double e  = sqrt(p*p + m[i]*m[i]);
      
      Jet* j = new Jet(px, py, pz, e, index);  
      if (!this->m_reject_bad_input || this->check_4vector(j)) {
        inputList.push_back(j);
        index++;
      } else delete j;
    }
  }
};


////////////////////////////////////////////////////////////////
/// \class EtaPhiPtCollection
/// \brief FourVecCollection where the variables are eta,phi,pt
///
/// FourVecCollection where the variables are eta,phi,pt
////////////////////////////////////////////////////////////////
template<class BType>
class EtaPhiPtCollection : public FourVecCollection<BType>  {
public:
  EtaPhiPtCollection(TString base,TString suffix="") : FourVecCollection<BType>(base, suffix) {
    this->set_var_names("Eta", "Phi", "Pt", "M");
  }
  
  virtual void fill_collection( Jet::jet_list_t &inputList, int start_index = 0) {
    BType& eta = this->m_v1; BType& phi = this->m_v2; BType& pt = this->m_v3;
    double m = this->m_userMass;
    int index = start_index;

    // Safe to use take number of input particles from var size?
    int N = 0;
    if (is_vector_type<BType>()) N = this->m_v1.size();
    else                         N = this->m_n;

    for (int i = 0; i < N; i++) {
      if (fabs(eta[i]) > 500) continue; // this will produce nan
      
      double px = pt[i] * cos(phi[i]);
      double py = pt[i] * sin(phi[i]);
      double pz = pt[i] * sinh(eta[i]);
      double p  = pt[i] * cosh(eta[i]);
      double e  = sqrt(p*p + m*m);
      
      Jet* j = new Jet(px,py,pz,e,index);  
      if (!this->m_reject_bad_input || this->check_4vector(j)) {
        inputList.push_back(j);
        index++;
      } else delete j;
    }
  }
};

}

#endif
