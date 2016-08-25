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

#ifndef _CALORIMETERSIMTOOL_HH_
#define _CALORIMETERSIMTOOL_HH_

#include "JetCore/JetTool.hh"
#include <math.h>
namespace SpartyJet { 

class Jet;

class CalorimeterSimTool : public JetTool {
public:
  CalorimeterSimTool(std::string name) : JetTool(name) {}
  CalorimeterSimTool(float etaLimit, float deltaEta, float deltaPhi, bool set2PI=true);

  virtual void init(JetMomentMap* mmap);
  virtual void execute(JetCollection& inputJets);

  void SetEtaLimit(float etaLimit)        {m_minEta = -1.*etaLimit; m_maxEta = etaLimit; }
  void SetTowerSize(float eta, float phi) {m_deltaEta = eta; m_nPhi = (int)floor(2.*M_PI/phi+0.5); m_deltaPhi= 2.*M_PI/m_nPhi; }
  void GetEtaPhiBins(Jet* j,int& etaBin,int& phiBin);
  void SetZeroTo2PI(bool b) {m_useZeroTo2Pi = b;}

private:
  float m_minEta;
  float m_maxEta;
  float m_deltaEta;
  float m_deltaPhi;
  int   m_nEta;
  int   m_nPhi;
  bool  m_useZeroTo2Pi;

  std::vector<std::vector<double> > m_towerEnergy;
  std::vector<std::vector<int> >    m_towerNparticles;

};
} // end of SpartyJet namespace

#endif
