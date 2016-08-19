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

#ifndef _NTUPLEMAKER_HH_
#define _NTUPLEMAKER_HH_

#include "CustomMessage.hh"

#include <string>
#include <map>
#include <vector>


#define NMAX 10000
#define NMOM_ARRAY_MAX 4

class TTree;
class TFile;

namespace SpartyJet {

class JetCollection;
class IGenericJetVar;
struct JetVar_Names;

// *****************************************************
// NtupleMaker : manage TTree and a collection of JetVar
//   and associate jet collections to the JetVars       
// *****************************************************
class NtupleMaker {

public:

  typedef std::map<std::string, IGenericJetVar*> jetvar_map_t;
    
  NtupleMaker();
  ~NtupleMaker();

  // Adding a GenericJetVar to the ntuple
  void addJetVar(IGenericJetVar* jv);
  void addInputJetVar(IGenericJetVar* jv);

  void init(std::string treename, std::string filename, bool update=false);
  void init_with_ttree(TTree* t);
  void finalize();

  void set_data(std::string jetname, JetCollection& theJets);

  void fillJets();

  // Re-access the JetVar object by its name
  IGenericJetVar* getJetVar(std::string name);

  void set_var_names(std::string eta, std::string phi,  std::string pt,
                     std::string e,   std::string mass, std::string ind,
                     std::string numc);

  void clear_vars();

  TTree* get_tree() {return m_tree;}
  TFile* get_file() {return m_file;}

protected:

  void schedule();

  TTree* m_tree;
  TFile* m_file;

  jetvar_map_t m_jetvarMap;

  IGenericJetVar* m_firstvar;

  Message m_log;

  JetVar_Names* m_varnames;
};

}  // namespace SpartyJet
#endif


