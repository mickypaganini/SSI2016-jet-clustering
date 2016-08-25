// Copyright 2010, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
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

#ifndef _TOPDOWNPRUNE_TOOL_HH_
#define _TOPDOWNPRUNE_TOOL_HH_

/// A TopDownPruneTool recurses through a jet's substructure, discarding
///  asymmetric branches.  A test for asymmetry should be supplied by the user
///  as the branch_test() method of a  derived class.  The parameter max_split
///  determines how many splittings will be attempted.  max_split = 1 will yield
///  one or two subjets; max_split = 2 will yield 1-4, etc.  The output
///  JetCollection is just the original one with some of the branches removed.
///  A JetMoment "Nsubjets_[Tool name]" is stored for each jet, holding the
///  number of subjets found, which will be in [1, 2**max_split].
/// See MassDropTool (below) for an example.

#include "JetCore/JetTool.hh"
#include "JetTools/JetSelectorTool.hh"

namespace SpartyJet {

class TopDownPruneTool : public JetTool {
public:
  TopDownPruneTool(int max_split = -1, std::string name = "TopDownPrune")
    : JetTool(name), m_max_split(max_split), m_Nsubjets("Nsubjets_"+name) {}
  virtual void init(JetMomentMap *mmap = NULL) {if(mmap) mmap->schedule_jet_moment(&m_Nsubjets);}
  virtual void execute(JetCollection &inputJets);
  virtual ~TopDownPruneTool() {}

protected:
  // Recersively check if this branching should be "pruned", and discard the
  //  pruned parents.  Increments level at each sucessful branching, stopping
  //  at m_max_split (or never if m_max_split = -1).  Returns the number of
  //  subjets found (one sucessful splitting yields two, two yields three, etc.).
  virtual int prune_branching(Jet *subjet, JetCollection &jc, int level=0);

  // Basic test of branch asymmetry, which should be implemented by derived
  //  classes.  Remove asymmetric parent(s) from the vector<Jet*> and put
  //  them in parents_failed.  "Pass" == parents.size() > 1 on return.
  virtual void branch_test(const Jet *child, std::vector<Jet*> & parents,
                           std::vector<Jet*> & parents_failed) = 0;

  // Set global variables for a given jet (say, jet pT) before we start pruning
  virtual void set_globals(const Jet *j) {}
  
  // Convenience methods to use in branch_test implementations
  virtual void remove_softest_parent(std::vector<Jet*> & parents,
                                    std::vector<Jet*> & parents_failed);
  virtual void remove_lightest_parent(std::vector<Jet*> & parents,
                                    std::vector<Jet*> & parents_failed);
public:
  std::string get_moment_name() {return m_Nsubjets.GetName();}
protected:
  int m_max_split; // Maximum number of successful splittings before the
                   //  pruning stops (m_max_split = 2 corresponds to splitting
                   //  down to a max of 4 subjets).
  JetMoment<int> m_Nsubjets; // JetMoment to hold # of subjets found
};


/// Simple cut tool that requires jets to have >= Nsubjets.
/// subjet_tool should be a pointer to the tool that found the subjets -- needed
///  so we know which Moment to ask for.
/// Also unclusters jet such that last merging is Nsubjets -> 1 if uncluster=true.
class SubjetCutTool : public JetSelectorTool {
public:
  SubjetCutTool(TopDownPruneTool *subjet_tool, int Nsubjets = 2,
                bool uncluster = false, std::string name = "SubjetCut")
    : JetSelectorTool(std::vector<int>(1, Nsubjets), name),
      subjetMomentName(subjet_tool->get_moment_name()), m_uncluster(uncluster)
    {}
  bool passCut(Jet *j);
protected:
  std::string subjetMomentName;
  bool m_uncluster;
};

/// This tool implements the mass drop procedure described in arXiv:0802.2470.
/// Jet branches that fail the mass drop and asymmetry cuts are discarded, down 
///  to a given level of splitting (default is one). 
class MassDropTool : public TopDownPruneTool {
public:
  MassDropTool(double mu_cut = 0.67, double ycut = 0.09, int max_split = 1,
               std::string name = "MassDrop")
    : TopDownPruneTool(max_split, name), m_mu_cut(mu_cut), m_ycut(ycut) {}
  void branch_test(const Jet *child, std::vector<Jet*> & parents,
                           std::vector<Jet*> & parents_failed);
protected:
  double m_mu_cut, m_ycut;
};

/// This tool implements the pruning tool in the Johns Hopkins top-tagging
///  scheme (arXiv:0806.0848).
class JHPruneTool : public TopDownPruneTool {
public:
  JHPruneTool(double delta_p = 0.1, double delta_r = 0.19, int max_split = 2,
              std::string name = "JHPrune")
    : TopDownPruneTool(max_split, name), m_delta_p(delta_p), m_delta_r(delta_r), m_pt(0.0) {}
  void branch_test(const Jet *child, std::vector<Jet*> & parents,
                           std::vector<Jet*> & parents_failed);
  void set_globals(const Jet *j) {m_pt = j->perp();}
protected:
  double m_delta_p, m_delta_r;
  double m_pt;
};

/// Not a TopDownPrune-r, but goes with JHPruneTool.
/// For each jet, merges the pair of subjets that gives a mass closest to m_subjetMass;
class SubjetMergeTool : public JetTool {
public:
  SubjetMergeTool(double m, std::string name = "SubjetMergeTool")
    : JetTool(name), m_subjetMass(m) {}
  void execute(JetCollection &inputJets);
protected:
  double m_subjetMass;
};

/// Not a TopDownPrune-r, but goes with JHPruneTool.
/// For each jet, merges the pair of subjets that gives the lowest mass.
class MinMassTool : public JetTool {
public:
  MinMassTool(std::string name = "minMass") : JetTool(name) {}
  virtual void init(JetMomentMap *mmap = NULL) {if(mmap) mmap->schedule_jet_moment<Double32_t>(m_name);}
  void execute(JetCollection &inputJets);
};

/// Uncluster jets down to N subjets
///  (So last merging step is N->1, not 2->1)
/// TODO: add dcut unclustering
class UnclusterTool : public JetTool {
public:
  UnclusterTool(size_t N, std::string name = "UnclusterTool") : JetTool(name), m_N(N) {}
  void execute(JetCollection &inputJets);
protected:
  size_t m_N;
};


}  // namespace SpartyJet



#endif


