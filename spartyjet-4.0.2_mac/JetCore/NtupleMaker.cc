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

#include "NtupleMaker.hh"
#include "JetCollection.hh"
#include "OutputVarUtils.hh"

#include "TTree.h"
#include "TFile.h"

using namespace std;

namespace SpartyJet { 

bool IGenericJetVar::do_phiconversion = false;

NtupleMaker::NtupleMaker() {
  m_firstvar = NULL;
  m_tree = NULL ;
  m_file = NULL; 
  m_log.set_name("NtupleMaker");
  m_varnames = new JetVar_Names();
}

NtupleMaker::~NtupleMaker() {
  jetvar_map_t::iterator it =  m_jetvarMap.begin();
  jetvar_map_t::iterator itE = m_jetvarMap.end();
  for (; it != itE; ++it)
    delete (*it).second;
  if (m_tree) delete m_tree;
  if (m_file) delete m_file;
  delete m_varnames;
}


/// Add a given JetVar to the ntuple
void NtupleMaker::addJetVar(IGenericJetVar* jv) {
  m_log << DEBUG << "Adding IGenericJetVar " << jv->name() << "  "<< jv << endl;
  m_jetvarMap[jv->name()] = jv;  
}

void NtupleMaker::addInputJetVar(IGenericJetVar* jv) {
  m_firstvar = jv;
  addJetVar(jv);
}

void NtupleMaker::init(string treename, string treefile, bool update) {
  m_log << DEBUG << "Initializing tree" << m_tree << endl;
  if (update) m_file = new TFile(treefile.c_str(), "UPDATE");
  else m_file = new TFile(treefile.c_str(), "RECREATE");
  m_file->cd();
  m_tree = new TTree(treename.c_str(), "SpartyJet tree");
  schedule();
}

void NtupleMaker::init_with_ttree(TTree* t) {
  m_file = t->GetCurrentFile();
  m_tree = t;
  schedule();
}

/// Schedule every variables added with the addJetVar methods
void NtupleMaker::schedule() {
  if (m_firstvar != NULL) {
    m_firstvar->set_var_names(*m_varnames );
    m_firstvar->schedule(m_tree);
    m_log << DEBUG << "Setting varnames to first var  "<< m_varnames->eta <<endl;
  }
  jetvar_map_t::iterator it = m_jetvarMap.begin();
  jetvar_map_t::iterator itE = m_jetvarMap.end();  
  for (; it != itE; ++it) {    
    IGenericJetVar* jv = (*it).second;

    jv->set_var_names(*m_varnames);

    if (jv != m_firstvar)
      jv->schedule(m_tree);
  }
}

/// Associate a jet_list  to a given JetVar named jetname 
void NtupleMaker::set_data(string jetname, JetCollection& theJets) {
  jetvar_map_t::iterator it = m_jetvarMap.find(jetname);
  if (it != m_jetvarMap.end()) {
    m_log << DEBUG << "Setting data for "<< jetname << "  IGenericJetVar = "<< (*it).second->name() << endl;
    (*it).second->set_data(theJets);    
  } else {
    //didn't find jetname    
  }
}

void NtupleMaker::finalize() {
  m_file->cd();
  m_tree->Write();
  // tree deletion apparently needs to be done before
  // closing file
  if (m_tree) delete m_tree;
  m_tree = NULL;
  m_file->Close();
}

void NtupleMaker::fillJets() {m_tree->Fill();}

IGenericJetVar * NtupleMaker::getJetVar(string name) {
  jetvar_map_t::iterator it = m_jetvarMap.find(name);
  if (it == m_jetvarMap.end()) return NULL;
  else return (*it).second;
}

void NtupleMaker::set_var_names(string eta,string phi,string pt,string e,string mass, string ind, string numc) {
  m_varnames->eta = eta;
  m_varnames->phi = phi;
  m_varnames->pt  = pt;
  m_varnames->e   = e;
  m_varnames->mass = mass;
  m_varnames->ind = ind;
  m_varnames->numC = numc;
}

void NtupleMaker::clear_vars() {
  jetvar_map_t::iterator it =  m_jetvarMap.begin();
  jetvar_map_t::iterator itE = m_jetvarMap.end();
}


} // namespace SpartyJet
