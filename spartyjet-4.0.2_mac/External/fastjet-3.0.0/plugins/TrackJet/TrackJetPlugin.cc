//STARTHEADER
// $Id: TrackJetPlugin.cc 2577 2011-09-13 15:11:38Z salam $
//
// Copyright (c) 2007-2011, Matteo Cacciari, Gavin P. Salam and Gregory Soyez
//
//----------------------------------------------------------------------
// This file is part of FastJet.
//
//  FastJet is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  The algorithms that underlie FastJet have required considerable
//  development and are described in hep-ph/0512210. If you use
//  FastJet as part of work towards a scientific publication, please
//  include a citation to the FastJet paper.
//
//  FastJet is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with FastJet. If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------
//ENDHEADER

// fastjet stuff
#include "fastjet/ClusterSequence.hh"
#include "fastjet/TrackJetPlugin.hh"

// other stuff
#include <list>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>

FASTJET_BEGIN_NAMESPACE      // defined in fastjet/internal/base.hh

using namespace std;

class TrackJetParticlePtr{
public:
  TrackJetParticlePtr(int i_index, double i_perp2)
    :  index(i_index), perp2(i_perp2){}

  int index;
  double perp2;

  bool operator <(const TrackJetParticlePtr &other) const { 
    return perp2>other.perp2;
  }
};

string TrackJetPlugin::description () const {
  ostringstream desc;
  desc << "TrackJet algorithm with R = " << R();
  return desc.str();
}

void TrackJetPlugin::run_clustering(ClusterSequence & clust_seq) const {
  // we first need to sort the particles in pt
  vector<TrackJetParticlePtr> particle_list;

  const vector<PseudoJet> & jets = clust_seq.jets();  
  int index=0;
  for (vector<PseudoJet>::const_iterator mom_it = jets.begin(); mom_it != jets.end(); mom_it++){
    particle_list.push_back(TrackJetParticlePtr(index, mom_it->perp2()));
    index++;
  }

  // sort the particles into decreasing pt
  stable_sort(particle_list.begin(), particle_list.end());


  // if we're using a recombination scheme different from the E scheme,
  // we first need to update the particles' energy so that they
  // are massless (and rapidity = pseudorapidity)
  vector<PseudoJet> tuned_particles = clust_seq.jets();
  vector<PseudoJet> tuned_tracks = clust_seq.jets();
  for (vector<PseudoJet>::iterator pit = tuned_particles.begin();
       pit != tuned_particles.end(); pit++)
    _jet_recombiner.preprocess(*pit);
  for (vector<PseudoJet>::iterator pit = tuned_tracks.begin();
       pit != tuned_tracks.end(); pit++)
    _track_recombiner.preprocess(*pit);


  // we'll just need the particle indices for what follows
  list<int> sorted_pt_index;
  for (vector<TrackJetParticlePtr>::iterator mom_it = particle_list.begin();
       mom_it != particle_list.end(); mom_it++)
    sorted_pt_index.push_back(mom_it->index);
  
  // now start building the jets
  while (sorted_pt_index.size()){
    // note that here 'track' refers to the direction we're using to test if a particle belongs to the jet
    // 'jet' refers to the momentum of the jet
    // the difference between the two is in the recombination scheme used to compute the sum of 4-vectors
    int current_jet_index = sorted_pt_index.front();
    PseudoJet current_jet   = tuned_particles[current_jet_index];
    PseudoJet current_track = tuned_tracks[current_jet_index];

    // remove the first particle from the available ones    
    list<int>::iterator index_it = sorted_pt_index.begin();
    sorted_pt_index.erase(index_it);

    // start browsing the remaining ones
    index_it = sorted_pt_index.begin();
    while (index_it != sorted_pt_index.end()){
      const PseudoJet & current_particle = tuned_particles[*index_it];
      const PseudoJet & current_particle_track = tuned_tracks[*index_it];

      // check if the particle is within a distance R of the jet
      double distance2 = current_track.plain_distance(current_particle_track);
      if (distance2 <= _radius2){
	// add the particle to the jet
	PseudoJet new_track;
	PseudoJet new_jet;
	_jet_recombiner.recombine(current_jet, current_particle, new_jet);
	_track_recombiner.recombine(current_track, current_particle_track, new_track);

	int new_jet_index;
	clust_seq.plugin_record_ij_recombination(current_jet_index, *index_it, distance2, new_jet, new_jet_index);

	current_jet = new_jet;
	current_track = new_track;
	current_jet_index = new_jet_index;

	// particle has been clustered so remove it from the list
	sorted_pt_index.erase(index_it);

	// and don't forget to start again from the beginning
	//  as the jet axis may have changed
	index_it = sorted_pt_index.begin();
      } else {
	index_it++;
      }
    }

    // now we have a final jet, so cluster it with the beam
    clust_seq.plugin_record_iB_recombination(current_jet_index, _radius2);
  }
    
}

FASTJET_END_NAMESPACE      // defined in fastjet/internal/base.hh
