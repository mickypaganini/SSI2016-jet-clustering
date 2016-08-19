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

#include "FastJetTool.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/JetHistory.hh"

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
using namespace fastjet;

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

namespace SpartyJet {
namespace FastJet {

void print_history(const ClusterSequence & seq)
{
	// get the history from in_seq
	const vector<ClusterSequence::history_element> & history = seq.history();
	const vector<PseudoJet> &particles = seq.jets();
	
	printf("%10s %10s %10s %10s %10s %10s %10s %10s\n", "history #", "parent 1",
         "parent 2", "child", "jet index", "ID #", "dij", "jet pT");
	for (unsigned int i = 0; i < history.size(); i++) {
		const ClusterSequence::history_element & h = history[i];
		if(h.jetp_index >= 0)
			printf("%10i %10i %10i %10i %10i %10i %10.3e %10.3e %10.3f\n", i, h.parent1,
             h.parent2, h.child, h.jetp_index,
             particles[h.jetp_index].user_index(), h.dij, h.max_dij_so_far,
             particles[h.jetp_index].perp());
		else
			printf("%10i %10i %10i %10i %10i %10s %10.3e %10.3e %10s\n", i, h.parent1,
             h.parent2, h.child, h.jetp_index, "XX", h.dij, h.max_dij_so_far, "XX");
	}
	
}

void FastJetTool::execute(JetCollection &jc) {
  // convert to ClusterSequence here and call execute(cs)
  SJClusterSequence cs(jc);
  execute(cs);  
  jc.clear_and_delete();
  jc.insert(cs);
}


void PseudoJetTool::execute(Jet* j) {

  m_currentJet = j;
  execute(*j);
}


// ***** Helper functions to create a ClusterSequence from a JetCollection/Jet
// Note that jetdef is not actually used anywhere; it is included so that
//  we can tell FastJet that, say, Cambridge/Aachen was used to cluster.
// TODO: why not use CS::_fill_initial_history()? (I think there was a reason but I can't remember now.)
SJClusterSequence::SJClusterSequence(JetCollection& jetcoll, JetDefinition* jetdef, Jet* jet)
  : ClusterSequence(), _max_dij_so_far(0.), _default_jet_def(new BlankPlugin()) {
  // load some metadata to make FastJet believe a certain algorithm was used
  if (jetdef) _decant_options(*jetdef, false);
  else _decant_options(_default_jet_def, false);

  // zero out total quantities; they will be updated by LoadLeafHistoryElement()
  _initial_n = 0;
  _Qtot = 0;

  vector<HistoryElement*> full_history = jetcoll.full_history(jet);
  vector<HistoryElement*>::const_iterator hit, hitE;
  hit = full_history.begin();
  hitE = full_history.end();
  vector<int> to_promote;
  
  // first, load leaves (might not be all at front of full_history())
  for (; hit != hitE; ++hit) {
    vector<HistoryElement*> parents = (*hit)->parents();
    Jet *j = (*hit)->getJet();
    // leaf
    if (parents.size() == 0) {
      _jets.push_back(*j);
      LoadLeafHistoryElement(*hit);
    }
    // old leaf style
    if (parents.size() == 1) cout << "SJCS: Using old-style leaves!" << endl;
  }
  // now get the rest
  for (hit = full_history.begin(); hit != hitE; ++hit) {  
    vector<HistoryElement*> parents = (*hit)->parents();
    Jet *j = (*hit)->getJet();
    // node
    if (parents.size() == 2) {
      _jets.push_back(*j);
      LoadNodeHistoryElement(*hit);
    }
    // top-level node
    if (!(*hit)->child())
      to_promote.push_back((*hit)->hindex());
  }
  for (size_t i = 0; i < to_promote.size(); ++i)
    PromoteJet(to_promote[i]);

  // set CS structure shared ptr
  _structure_shared_ptr.reset(new ClusterSequenceStructure(this));
  // set shared pointers for jets
  for (size_t i = 0; i < _jets.size(); ++i)
    _jets[i].set_structure_shared_ptr(_structure_shared_ptr);
}
void SJClusterSequence::LoadNodeHistoryElement(HistoryElement *he) {
  int newjet_k = _jets.size()-1; // merged jet's index

  // get history index
  int newstep_k = _history.size();
  // and provide jet with the info
  _jets[newjet_k].set_cluster_hist_index(newstep_k);

  he->setHindex(newstep_k);

  history_element element;
  element.parent1 = he->parents()[0]->hindex();
  element.parent2 = he->parents()[1]->hindex();
  element.jetp_index = newjet_k;
  element.child = ClusterSequence::Invalid;
  element.dij   = he->dij();
  
  // old way -- relies on history being in clustering order
  //  not always true, in particular for re-clustered jets
  //_max_dij_so_far = max(element.dij, _max_dij_so_far);
  //element.max_dij_so_far = _max_dij_so_far;
  
  // better (but only gets max_dij_so_far right within a jet)
  //  there may be pathological cases where this is not globablly correct
  element.max_dij_so_far = he->max_dij_so_far();
  
  _history.push_back(element);

  int local_step = _history.size()-1;
  assert(local_step == newstep_k);

  assert(element.parent1 >= 0);
  _history[element.parent1].child = local_step;
  if (element.parent2 >= 0) {_history[element.parent2].child = local_step;}
}

void SJClusterSequence::PromoteJet(int ind) {
  // get history index
  int newstep_k = _history.size();
  _history[ind].child = newstep_k;

  history_element element;
  element.parent1 = ind;
  element.parent2 = ClusterSequence::BeamJet;
  element.jetp_index = ClusterSequence::Invalid;
  element.child = ClusterSequence::Invalid;
  element.dij   = 1e100; // not implementing this yet
  element.max_dij_so_far = 1e100;
  _history.push_back(element);
}

void SJClusterSequence::LoadLeafHistoryElement(HistoryElement *he) {
  int i = _jets.size()-1; // this jet's index in _jets
  history_element element;
  element.parent1 = InexistentParent;
  element.parent2 = InexistentParent;
  element.child   = Invalid;
  element.jetp_index = i;
  element.dij     = 0.0;
  element.max_dij_so_far = 0.0;

  _history.push_back(element);
  _jets[i].set_cluster_hist_index(_history.size()-1);
  Jet *jet = he->getJet();
  _jets[i].set_user_index(jet->input_index()); // so can relate PseudoJets back to original JetCollection

  // reset he's index (will have changed if subjets were removed)
  he->setHindex(_history.size()-1);

  _initial_n++;
  _Qtot += jet->E();
}


}
} // namespace SpartyJet
