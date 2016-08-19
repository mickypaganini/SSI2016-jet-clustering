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

#include "CalorimeterSimTool.hh"
#include "JetCore/JetCollection.hh"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace SpartyJet { 

CalorimeterSimTool::CalorimeterSimTool(float etaLimit, float deltaEta, float deltaPhi, bool set2Pi): 
  JetTool("CalorimeterSimTool"),
  m_minEta(-1*etaLimit),
  m_maxEta(   etaLimit),
  m_useZeroTo2Pi(set2Pi)
{
  SetTowerSize(deltaEta, deltaPhi);
  m_nEta = (int)(2 * etaLimit / m_deltaEta);
}


void CalorimeterSimTool::init(JetMomentMap* mmap) {
  // Create Tower Grid
  m_log << WARNING << "Creating tower grid of: " 
                   << m_nEta << " bins in eta of size " << m_deltaEta << " and: " 
                   << m_nPhi << " bins in phi of size " << m_deltaPhi << std::endl;
  m_towerEnergy     = vector<vector<double> >(m_nEta, vector<double>(m_nPhi, 0.));
  m_towerNparticles = vector<vector<int> >   (m_nEta, vector<int>   (m_nPhi, 0));
}


void CalorimeterSimTool::execute(JetCollection& theJets) {
  // Loop on all jets and insert into calorimeter grid
  JetCollection::iterator jit  = theJets.begin(); 
  JetCollection::iterator jitE = theJets.end(); 
  int etaBin, phiBin;
  for (; jit != jitE; ++jit) {
    GetEtaPhiBins(*jit, etaBin, phiBin);
    if (etaBin > -1) {
      m_towerEnergy[etaBin][phiBin] += (*jit)->e();
      m_towerNparticles[etaBin][phiBin]++;
    }
  }

  // don't save old jets
  theJets.clear_and_delete();

  // Loop on all towers, if particle was inserted, create new Jet and store
  Jet::jet_list_t tempJets;
  int index = 0;
  for (int eBin = 0; eBin < m_nEta; eBin++) {
    for (int pBin = 0; pBin < m_nPhi; pBin++) {
      if (m_towerNparticles[eBin][pBin] > 0) {
        double eta = m_minEta + (eBin + 0.5) * m_deltaEta;
        double phi = (pBin + 0.5) * m_deltaPhi;
        if (!m_useZeroTo2Pi) phi = to_minusPI_PI(phi);
        double energy = m_towerEnergy[eBin][pBin] ;
        double pt = energy/cosh(eta);
        double px = pt*cos(phi);
        double py = pt*sin(phi);
        double pz = pt*sinh(eta);
        tempJets.push_back(new Jet(px, py, pz, energy, index));
        ++index;
      }
    }
  }
  // copy into theJets
  theJets.deep_copy(tempJets);

  // Reset tower grid
  for (int i = 0; i < m_nEta; i++) {
    fill(m_towerEnergy[i].begin(), m_towerEnergy[i].end(), 0.);
    fill(m_towerNparticles[i].begin(), m_towerNparticles[i].end(), 0);
  }
}


void CalorimeterSimTool::GetEtaPhiBins(Jet* jet, int& etaBin, int& phiBin) {
  if ((jet->eta() < m_minEta) || (jet->eta() > m_maxEta)) {
    etaBin = -1;
    phiBin = -1;
  } else {
    float phi = jet->phi(); // PseudoJet::phi() returns [0,2pi]
    double absEta = jet->eta() - m_minEta;
    etaBin = (int)(absEta / m_deltaEta);
    phiBin = (int)(phi / m_deltaPhi);
  }
}


} // end SpartyJet namespace
