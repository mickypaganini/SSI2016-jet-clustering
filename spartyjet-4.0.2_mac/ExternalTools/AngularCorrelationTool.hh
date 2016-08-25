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

#ifndef _ANGULAR_CORRELATION_TOOL_HH_
#define _ANGULAR_CORRELATION_TOOL_HH_

#include "FastJetTools/FastJetTool.hh"
#include "JetCore/JetMomentMap.hh"
#include "AngularCorrelation.hh"
#include <vector>

namespace SpartyJet {
namespace FastJet {

/// stores jet moments corresponding to the angular correlation variables of
/// 1104.1646 Jankowiak & Larkoski

class AngularCorrelationTool : public PseudoJetTool {
public:
  AngularCorrelationTool(double prominence, bool erf, double dR, double R_max=0.0, std::string name = "AngularCorrelationTool")
    : PseudoJetTool(name), m_prominence(prominence), m_erf(erf), m_dR(dR), m_R_max(R_max) {}

  virtual void init(JetMomentMap* mmap=0);
  
  virtual void execute(fastjet::PseudoJet& pj);

private:
  GaussTable m_gaussTable;
  double m_prominence, m_erf, m_dR, m_R_max;
};

/// Stores angular scale and partial mass for each peak found, up to three
/// Rn, mn = 0 if n > nPeaks
inline void AngularCorrelationTool::init(JetMomentMap* map) {
  map->schedule_jet_moment<int>("nPeaks");
  map->schedule_jet_moment("R1");
  map->schedule_jet_moment("m1");
  map->schedule_jet_moment("R2");
  map->schedule_jet_moment("m2");
  map->schedule_jet_moment("R3");
  map->schedule_jet_moment("m3");
}

inline void AngularCorrelationTool::execute(fastjet::PseudoJet& pj) {
  ASF structure(pj.constituents(), m_gaussTable, m_dR, m_erf, m_R_max);
  std::vector<peak> peaks = structure.GetPeaksMinProm(m_prominence);
  set_jet_moment<int>("nPeaks", peaks.size());
  double R[3], m[3];
  for (unsigned int i = 0; i < 3; ++i) {
    R[i] = (peaks.size() > i) ? peaks[i].Rval : 0.0;
    m[i] = (peaks.size() > i) ? peaks[i].partialmass : 0.0;
  }
  set_jet_moment("R1", R[0]);
  set_jet_moment("m1", m[0]);
  set_jet_moment("R2", R[1]);
  set_jet_moment("m2", m[1]);
  set_jet_moment("R3", R[2]);
  set_jet_moment("m3", m[2]);
}

} // namespace FastJet
} // namespace SpartyJet


#endif

