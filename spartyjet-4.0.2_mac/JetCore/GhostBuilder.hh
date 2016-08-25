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

#ifndef _GHOSTBUILDER_HH_
#define _GHOSTBUILDER_HH_

///////////////////////////////////////////
///
/// Defines some methods to add ghost proto-jets to 
/// a jet collection.
/// Could be purely random, on a grid, on a grid+random fluctuations...
///
////////////////////////////////////////////

#include "TRandom3.h"
#include "JetCollection.hh"
#include "JetMomentMap.hh"

namespace SpartyJet {

class GhostBuilder {
public:
  GhostBuilder(int n) : m_num(n) , m_phimin(-M_PI) , m_phimax(M_PI), m_rapmin(-5.), m_rapmax(5.) {}
  virtual ~GhostBuilder(){}
  
  virtual void add_ghosts(JetCollection* coll){};
  virtual void reconfigure(int nghosts, float rapmin, float rapmax, float phimin, float phimax) {
    m_num = nghosts; m_phimin = phimin;m_phimax = phimax;
    m_rapmin = rapmin;m_rapmax = rapmax;
  }

protected:
  int m_num;
  float m_phimin, m_phimax;
  float m_rapmin, m_rapmax;
};


class GhostBuilderRandom : public GhostBuilder {
public:
  GhostBuilderRandom(int n) : GhostBuilder(n) {}
  
  virtual void add_ghosts(JetCollection* coll) {
    int index = coll->size();
   
    JetMomentMap* themap = coll->get_JetMomentMap();

    for (int i = 0; i < m_num; i++) {
      double rap = rnd.Uniform(m_rapmin, m_rapmax);
      double phi = rnd.Uniform(m_phimin, m_phimax);
      Jet* j = new Jet(10e-16, 0, 0, 10e-15, index);
      j->SetPtEtaPhiM(10e-16, rap, phi, 0);
      themap->set_jet_moment<int>("pdgId", j, 0);
      coll->push_back(j);
      index++;
    }
  }
  
protected:
  TRandom3 rnd;
};

}


#endif
