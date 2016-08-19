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

#ifndef _OUTPUTVARUTILS_HH_
#define _OUTPUTVARUTILS_HH_

#include "CustomMessage.hh"
#include "JetCollection.hh"

// must be included after JetMoment.hh, so quasi-circular template dependencies work.
// JetMoment.icc needs BranchWrap.hh, which needs JetMoment.hh, which includes JetMoment.icc...
#include "BranchWrap.hh"

class TTree;

///////////////////////////////////////////////////////
///   JetVar classes hold variables for a jet collection
///   in order to save them in a ROOT ntuple.
///   They create TTree branches for these variables
///
///  Output variables can be simple type, pure C arrays or STL vectors.  
///  Supported base types are float, double and int. 
///  Current limitation : when using pure C arrays, constituents number must NOT exceed 10000
/// 
///  A 'factory' OutputVarFactory is provided to create those complex JetVar classes 
///  from simple input parameters (ex "vector" and "float"). It allows to hide template 
///  complexity.
///////////////////////////////////////////////////////////
namespace SpartyJet { 

/// Define the naming of output variables.
struct JetVar_Names {
  public:
    JetVar_Names();
    std::string eta;
    std::string phi;
    std::string pt;
    std::string e;
    std::string mass;
    std::string ind;
    std::string numC;
};

///////////////////////////////////////////////////////////////
/// \class IGenericJetVar is an interface for all JetVar classes
///////////////////////////////////////////////////////////////
class IGenericJetVar  {
public:
  
  IGenericJetVar() {};
  IGenericJetVar(std::string name, JetMomentMap* mmap=0) {}
  virtual ~IGenericJetVar() {}
  
  /// Create branches for each variable in the given tree
  virtual void schedule(TTree* tree) = 0;
  /// Associate data from  jet lists to arrays to be dumped in TTree
  virtual void set_data(JetCollection& theJets) = 0;
  /// set the names of output variables
  virtual void set_var_names(JetVar_Names& vn) = 0;

  /// when ROOT output variables are C arrays, one needs the max size of the array 
  /// and the actual size. the following function give this info.
  virtual BranchWrap_simple<int>* get_input_refN() = 0;
  virtual size_t get_size_max() = 0;
  
  virtual std::string name() = 0;

  static bool do_phiconversion;
};


class GenericJetVar  : public IGenericJetVar{
public:
  
  GenericJetVar() {}
  GenericJetVar(std::string name, JetMomentMap* mmap=0)
    : m_prefix(name), m_mmap(mmap), N(""), m_Nmax(100000) {m_log.set_name(name+"_output");}
  virtual ~GenericJetVar() {clear_list(m_jet_moment_vars); clear_list(m_event_moment_vars);}
  
  /// Create branches for each variable in the given tree
  virtual void schedule(TTree* tree);
  /// Associate data from  jet lists to arrays
  virtual void set_data(JetCollection& theJets);
  virtual void set_var_names(JetVar_Names& vn) {}
  virtual std::string name() {return m_prefix;}
  
protected:
  
  std::string m_prefix;
  JetMomentMap* m_mmap;
  
  std::vector<IBranchWrap_JetMoment*> m_jet_moment_vars;
  std::vector<IBranchWrap_EventMoment*> m_event_moment_vars;
  
  BranchWrap_simple<int> N; /// The number of jets in the collection
  
  /// when ROOT output variables are C arrays, one needs the max size of the array 
  /// and the actual size. the following function give this info.
  virtual BranchWrap_simple<int>* get_input_refN() {return &N;}
  virtual size_t get_size_max() {return m_Nmax;}
  size_t m_Nmax; // The maximum number of jets: no size restriction because we use vectors
  
  Message m_log;
  
  template<class BRANCH>
  void set_name_register(BRANCH& b, const std::string& name, TTree* t){
    std::string fname = m_prefix+"_" + name ;
    m_log << DEBUG << "Scheduling "<< fname << std::endl;
    b.set_name(fname);
    b.registerBranch(t);
  }
  
  /// All branch-arrays are resize to N (usefull only when BRANCHXD are vectors)
  virtual void resize_vars(JetCollection& theJets);
};


///////////////////////////////////////////////////////////////
/// \class JetVar
/// \brief specialization of GenericJetVar with kinematic variables.
/// 
/// Just adds kinematic variables of jets
/// Leaving jet variable branches templated for now
///////////////////////////////////////////////////////////////
template< class BRANCH1D>
class JetVar : public  GenericJetVar {
public:
  JetVar(){};
  JetVar(std::string name, JetMomentMap* mmap=0) : GenericJetVar(name, mmap) {}
  virtual ~JetVar() {}
  
  virtual void set_var_names(std::string eta, std::string phi,  std::string pt,
                             std::string e,   std::string mass, std::string ind,
                             std::string numc);
  virtual void set_var_names(JetVar_Names& vn) {var_names = vn;}
  
  virtual void schedule(TTree* tree);
  virtual void set_data(JetCollection& theJets);
  
protected :
  /// All branch-arrays are resize to N (usefull only when BRANCH1D are vectors)
  virtual void resize_vars(JetCollection& theJets);
  
  JetVar_Names var_names;
  
  BRANCH1D eta;
  BRANCH1D phi;
  BRANCH1D pt;
  BRANCH1D e;
  BRANCH1D mass;
};


///////////////////////////////////////////////////////////////
/// \class JetVarIndex  
///
/// \brief specialization of JetVar adding variables to hold jet constituents index
/// 
/// adds a new template parameter : the abstracted branch type describing indices.
///////////////////////////////////////////////////////////////
template< class BRANCH1D, class BRANCH1Dind>
class JetVarIndex : public JetVar<BRANCH1D> {
public:
  JetVarIndex(std::string name,JetMomentMap *mmap=0);
  virtual ~JetVarIndex() {}
  virtual void schedule(TTree* tree);
  virtual void set_data(JetCollection& theJets);
  
  void set_input_refN(BranchWrap_simple<int>* jv) {m_input_refN = jv;}
  void set_input_refMax(size_t max) {m_input_sizeMax = max;}

  int get_index_max() {return index.size_max();}

protected :
  /// All branch-arrays are resize to N (usefull only when BRANCH1D are vectors)
  virtual void resize_vars(JetCollection& theJets);

  BranchWrap_simple<int>* m_input_refN; // Branch holding the number of jets. Mandatory when using array in BRANCH1D
  size_t m_input_sizeMax;
  
  BRANCH1Dind index;
  BRANCH1D num_constit;
};


enum ArrayType {kVector, kArray};
enum BaseType  {kFloat, kDouble};

///////////////////////////////////////////////////////////////
/// \class OutputVarFactory
///
/// \brief convenience class : create function JetVar classes from simple parameters
/// 
///////////////////////////////////////////////////////////////
class OutputVarFactory {
public:
  OutputVarFactory() : m_array_type(kVector), m_base_type(kFloat) {}
    
  void set_array_type(ArrayType t) {m_array_type = t;}
  void set_base_type(BaseType t) {m_base_type = t;}
  
  /// Build a JetVar class. if inputvar != NULL then  build JetVarIndex else JetVar.
  IGenericJetVar* get_jet_var(std::string name, JetMomentMap* map, IGenericJetVar* inputvar = 0, bool onlymoment = false);
  /// Build a JetVar class for input jet (no index, no moment, size 10000 in case of array)
  IGenericJetVar* get_inputjet_var(std::string name, JetMomentMap* map= NULL);

protected:
  // a short cut for hopefully better readability
  template<class JVI>
  IGenericJetVar* prepare_input(JVI* jvar, IGenericJetVar * inputvar) {
    jvar->set_input_refN(inputvar->get_input_refN());
    return jvar;
  }

  template <int N>
  IGenericJetVar* _get_jet_var(std::string name, JetMomentMap* map, IGenericJetVar* inputvar = 0, bool onlymoment = false);


  ArrayType m_array_type;
  BaseType m_base_type;
};


} // namespace SpartyJet

#ifndef G__DICTIONARY
// prevent dict generation by rootcint for this part of header
#include "OutputVarUtils.icc"
#endif


#endif
