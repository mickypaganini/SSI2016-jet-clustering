#ifndef D0RunIIconeJets_CONEJETINFO_HPP
#define D0RunIIconeJets_CONEJETINFO_HPP

// --------------------------------------------------------------------------
// ConeJetInfo.hpp
// Purpose: Hold informations about the cone jets that do not fit into
//   a CalTClusterChunk/IntEclusterChunk.
//
// Created: Laurent Duflot 31-JUL-2000
//
// Modified:
//  09-Aug-2000 Laurent Duflot
//   + add initial jet ET (i.e. before split/merge) 
//    1-May-2007 Lars Sonnenschein
//    extracted from D0 software framework and modified to remove subsequent dependencies
// --------------------------------------------------------------------------

//#define CONEJET_SPLITMERGE_MOD 100

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace d0{

namespace D0RunIIconeJets_CONEJETINFO {

const int CONEJET_SPLITMERGE_MOD = 100;

class ConeJetInfo
{
public:
  ConeJetInfo(): _seedET(0.), _initial_jet_ET(0.), _nb_split_merge(0) {};
  ConeJetInfo( float seedET): _seedET(seedET),  _nb_split_merge(0) {}; 
  ConeJetInfo( float seedET, float initialET, int nb_split, int nb_merge): 
    _seedET(seedET), _initial_jet_ET(initialET), 
    _nb_split_merge(nb_merge + CONEJET_SPLITMERGE_MOD*nb_split) {};
  ~ConeJetInfo() {};

  float seedET() const {return _seedET;};
  float initialET() const { return _initial_jet_ET; };
  int nbSplit() const {return _nb_split_merge/CONEJET_SPLITMERGE_MOD;};
  int nbMerge() const {return _nb_split_merge%CONEJET_SPLITMERGE_MOD;};
  int SplitMergeWord() const {return _nb_split_merge;};

  void initialET(float ET) { _initial_jet_ET = ET;};
  void splitted() { _nb_split_merge += CONEJET_SPLITMERGE_MOD;};
  void merged() { _nb_split_merge += 1;};


private:
  float _seedET;
  float _initial_jet_ET;  // stable cone ET before split/merge
  int _nb_split_merge;
  
};

}

}  // namespace d0

FASTJET_END_NAMESPACE

#endif

