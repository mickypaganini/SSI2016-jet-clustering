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

#include "OutputVarUtils.hh"

#include "TTree.h"

#include <iostream>
using namespace std;

namespace SpartyJet {

JetVar_Names::JetVar_Names() {
  eta =  "eta";
  phi =  "phi";
  pt =  "pt";
  e  =   "e";
  mass = "mass";
  ind  = "ind" ;
  numC = "numC";
}

template<int NMAX>
IGenericJetVar* OutputVarFactory::_get_jet_var(string name, JetMomentMap* map, IGenericJetVar* inputvar, bool onlymoment) {

  // Give shortcut names to every possible output types :
  typedef JetVarIndex<BranchWrap_array<float, NMAX>, BranchWrap_array<int, NMAX*100> >  array_float_index;
  typedef JetVarIndex<BranchWrap_array<double, NMAX>, BranchWrap_array<int, NMAX*100> > array_double_index;
  typedef JetVarIndex<BranchWrap_vector<float>, BranchWrap_vector<int> >                vector_float_index;
  typedef JetVarIndex<BranchWrap_vector<double>, BranchWrap_vector<int> >               vector_double_index;

  typedef JetVar<BranchWrap_array<float, NMAX> >  array_float;
  typedef JetVar<BranchWrap_array<double, NMAX> > array_double;
  typedef JetVar<BranchWrap_vector<float> >       vector_float;
  typedef JetVar<BranchWrap_vector<double> >      vector_double;

  if (m_array_type == kArray) {
    if (m_base_type == kFloat) {
      if (onlymoment)
        return new GenericJetVar(name, map);
      if (inputvar)
        return prepare_input(new array_float_index(name,map), inputvar);
      else
        return new array_float(name, map);
    } else if (m_base_type == kDouble) {
      if (onlymoment)
        return new GenericJetVar(name, map);
      if (inputvar)
        return prepare_input(new array_double_index(name, map), inputvar);
      else
        return new array_double(name,map);
    } else {
      cout << " ERROR unknown base type " << m_base_type << " for output variables" << endl;
    }
  } else if (m_array_type == kVector) {
    if (m_base_type == kFloat) {
      if (onlymoment)
        return new GenericJetVar(name, map);
      if (inputvar)
        return prepare_input(new vector_float_index(name, map) , inputvar);
      else
        return new vector_float(name, map);
    } else if (m_base_type == kDouble) {
      if (onlymoment)
        return new GenericJetVar(name, map);
      if (inputvar)
        return prepare_input(new vector_double_index(name, map) , inputvar);
      else
        return new vector_double(name,map);
    } else {
      cout << " ERROR unknown base type " << m_base_type << " for output variables" << endl;
    }
  } else {
    cout << " ERROR unknown array type " << m_array_type << " for output variables" << endl;
  }
    
  cout << "OutputVarFactory not implemented yet for " << m_array_type << ", " << m_base_type << "!" << endl;
  return 0;
}

IGenericJetVar* OutputVarFactory::get_jet_var(string name, JetMomentMap* map, IGenericJetVar* inputvar, bool onlymoment) {
  return _get_jet_var<100>(name,map,inputvar, onlymoment);
}

IGenericJetVar* OutputVarFactory::get_inputjet_var(string name, JetMomentMap* map) {
  return _get_jet_var<10000>(name,map, NULL, false);
}


//****************************************************************************************
// New (simple) implementation

/// Schedule all generic variables (jet moment, jet moment array, event variable,..)
void GenericJetVar::schedule(TTree* tree) {
  this->set_name_register(N, "N", tree);
  if (!m_mmap) return;
  
  // schedule jet moments
  int nmom = m_mmap->num_jet_moment();
  m_jet_moment_vars.resize(nmom, NULL);

  const JetMomentMap::moment_store_t& moments = m_mmap->get_jet_moments();
  JetMomentMap::moment_store_t::const_iterator it  = moments.begin();
  JetMomentMap::moment_store_t::const_iterator itE = moments.end();
  for (int i = 0; it != itE; ++it, ++i){
    m_jet_moment_vars[i] = dynamic_cast<IBranchWrap_JetMoment*>((*it)->GetBranchWrap());
    this->set_name_register(*(m_jet_moment_vars[i]), (*it)->GetName(), tree);
  }
  
  // schedule event moments
  const JetMomentMap::moment_store_t& event_moments = m_mmap->get_event_moments();
  m_event_moment_vars.resize(event_moments.size(), NULL);
  it  = event_moments.begin();
  itE = event_moments.end();
  for (int i = 0; it != itE; ++it, ++i) {
    m_event_moment_vars[i] = dynamic_cast<IBranchWrap_EventMoment*>((*it)->GetBranchWrap());
    this->set_name_register(*(m_event_moment_vars[i]), (*it)->GetName(), tree);
  }
}

void GenericJetVar::set_data(JetCollection& theJets) {
  resize_vars(theJets);
  
  // !! important : point to this JetCollection map.
  // This assumes it has the same structure as the map used in schedule
  // (almost guaranteed when using JetAnalyis)
  m_mmap = theJets.get_JetMomentMap();
  if (!m_mmap) return;
  
  // Loop over scheduled jet moments
  for (size_t i = 0; i < m_jet_moment_vars.size(); i++) {
    TString name = m_jet_moment_vars[i]->get_name();
    name.ReplaceAll(TString(m_prefix)+"_","");
    //cout << "GenericJetVar: Loading data for moment " << name << endl;
    // loop over jets
    JetCollection::iterator it  = theJets.begin();
    JetCollection::iterator itE = theJets.end();
    for (size_t jeti = 0; it != itE; ++it, ++jeti) { // loop on each jet
      Moment named_blank(name.Data());
      const Moment* m = m_mmap->get_jet_moment(*it, &named_blank);
      if(m) m_jet_moment_vars[i]->LoadMoment(m, jeti); //m_jet_moment_vars[i][jeti] = m->GetValue();
    }
  }
  
  // Now set global variables :
  const JetMomentMap::moment_store_t& event_moments = m_mmap->get_event_moments();
  if (event_moments.size() != m_event_moment_vars.size()) {
    cout << "GenericJetVarSimple::set_data: Event has wrong number of moments!" << endl;
    return;
  }
  JetMomentMap::moment_store_t::const_iterator mit  = event_moments.begin();
  JetMomentMap::moment_store_t::const_iterator mitE = event_moments.end();
  for (int i = 0; mit != mitE; ++mit, ++i) {
    m_event_moment_vars[i]->LoadMoment(*mit);
  }
}

void GenericJetVar::resize_vars(JetCollection& theJets) {
  N = theJets.size();
  size_t nmom = m_jet_moment_vars.size();
  for (size_t i = 0; i < nmom; ++i) {
    m_jet_moment_vars[i]->resize(N);
  }
}

//*****************************************************************************************

} // namespace SpartyJet
