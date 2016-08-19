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

#include "TopDownPruneTool.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/JetHistory.hh"
#include <vector>
#include <cmath>
using namespace std;

namespace SpartyJet {


void TopDownPruneTool::execute(JetCollection& inputJets) {
  JetMomentMap* mmap = inputJets.get_JetMomentMap();
  JetCollection::iterator it, itE;
  it  = inputJets.begin();
  itE = inputJets.end();
  for (; it != itE; ++it) {
    set_globals(*it);
    m_Nsubjets = prune_branching(*it, inputJets);
    mmap->set_jet_moment(*it, &m_Nsubjets);
  }
}



// Recersively check if this branching should be "pruned", and discard the
//  pruned parents.  Increments level at each sucessful branching, stopping
//  at m_max_split (or never if m_max_split = -1).  Returns the number of
//  subjets found (one sucessful splitting yields two, two yields three, etc.).
int TopDownPruneTool::prune_branching(Jet* subjet, JetCollection& jc, int level) {
  if (m_max_split != -1 && level >= m_max_split) return 1;
  
  vector<Jet*> parents = jc.get_parents(subjet);
  vector<Jet*> parents_failed;
  if (parents.size() == 0) return 1;
  if (parents.size() == 1) return prune_branching(parents[0], jc, level);
  
  int Nsubjets = 0;
  branch_test(subjet, parents, parents_failed);
  // increase split level if more than one parent passed:
  int new_level = parents.size() > 1 ? level + 1 : level;
  
  // recurse on passing branches
  if (parents.size() == 0) Nsubjets = 1;
  else for (size_t i = 0; i < parents.size(); ++i)
      Nsubjets += prune_branching(parents[i], jc, new_level);
  // remove failed branches
  //if (Nsubjets > 1)  // Identical to original JH scheme with this if statement!
    jc.remove_subjets(subjet, parents_failed);
  
  return Nsubjets;
}

void TopDownPruneTool::remove_softest_parent(std::vector<Jet*>& parents,
                       std::vector<Jet*>& parents_failed) {
  if (parents.size() == 0) return;
  size_t softest = 0;
  for (size_t i = 1; i < parents.size(); ++i)
    if (parents[i]->perp() < parents[softest]->perp()) softest = i;
  parents_failed.push_back(parents[softest]);
  parents.erase(parents.begin()+softest);
}

void TopDownPruneTool::remove_lightest_parent(std::vector<Jet*>& parents,
                       std::vector<Jet*>& parents_failed) {
  if (parents.size() == 0) return;
  size_t lightest = 0;
  for (size_t i = 1; i < parents.size(); ++i)
    if (parents[i]->m() < parents[lightest]->m()) lightest = i;
  parents_failed.push_back(parents[lightest]);
  parents.erase(parents.begin()+lightest);
}

// Requires that the jet have at least m_cutsI[0] subjets, as found by
//  the tool passed to the constructor.
// Also unclusters the jet so that the last merging is Nsubjets -> 1 if m_uncluster = true
bool SubjetCutTool::passCut(Jet* j) {
  int Nsubjets = m_map->get_jet_moment<int>(subjetMomentName, j);
  if (Nsubjets >= m_cutsI[0]) {
    if (m_uncluster) {
      // uncluster to Nsubjets subjets of total jet
      HistoryElement *he = j->history();
      if (he && he->nParents() > 0) {
        std::vector<HistoryElement*> parents = he->parents();
        while ((int)parents.size() < Nsubjets) {
          // find parent with largest dij
          HistoryElement *to_uncluster = parents[0];
          double dij = parents[0]->dij();
          for (size_t i = 1; i < parents.size(); ++i) {
            if (parents[i]->dij() > dij) {
              to_uncluster = parents[i];
              dij = parents[i]->dij();
            }
          }
          // now uncluster this parent
          std::vector<HistoryElement*> grandparents = to_uncluster->parents();
          for (size_t i = 0; i < grandparents.size(); ++i) {
            he->addParent(grandparents[i]);
            to_uncluster->removeParent(grandparents[i]);
            grandparents[i]->setChild(he);
          }
          he->removeParent(to_uncluster);
          delete to_uncluster;
          parents = he->parents();
        }
      }
    }
    return true;
  }
  return false;
}

// Implements the mass drop and asymmetry tests from arXiv:0802.2470:
//  max(m_1, m_2)/mjet < mu_cut (default = 0.67)
//  min(pt_1^2, pt_2^2) * DeltaR_{12}^2 / mjet^2 > ycut (default = 0.09)
void MassDropTool::branch_test(const Jet* child, std::vector<Jet*>& parents,
                               std::vector<Jet*>& parents_failed) {
  double mjet = child->m();
  if (mjet < 1.e-6) {parents.clear(); return;}  // protect against divide-by-zero
  else if (parents.size() != 2) {
    m_log << ERROR << "MassDrop method only intended for 1->2 splittings!" << std::endl;
    parents.clear();
    return;
  } else {
    bool test = true;
    Jet *p1 = parents[0];
    Jet *p2 = parents[1];
    // find largest subjet mass, test m_sub/m_jet < mu_cut
    double max_m = 0.;
    max_m = std::max(max_m, p1->m());
    max_m = std::max(max_m, p2->m());
    test &= max_m/mjet < m_mu_cut;
    // find y, test y > ycut
    double y = std::min(p1->perp2(), p2->perp2()) * p1->squared_distance(*p2) / (mjet*mjet);
    test &= y > m_ycut;
    if (!test) remove_lightest_parent(parents, parents_failed);
  }
}

// Implements the pruning step in the Johns Hopkins top-tagging scheme
//  (arXiv:0806.0848).  A branching passes if:
//    1) pT_i > m_delta_p * pT_{i+j} for both parents
//    2) DeltaR_ij > m_delta_r
// If 2 fails, stop.  If 1 fails for both parents, stop.  If 1 fails for one
//  parent, discard failed parent and recurse on harder parent.
void JHPruneTool::branch_test(const Jet* child, std::vector<Jet*>& parents,
                               std::vector<Jet*>& parents_failed) {
  if (m_pt < 1.e-6) {parents.clear(); return;}
  else if (parents.size() != 2) {
    m_log << ERROR << "JHPrune method only intended for 1->2 splittings!" << std::endl;
    parents.clear(); return;
  } else {
    Jet *p1 = parents[0];
    Jet *p2 = parents[1];
    if (p2->perp() > p1->perp()) std::swap(p1, p2);
    if ( (p1->perp() < m_delta_p * m_pt) // both too soft
      || (std::sqrt(p1->squared_distance(*p2)) < m_delta_r) ) { // too close
      parents.clear();
    } else if (p2->perp() < m_delta_p * m_pt) {
      remove_softest_parent(parents, parents_failed);
    }
  }
}


// For each jet, merge the pair of subjets that have mass closest to m_subjetMass.
void SubjetMergeTool::execute(JetCollection& inputJets) {
  JetCollection::iterator it, itE;
  it = inputJets.begin();
  itE = inputJets.end();
  for (; it != itE; ++it) {
    vector<Jet*> parents = inputJets.get_parents(*it);
    if (parents.size() < 3) return;
    int min_i=0, min_j=1;
    double min_diff = 1.e100;
    // find closest mass pair of this Jet's subjets
    for (size_t i = 0; i < parents.size(); ++i) {
      for (size_t j = i + 1; j < parents.size(); ++j) {
        Jet sum(0,0,0,0,-1);
        sum += *parents[i];
        sum += *parents[j];
        if (abs(sum.m() - m_subjetMass) < min_diff) {
          min_diff = abs(sum.m() - m_subjetMass);
          min_i = i;
          min_j = j;
        }
      }
    }
    // merge subjets min_i + min_j and insert into history
    vector<Jet*> to_merge;
    to_merge.push_back(parents[min_i]);
    to_merge.push_back(parents[min_j]);
    inputJets.merge_subjets(to_merge);
  }
}

// For each jet, merge the pair of subjets that gives the lowest mass.
void MinMassTool::execute(JetCollection& inputJets) {
  JetCollection::iterator it, itE;
  it = inputJets.begin();
  itE = inputJets.end();
  for (; it != itE; ++it) {
    vector<Jet*> parents = inputJets.get_parents(*it);
    double min_mass = 0.0;
    if (parents.size() >= 3) { // if < 3 parents, just leave min_mass = 0 and don't do anything
      int min_i=0, min_j=1;
      min_mass = 1.e100;
      // find minimum mass pair of this Jet's subjets
      for (size_t i = 0; i < parents.size(); ++i) {
        for (size_t j = i + 1; j < parents.size(); ++j) {
          Jet sum(0,0,0,0,-1);
          sum += *parents[i];
          sum += *parents[j];
          if (sum.m() < min_mass) {
            min_mass = sum.m();
            min_i = i;
            min_j = j;
          }
        }
      }
      // merge subjets min_i + min_j and insert into history
      vector<Jet*> to_merge;
      to_merge.push_back(parents[min_i]);
      to_merge.push_back(parents[min_j]);
      inputJets.merge_subjets(to_merge);
    }
    
    JetMomentMap *map = inputJets.get_JetMomentMap();
    if(map) map->set_jet_moment<Double32_t>(m_name, *it, min_mass);
  }
}

// Uncluster to N subjets, so last merge is N->1
void UnclusterTool::execute(JetCollection& inputJets) {
  JetCollection::iterator it, itE;
  it = inputJets.begin();
  itE = inputJets.end();
  for (; it != itE; ++it) {
    vector<Jet*> parents = inputJets.get_parents(*it);
    if (parents.size() < 2) continue; // no substructure
    while (parents.size() < m_N) {
      double max_dij = inputJets.get_dij(parents[0]);
      Jet *to_uncluster = parents[0];
      for (size_t i = 1; i < parents.size(); ++i) {
        if (inputJets.get_dij(parents[i]) > max_dij) {
          max_dij = inputJets.get_dij(parents[i]);
          to_uncluster = parents[i];
        }
      }
      inputJets.uncluster_jet(to_uncluster);
      // check for failure
      size_t old_size = parents.size();
      parents = inputJets.get_parents(*it);
      if (parents.size() == old_size) break;
    }
  }
}

} // namespace SpartyJet
