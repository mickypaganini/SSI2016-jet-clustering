//STARTHEADER
// $Id: CMSIterativeConePlugin.cc 1504 2009-04-10 13:39:48Z salam $
//
// Copyright (c) 2007-2011, Matteo Cacciari, Gavin P. Salam and Gregory Soyez
// Copyright (c) ????-????, CMS [for the iterative-cone code itself]
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
#include "fastjet/CMSIterativeConePlugin.hh"

// other stuff
#include <vector>
#include <list>
#include <sstream>
#include "SortByEt.h"

FASTJET_BEGIN_NAMESPACE      // defined in fastjet/internal/base.hh

using namespace std;
using namespace cms;

//------------------------------------------------------
// some tools
//------------------------------------------------------
template <class T> 
T deltaPhi (T phi1, T phi2) { 
  T result = phi1 - phi2;
  while (result > M_PI) result -= 2*M_PI;
  while (result <= -M_PI) result += 2*M_PI;
  return result;
}

template <class T>
T deltaR2 (T eta1, T phi1, T eta2, T phi2) {
  T deta = eta1 - eta2;
  T dphi = deltaPhi (phi1, phi2);
  return deta*deta + dphi*dphi;
}

//------------------------------------------------------


string CMSIterativeConePlugin::description () const {
  ostringstream desc;
  desc << "CMSIterativeCone plugin with R = " << theConeRadius << " and seed threshold = " << theSeedThreshold;
  return desc.str();
}

void CMSIterativeConePlugin::run_clustering(ClusterSequence & clust_seq) const {

  // This code is adapted from CMSIterativeConeAlgorithms.cc from the
  // CMSSW software. 
  // The adaptation is just meant to use 
  //   - the FastJet 4-vectors instead of the CMS ones
  //   - the FastJet clustering history structures instead of the 
  //     ProtoJet one used by CMS.

  //make a list of input objects ordered by ET
  //cout << "copying the list of particles" << endl;
  list<PseudoJet> input;
  for (unsigned int i=0 ; i<clust_seq.jets().size() ; i++) {
    input.push_back(clust_seq.jets()[i]);
  }
  NumericSafeGreaterByEt<PseudoJet> compCandidate;
  //cout << "sorting" << endl;
  input.sort(compCandidate);

  //find jets
  //cout << "launching the main loop" << endl;
  while( !input.empty() && (input.front().Et() > theSeedThreshold )) {
    //cone centre 
    double eta0=input.front().eta();
    double phi0=input.front().phi();
    //protojet properties
    double eta=0;
    double phi=0;
    double et=0;
    //list of towers in cone
    list< list<PseudoJet>::iterator> cone;
    for(int iteration=0;iteration<100;iteration++){
      //cout << "iterating" << endl;
      cone.clear();
      eta=0;
      phi=0;
      et=0;
      for(list<PseudoJet>::iterator inp=input.begin();
	  inp!=input.end();inp++){
	const PseudoJet tower = *inp;	
	if( deltaR2(eta0,phi0,tower.eta(),tower.phi()) < 
	    theConeRadius*theConeRadius) {
	  double tower_et = tower.Et();	  
          cone.push_back(inp);
          eta+= tower_et*tower.eta();
          double dphi=tower.phi()-phi0;
          if(dphi>M_PI) dphi-=2*M_PI;
          else if(dphi<=-M_PI) dphi+=2*M_PI;
          phi+=tower_et*dphi;
          et +=tower_et;
        }
      }
      eta=eta/et;
      phi=phi0+phi/et;
      if(phi>M_PI)phi-=2*M_PI;
      else if(phi<=-M_PI)phi+=2*M_PI;
      
      if(fabs(eta-eta0)<.001 && fabs(phi-phi0)<.001) break;//stable cone found
      eta0=eta;
      phi0=phi;
    }

    //cout << "make the jet final" << endl;

    //make a final jet and remove the jet constituents from the input list 
    //  InputCollection jetConstituents;     
    //  list< list<InputItem>::iterator>::const_iterator inp;
    //  for(inp=cone.begin();inp!=cone.end();inp++)  {
    //    jetConstituents.push_back(**inp);
    //    input.erase(*inp);
    //  }
    //  fOutput->push_back (ProtoJet (jetConstituents));
    //
    // IMPORTANT NOTE:
    //   while the stability of the stable cone is tested using the Et
    //   scheme recombination, the final jet uses E-scheme
    //   recombination.
    //
    // The technique used here is the same as what we already used for
    // SISCone except that we act on the 'cone' list.
    // We successively merge the particles that make up the cone jet
    // until we have all particles in it.  We start off with the zeroth
    // particle.
    list< list<PseudoJet>::iterator>::const_iterator inp;
    inp = cone.begin();
    int jet_k = (*inp)->cluster_hist_index();
    // gps tmp
    //float px=(*inp)->px(), py=(*inp)->py(), pz=(*inp)->pz(), E = (*inp)->E();

    // remove the particle from the list and jump to the next one
    input.erase(*inp);
    inp++;

    // now loop over the remaining particles
    while (inp != cone.end()){
      // take the last result of the merge
      int jet_i = jet_k;
      // and the next element of the jet
      int jet_j = (*inp)->cluster_hist_index();
      // and merge them (with a fake dij)
      double dij = 0.0;

      // create the new jet by hand so that we can adjust its user index
      // Note again the use of the E-scheme recombination here!
      PseudoJet newjet = clust_seq.jets()[jet_i] + clust_seq.jets()[jet_j];

      // gps tmp to try out floating issues
      //px+=(*inp)->px(), py+=(*inp)->py(), pz+=(*inp)->pz(), E += (*inp)->E();
      //PseudoJet newjet(px,py,pz,E);
        
      clust_seq.plugin_record_ij_recombination(jet_i, jet_j, dij, newjet, jet_k);

      // remove the particle from the list and jump to the next one
      input.erase(*inp);
      inp++;
    }

    // we have merged all the jet's particles into a single object, so now
    // "declare" it to be a beam (inclusive) jet.
    // [NB: put a sensible looking d_iB just to be nice...]
    double d_iB = clust_seq.jets()[jet_k].perp2();
    clust_seq.plugin_record_iB_recombination(jet_k, d_iB);


  } //loop over seeds ended

    
}

FASTJET_END_NAMESPACE      // defined in fastjet/internal/base.hh
