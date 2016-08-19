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

#ifndef SJ_BRANCHWRAP_h
#define SJ_BRANCHWRAP_h

#include "CommonUtils.hh"
#include "JetMoment.hh"

#include "TTree.h"
#include "TString.h"

#include <vector>
#include <iostream>

/////////////////////////////////////////////////////////
/// \class BranchWrap
///
/// This class abstract the TBranch in order to provide a 
/// unique interface to TBranch::SetBranchAddress (set-up for reading) and 
/// TBranch::Branch (set-up for writing)
/// The derived classes of BranchWrap implement the concrete
/// type of the TTree variable, holding an object of this type
/// ex : vector<double> or float or ...
/////////////////////////////////////////////////////////

namespace SpartyJet {

class BranchWrap {
public:
  BranchWrap(TString n="") : m_b(0), m_name(n) {}
  virtual ~BranchWrap() {}
  
  virtual void SetBranchAddress(TTree* t) {}
  virtual void registerBranch(TTree* t) {}
  virtual void resize(int i) {} ///< needed for derived class using vectors
  
  int     GetEntry(int i)         {return (m_b ? m_b->GetEntry(i) : 0);}
  void    set_name(TString n)     {m_name = n;}
  void    set_name(std::string n) {m_name = n.c_str();}
  TString get_name()              {return m_name;}
  
protected:
  TBranch* m_b;
  TString  m_name;
};

class BranchWrap1D : public BranchWrap {
public:
  BranchWrap1D(TString n="") : BranchWrap(n), m_refN(0) {}
  virtual ~BranchWrap1D() {}
  
  TString get_refN_name() {return (m_refN ? m_refN->get_name() : "");}
  
  void set_refN(BranchWrap* b) {m_refN = b;}

protected:
  BranchWrap* m_refN;
};


template<class T>
class BranchWrap_vector : public BranchWrap1D {
public:
  BranchWrap_vector(TString n="") : BranchWrap1D(n), m_vec(0) {}
  virtual ~BranchWrap_vector() {if (m_vec) {m_vec->clear();  delete m_vec;}}
  
  T& operator[](int i) {return (*m_vec)[i];}
  
  int size()     {return m_vec->size();}
  int size_max() {return 999999999;}
  
  virtual void SetBranchAddress(TTree* t) {
    m_b = t->GetBranch(m_name);
    if (m_b) t->SetBranchAddress(m_name , &m_vec);
    else std::cout << " WARNING !! no TBranch named : " << m_name << std::endl;
  }
  
  virtual void registerBranch(TTree* t) {m_b = t->Branch(m_name, &m_vec);}
  
  virtual void resize(int i) {m_vec->resize(i);}

protected:
  std::vector<T>* m_vec;
};


class IBranchWrap_JetMoment : public BranchWrap1D {
public:
  IBranchWrap_JetMoment(TString n="") : BranchWrap1D(n) {}
  virtual ~IBranchWrap_JetMoment() {}
  virtual void LoadMoment(const Moment* m, int i) = 0;
};


template<class T>
class BranchWrap_JetMoment : public IBranchWrap_JetMoment {
public:
  BranchWrap_JetMoment(TString n="") : IBranchWrap_JetMoment(n), m_vec(0) {}
  virtual ~BranchWrap_JetMoment() {if (m_vec) {m_vec->clear();  delete m_vec;}}
  
  T& operator[](int i) {return (*m_vec)[i];}
  virtual void LoadMoment(const Moment *m, int i) {
    const JetMoment<T>* jm = dynamic_cast<const JetMoment<T>*>(m);
    if (jm) (*m_vec)[i] =  jm->GetValue();
  }
  
  int size()     {return m_vec->size();}
  int size_max() {return 999999999;}
  
  virtual void SetBranchAddress(TTree* t) {
    m_b = t->GetBranch(m_name);
    if (m_b) t->SetBranchAddress(m_name, &m_vec);
    else std::cout << " WARNING !! no TBranch named : " << m_name  << std::endl;
  }
  
  virtual void registerBranch(TTree* t) {m_b = t->Branch(m_name, &m_vec);}
  
  virtual void resize(int i) {m_vec->clear(); m_vec->resize(i);}

protected:
  std::vector<T>* m_vec;
};


template<class T> TString get_type_string()      {return "";}
template<class T> TString get_type_stringLong()  {return "";}
template<> inline TString get_type_string<float>()      {return "F";}
template<> inline TString get_type_string<int>()        {return "I";}
template<> inline TString get_type_string<double>()     {return "D";}
template<> inline TString get_type_stringLong<float>()  {return "float";}
template<> inline TString get_type_stringLong<int>()    {return "int";}
template<> inline TString get_type_stringLong<double>() {return "double";}


template<class T, int N_T=100>
class BranchWrap_array : public BranchWrap1D {
public:
  
  BranchWrap_array(TString name="") : BranchWrap1D(name) {}
  virtual ~BranchWrap_array() {}
  
  T& operator[](int i) {return m_vec[i];}
  
  int size()     {return N_T;}
  int size_max() {return N_T;}
  
  virtual void SetBranchAddress(TTree* t) {
    t->SetBranchAddress(m_name, m_vec);
    m_b = t->GetBranch(m_name);
    if (!m_b) std::cout << " WARNING !! no TBranch named : " << m_name << std::endl;
  }
  
  virtual void registerBranch(TTree* t) {
    // build the type as in e.g. "myvar[150]/F"
    TString refname = get_refN_name();
    if (refname == "") refname += N_T;
    TString type = m_name + "[" + refname + "]/" + get_type_string<T>();
    m_b = t->Branch(m_name, m_vec, type);
  }

protected:  
  T m_vec[N_T];
};


template<class T>
class BranchWrap_simple : public BranchWrap {
public:
  BranchWrap_simple(TString n="") : BranchWrap(n) {}
  virtual ~BranchWrap_simple() {}
  
  void operator=(T v) {m_val = v;}
  operator T&(void)  {return m_val;}
  
  virtual void SetBranchAddress(TTree* t) {
    t->SetBranchAddress(m_name , &m_val, &m_b); 
    if (!m_b) std::cout << "WARNING:  No TBranch named : " << m_name << std::endl;
  }
  
  virtual void registerBranch(TTree *t){
    // build the type as in e.g. "myvar[150]/F"
    TString type = m_name + "/" + get_type_string<T>();
    m_b = t->Branch(m_name, &m_val, type);
  }

protected:
  T m_val;
};


template<class T> bool is_basic_type()               {return false;}
template<class T> bool is_vector_type()              {return false;}
template <> inline bool is_basic_type<char>()               {return true;}
template <> inline bool is_basic_type<int>()                {return true;}
template <> inline bool is_basic_type<float>()              {return true;}
template <> inline bool is_basic_type<double>()             {return true;}
template <> inline bool is_basic_type<bool>()               {return true;}
template <> inline bool is_basic_type<short int>()          {return true;}
template <> inline bool is_basic_type<long int>()           {return true;}
template <> inline bool is_basic_type<long double>()        {return true;}
template <> inline bool is_basic_type<unsigned char>()      {return true;}
template <> inline bool is_basic_type<unsigned int>()       {return true;}
template <> inline bool is_basic_type<unsigned short int>() {return true;}
template <> inline bool is_basic_type<unsigned long int>()  {return true;}
template <> inline bool is_basic_type<signed char>()        {return true;}
template <> inline bool is_vector_type<SpartyJet::BranchWrap_vector< double > >() {return true;}
template <> inline bool is_vector_type<SpartyJet::BranchWrap_vector< float > >()  {return true;}
template <> inline bool is_vector_type<SpartyJet::BranchWrap_array< double > >()  {return false;}
template <> inline bool is_vector_type<SpartyJet::BranchWrap_array< float > >()   {return false;}


/// This branch class can wrap any class type T that ROOT has a dictionary for
///  Now also basic types!!
class IBranchWrap_EventMoment : public BranchWrap {
public:
  IBranchWrap_EventMoment(TString n="") : BranchWrap(n) {}
  virtual ~IBranchWrap_EventMoment() {}
  virtual void LoadMoment(const Moment* m) = 0;
};


template<class T>
class BranchWrap_EventMoment : public IBranchWrap_EventMoment {
public:
  BranchWrap_EventMoment(TString n="") : IBranchWrap_EventMoment(n) {m_val = new T;}
  virtual ~BranchWrap_EventMoment() {if(m_val) delete m_val;}
  
  void operator=(const T& v) {*m_val = v;}
  operator T&(void)          {return *m_val;}
  
  virtual void LoadMoment(const Moment* m) {
    const EventMoment<T>* em = dynamic_cast<const EventMoment<T>*>(m);
    if (em) *m_val = em->GetValue();
  }
  
  virtual void SetBranchAddress(TTree* t) {
    t->SetBranchAddress(m_name , &m_val, &m_b);
    if (!m_b) std::cout << " WARNING !! no TBranch named : "<< m_name  << std::endl;
  }
  
  virtual void registerBranch(TTree* t) {
    if (is_basic_type<T>()) {
      // build the type as in e.g. "myvar[150]/F"
      TString type = m_name + "/" + get_type_string<T>();
      m_b = t->Branch(m_name, m_val, type);
    } else
      m_b = t->Branch(m_name, &m_val);
  }

protected:
  T* m_val;
};


} // namespace SpartyJet

#endif
