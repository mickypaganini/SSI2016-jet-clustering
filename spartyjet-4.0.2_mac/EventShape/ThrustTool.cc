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

#include "ThrustTool.hh"
#include "JetCore/JetMomentMap.hh"
#include "JetCore/CommonUtils.hh"
#include "TLorentzVector.h"

using namespace std;

namespace SpartyJet {
namespace eventshape {

void ThrustTool::init(JetMomentMap* mmap) {
  if (mmap != NULL) {
    mmap->schedule_event_moment<Double32_t>("THRUST");
    mmap->schedule_event_moment<Double32_t>("THRUST_MINOR");
    mmap->schedule_event_moment<Double32_t>("THRUST_PHI");
  }
}

void ThrustTool::execute(JetCollection& theJets) {       
  double thrust_major = 0;  // should be float?!??
  double thrust_minor = 0;
  TVector3 thrust_v = thrust(&theJets, thrust_major, thrust_minor);

  // retrieve the map of the collection :
  JetMomentMap* themap = theJets.get_JetMomentMap();
  if (themap->num_event_moment() == 0) return;
  
  themap->set_event_moment<Double32_t>("THRUST", thrust_major);
  themap->set_event_moment<Double32_t>("THRUST_MINOR", thrust_minor);
  themap->set_event_moment<Double32_t>("THRUST_PHI", atan2(thrust_v.y(), thrust_v.x()));
}


TVector3 ThrustTool::thrust(const JetCollection* theParticles,
                   double& thrust_major, double& thrust_minor, bool useThreeD) {
  return thrust(theParticles->begin(), theParticles->end(), thrust_major, thrust_minor, useThreeD);
}

TVector3 ThrustTool::thrust(const jetIt_t iBeg, const jetIt_t iEnd,
       double& thrust_major, double& thrust_minor, bool useThreeD) {
  /* 
    This code is recopied from Atlas Code (Rolf Seuster)

    Finding the thrust axis in an event is not trivial.
    
    Here, we follow the procedure described in the PYTHIA manual JHEP 05 (2006) 026,
    also hep-ph/0603175. The approach is to use an iterative method, which usually
    converges quickly. As the minimization can find just a local minimum, different
    starting points for the thrust axis are tried. By default, first the direction
    of the four most energetic particles are tried, if their result disagrees, all
    16 permutations of the sum of all 4 particles are tried (with coefficients +- 1)
    
    Note, that the thrust is calculated for _ALL_ particles. If you want only a subset
    of particles, you have to apply a cut beforehand.
    See e.g. Reconstruction/EventShapes/EventShapeTools for examples.
  */

  TVector3 thrust(0,0,0);

  if (iBeg == iEnd){
   thrust_major = 0;
   thrust_minor = 0;
   return thrust;
  }


  int agree = 0;
  int disagree = 0;

  TVector3 n_0[20];
  short add0[20] = { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1 };
  short add1[20] = { 0, 1, 0, 0, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1,-1,-1,-1,-1 };
  short add2[20] = { 0, 0, 1, 0, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1 };
  short add3[20] = { 0, 0, 0, 1, 1,-1, 1,-1, 1,-1, 1,-1, 1,-1, 1,-1, 1,-1, 1,-1 };

  vector<Jet*> v_copy(4);

  // partial_sort_copy sorts a copy of the collection according to energy and
  //  returns only the first four elements (minimum of input collection size and
  //  pre-allocated output vector v_copy
  partial_sort_copy(iBeg, iEnd, 
                        v_copy.begin(), v_copy.end(),
                        JetSorter_E());


  int n_tests = 0;
  int max_tests = min<int>(20, distance(iBeg, iEnd));
  do {
    n_0[n_tests]=TVector3(0,0,0);

    // assign direction of four most energetic particles
    n_0[n_tests] +=
      add0[n_tests] * TVector3(v_copy.at(0)->px(), v_copy.at(0)->py(), v_copy.at(0)->pz()) +
      add1[n_tests] * TVector3(v_copy.at(1)->px(), v_copy.at(1)->py(), v_copy.at(1)->pz()) +
      add2[n_tests] * TVector3(v_copy.at(2)->px(), v_copy.at(2)->py(), v_copy.at(2)->pz()) +
      add3[n_tests] * TVector3(v_copy.at(3)->px(), v_copy.at(3)->py(), v_copy.at(3)->pz());

    if (!useThreeD)
      n_0[n_tests].SetZ(0);

    /* // my convention : x is always positive (thrust axis has two fold ambiguity)
      if(n_0[n_tests].x()<0)
      n_0[n_tests] = - n_0[n_tests]; */

    // protect against small number of input particles (smaller than 4!)
    if (n_0[n_tests].Mag() > 0)
      //n_0[n_tests] /= n_0[n_tests].Mag();
      n_0[n_tests] *= 1/n_0[n_tests].Mag();

    int loop = 0;
    bool run = false;
    do {
      TVector3 n_1(0,0,0);
      for (jetIt_t itr = iBeg; itr != iEnd; ++itr) {
         //  if(((*itr)->hlv()).vect().Dot(n_0[n_tests])>0)
         if ((*itr)->px() * n_0[n_tests].x() +
             (*itr)->py() * n_0[n_tests].y() +
             (*itr)->pz() * n_0[n_tests].z() > 0)
           n_1 += TVector3((*itr)->px(), (*itr)->py(), (*itr)->pz());
         else
           n_1 -= TVector3((*itr)->px(), (*itr)->py(), (*itr)->pz());
      }

      if (!useThreeD)
       n_1.SetZ(0);

      // protect against few number of input particles (smaller than 4!)
      if (n_1.Mag() > 0)
        n_1 *= 1/n_1.Mag();

      // has axis changed ? if so, try at most ten times (thrust axis has two fold ambiguity)
      run = (n_0[n_tests] != n_1) && (-n_0[n_tests] != n_1) && loop++ < 10;
      n_0[n_tests] = n_1;
    } while (run);
   
   // agrees or disagrees with first result ?
   //  thrust has a sign ambiguity
   if (n_tests > 0 && (n_0[0] == n_0[n_tests] || n_0[0] == -n_0[n_tests])) agree++;
   if (n_tests > 0 &&  n_0[0] != n_0[n_tests] && n_0[0] != -n_0[n_tests])  disagree++;
   
   // stop if four first tries give same result (no test for first try! )
   //  if not, try at most max_tests combinations
  } while ((disagree > 0 || agree < 4) && ++n_tests < max_tests);

  // now that we have the thrust axis, we determine the thrust value
  //  if the various calculations of the thrust axes disagree, try all
  //  and take the maximum, calculate minor and mayor axis
  n_tests = 0;


  do {
    double denominator = 0;
    double numerator_t = 0;
    double numerator_m = 0;
    for (jetIt_t itr = iBeg; itr != iEnd; ++itr) {
      TLorentzVector v((*itr)->px(), (*itr)->py(), (*itr)->pz(), (*itr)->e());
      TVector3 c(v.Vect());
      c.SetZ(0);
      numerator_t += fabs(c.Dot(n_0[n_tests]));
      numerator_m += (c.Cross(n_0[n_tests])).Mag();
      denominator += c.Mag();
    }

    if (numerator_t / denominator > thrust_major) {
      thrust_major = numerator_t / denominator;
      thrust_minor = numerator_m / denominator;
      thrust=n_0[n_tests];
    }
  } while (disagree > 0 && ++n_tests < max_tests);

  //     cout << "Calculation of Thrust gave: ( "
  // 	      << thrust.x() << " | "
  // 	      << thrust.y() << " |" << endl;

  // return StatusCode::SUCCESS;
  return thrust;
}



}  // namespace SpartyJet
};
