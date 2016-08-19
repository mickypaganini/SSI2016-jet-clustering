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

#include "JetCore/JetCollection.hh"
#include "JetCore/JetStructure.hh"
#include "FastJetUtils.hh"
#include "FastJetFinder.hh"

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequenceActiveArea.hh"
#include "fastjet/AreaDefinition.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/ClusterSequencePassiveArea.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/GhostedAreaSpec.hh"
using namespace fastjet;

#include <vector>
using namespace std;

namespace SpartyJet {
namespace FastJet {


FastJetFinder::FastJetFinder(string name, JetAlgorithm alg, double R, bool area)
                            : JetTool(name) {
  set_defaults(); // sets all other parameters to sensible values
  set_algorithm(alg, R);
  m_area = area;
  init();
}

FastJetFinder::FastJetFinder(JetDefinition* jet_def, string name, bool area)
                            : JetTool(name) {
  set_defaults();
  m_use_ext_jet_def = true;
  m_jet_def = jet_def;
  m_area = area;
  init();
}

FastJetFinder::~FastJetFinder()
{
  if (! m_use_ext_jet_def) // only delete jet_def if we made it
    delete m_jet_def; m_jet_def = NULL;
}

void FastJetFinder::set_defaults() {
  m_jet_def = NULL;
  m_use_ext_jet_def = false;

  m_areaChoice    = active_area;
  m_inclusive     = true;

  m_ptmin         = 5.0;
  m_dcut          = 25.0;
  m_njets         = -1;

  m_ghost_etamax  = 6.0;
  m_repeat        = 5;
  m_ghost_area    = 0.01;
  m_grid_scatter  = 1E-4;
  m_kt_scatter    = 0.01;
  m_mean_ghost_kt = 1E-100;
}


// Should we bother safety check here?  Let FastJet figure it out...
void FastJetFinder::set_algorithm(JetAlgorithm x, double R) {
  if(x != kt_algorithm && x != cambridge_algorithm && x != antikt_algorithm
     && x != genkt_algorithm && x != cambridge_for_passive_algorithm
     && x != genkt_for_passive_algorithm) {
    cout << "FastJet algorithm \"" << x << "\" is not defined." << endl;
    cout << "acceptable algorithms are: " << endl;
    cout << " kt  : kt_algorithm " << endl;
    cout << " CambAach  : cambridge_algorithm " << endl;
    cout << " antikt  : antikt_algorithm " << endl;
    cout << " genkt  : genkt_algorithm " << endl;
    cout << " CambAachPassive : cambridge_for_passive_algorithm " << endl;
    cout << " genktPassive : genkt_for_passive_algorithm " << endl;
  }
  else if (m_use_ext_jet_def) {
    cout << "Using external jet definition, don't call set_algorithm -- mess with it yourself!" << endl;
  }
  else {
    // Prepare JetDefinition
    if (m_jet_def != NULL) delete m_jet_def;
    m_jet_def = new JetDefinition((JetAlgorithm)x, R);
    m_log << INFO << "FastJet configured to run: " << m_jet_def->description() << endl;
  }
}

void FastJetFinder::configure_area(double e, int r, double a,
                                   double s, double ks, double kt) {
  m_ghost_etamax  = e;
  m_repeat        = r;
  m_ghost_area    = a;
  m_grid_scatter  = s;
  m_kt_scatter    = ks;
  m_mean_ghost_kt = kt;
}



void FastJetFinder::init(JetMomentMap* mmap) {
  if ((m_area) && (mmap != NULL)) {
    mmap->schedule_jet_moment("area");
    mmap->schedule_jet_moment("area_error");
  }
}


void FastJetFinder::execute(JetCollection& inputJets) {
 // JetCollection tmp_list;

  // retrieve the map of the collection :
  JetMomentMap* themap = inputJets.get_JetMomentMap();
  // Copy Jet moment layout from input
//  themap->copy_structure(*(inputJets.get_JetMomentMap()));

  // Prevent problems with empty events :
  if (inputJets.size() == 0) return;

  // convert inputJets to psuedojets
  vector<PseudoJet> pjets;
  pjets.resize(inputJets.size()); // we know what will be the size

  JetCollection::const_iterator iter  = inputJets.begin();
  JetCollection::const_iterator iterE = inputJets.end();
  for (int ind=0; iter != iterE; ++iter, ++ind) {
    pjets[ind] = **iter;
    // store the jet's index (corresponds to index in initial input set)
    pjets[ind].set_user_index((*iter)->input_index());
    pjets[ind].set_cluster_hist_index(-1); // necessary?
  }

  ClusterSequence* clust_seq = 0;

  // Find jets with or without area ----------------------------------------------
  if (m_area) {          // area calculation turned on
    AreaDefinition area_def;
    if(m_areaChoice == voronoi_area) {
      VoronoiAreaSpec Varea_spec;
      area_def = AreaDefinition(Varea_spec);
    } else {
      GhostedAreaSpec Garea_spec = GhostedAreaSpec(m_ghost_etamax,m_repeat,m_ghost_area,m_grid_scatter,m_kt_scatter,m_mean_ghost_kt);
      area_def = AreaDefinition(Garea_spec,(AreaType)m_areaChoice);
    }
    clust_seq = new ClusterSequenceArea(pjets, *m_jet_def, area_def);
  } else {
    clust_seq = new ClusterSequence(pjets, *m_jet_def); 
  }

  vector<PseudoJet> output_jets;
  // Retrieve jets ----------------------------------------------
  if (m_inclusive) {
      output_jets = sorted_by_pt(clust_seq->inclusive_jets(m_ptmin));
      m_log << DEBUG << "Found " << output_jets.size() << " inclusive jets" << endl;
  }
  else {
    if (m_njets != -1) {
      // make sure we don't ask for more jets than there were inputs
      int njets = min(m_njets, (int)inputJets.size());
      output_jets = sorted_by_pt(clust_seq->exclusive_jets(njets));
      m_log << DEBUG << "Found " << output_jets.size() << " exclusive jets with m_njets = " << m_njets << endl;
    } else {
      output_jets = sorted_by_pt(clust_seq->exclusive_jets(m_dcut));
      m_log << DEBUG << "Found " << output_jets.size() << " exclusive jets with dcut = " << m_dcut << endl;
    }
  }

  // Remove the input jets from inputJets, but don't delete them (so that the
  // leaves of the ClusterSequence can refer back to them for SJ info like their
  // input index).
  JetCollection::iterator it, itE = inputJets.end();
  for (it = inputJets.begin(); it != itE; ++it) {
    (*it)->user_info<SpartyJetUserInfo>().should_delete();
    // We're losing our reference to this jet, so we'll never delete it.
    // Don't let its reference to its UI shared ptr count, so that when the copy
    //  we're making goes out of scope, everything gets cleaned up.  Otherwise
    //  a circular reference between the input jet and its UI survives forever.
    (*it)->user_info_shared_ptr().set_count((*it)->user_info_shared_ptr().use_count() - 1);
  }
  inputJets.clear();

  // Convert jets to SpartyJet format ----------------------------------------------
  for (unsigned i = 0; i < output_jets.size(); i++) {
    
    PseudoJet &jet = output_jets[i];
    // load into JetCollection
    inputJets.insert(jet, *clust_seq);
    Jet* t2jet = inputJets.back();
    
    if (m_area){
      ClusterSequenceArea *clust_seq_area = dynamic_cast<ClusterSequenceArea*> (clust_seq);
      themap->set_jet_moment("area", t2jet, clust_seq_area->area(jet));  // setting the area for the momentmap
      themap->set_jet_moment("area_error", t2jet, clust_seq_area->area_error(jet));
    }
  }
  
  // leave original structure for now
  //// set structure pointers for each jet (our way of mimicking FastJet behavior)
  //for (unsigned i = 0; i < inputJets.size(); ++i) {
  //  inputJets[i]->set_structure_shared_ptr(SharedPtr<PseudoJetStructureBase>(new JetStructure(inputJets[i], &inputJets)));
  //}
  
  if (output_jets.size() > 0)
    clust_seq->delete_self_when_unused();
  else
    delete clust_seq;

}

// warning: using this screws up history indices (not used for much)
void FastJetRecluster::execute(JetCollection& inputJets) {
  JetCollection single_jet, output;
  JetCollection::const_iterator it, itE;
  it = inputJets.begin();
  itE = inputJets.end();
  for (; it != itE; ++it) {
    Jet::jet_list_t constituents;
    Jet::constit_vect_t::iterator cit, citE;
    cit = (*it)->first_constituent();
    citE = (*it)->last_constituent();
    for (; cit != citE; ++cit)
      constituents.push_back(*cit);
    single_jet.deep_copy(constituents);
    
    // run algorithm on this jet's constituents
    FastJetFinder::execute(single_jet);
    output.deep_copy(single_jet);
    single_jet.clear_and_delete();
  }
  
  inputJets.clear_and_delete();
  inputJets.swap(output);
}

}  // namespace SpartyJet::FastJet
}  // namespace SpartyJet

