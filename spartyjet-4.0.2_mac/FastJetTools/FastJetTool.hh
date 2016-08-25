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

#ifndef _FASTJETTOOL_HH_
#define _FASTJETTOOL_HH_

#include "JetCore/JetTool.hh"
#include "JetCore/JetMomentMap.hh"

#include "fastjet/ClusterSequence.hh"

namespace SpartyJet {
namespace FastJet {

/// A wrapper for FastJet JetTool's -- handles conversion from ClusterSequence to JetCollection.
///  (Should be obsolete soon!)
class FastJetTool : public JetTool {
public:
  FastJetTool(std::string name = "FJTool") : JetTool(name) {}
  virtual ~FastJetTool() {}

  virtual void execute(JetCollection& jc);

  // Many (most?) FJTools will work just by implementing this function
  virtual void execute(fastjet::ClusterSequence& cs) {}
};


/// Similar, but runs on single jets
/// User overrides execute(PseudoJet)
class PseudoJetTool : public JetTool {
public:
  PseudoJetTool(std::string name = "PseudoJetTool") : JetTool(name) {}
  virtual ~PseudoJetTool() {}
  
  /// does conversion SpartJet::Jet -> fastjet::PseudoJet
  virtual void execute(Jet* j);
    
  /// User defines this
  virtual void execute(fastjet::PseudoJet& pj) = 0;

/// a derived class should use this to set jet moments
///  should be called by execute(PseudoJet) during call from execute(Jet)
protected:
  template <class T>
  void set_jet_moment(std::string name, T value) {m_map->set_jet_moment<T>(name, m_currentJet, value);}
private:
  const Jet* m_currentJet;
};


#ifndef __CINT__

/// A Fake Plugin JetDefinition for help in initializing ClusterSequence
class BlankPlugin : public fastjet::JetDefinition::Plugin {
public:
  virtual std::string description() const {return "Blank plugin -- don't use!";}
  virtual void run_clustering(fastjet::ClusterSequence&) const {}
  virtual double R() const {return 1e100;}
};

/// Helper class: inherits from ClusterSequence but knows how to build itself from a JetCollection
/// An optional JetDefinition argument lets FastJet know what algorithm was used
///  to cluster the jets; this may be useful for subsequent tools.
/// If Jet j is non-zero, only loads that jet and its constituents
class SJClusterSequence : public fastjet::ClusterSequence {
public:
  SJClusterSequence(JetCollection& jetcoll, fastjet::JetDefinition* jetdef=0, Jet* j=0);
  virtual ~SJClusterSequence() {delete _default_jet_def.plugin();}
protected:
  virtual void LoadNodeHistoryElement(HistoryElement *he);
  virtual void LoadLeafHistoryElement(HistoryElement *he);
  virtual void PromoteJet(int ind); // promotes pseudojet at index ind to a jet
protected:
  double _max_dij_so_far;
  fastjet::JetDefinition _default_jet_def;
};

#endif

}
} // namespace SpartyJet

#endif
