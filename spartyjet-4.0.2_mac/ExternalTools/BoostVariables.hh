// Copyright (c) 2011 Christopher Vermilion
//
//----------------------------------------------------------------------
//  This file is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  This file is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  The GNU General Public License is available at
//  http://www.gnu.org/licenses/gpl.html or you can write to the Free Software
//  Foundation, Inc.:
//      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//----------------------------------------------------------------------

#ifndef _BOOSTVARIABLES_HH_
#define _BOOSTVARIABLES_HH_

#include "fastjet/FunctionOfPseudoJet.hh"

#ifndef G__DICTIONARY
typedef double Double32_t; // ROOT will store as 32-bit, but in code is double
#endif

#include <vector>
#include <cmath>

FASTJET_BEGIN_NAMESPACE

/// Measures the mass of the minimum-mass pairing of subjets
/// If the PJ has pieces, all pairs of pieces are tried; otherwise we try
///  exclusive_subjets_up_to(3).
/// If only two subjets are found, returns the smaller subjet mass; if only one
///  subjet, returns 0.
class MinMassFunction : public fastjet::FunctionOfPseudoJet<Double32_t> {
  Double32_t result(const fastjet::PseudoJet& pj) const {
    if (!pj.has_structure()) return 0.0;
    std::vector<fastjet::PseudoJet> subjets;
    // get pieces if they exists
    if (pj.has_pieces()) {
      subjets = pj.pieces();
    }
    if (subjets.size() <= 2) {
      // no pieces or fewer than three
      if (pj.has_exclusive_subjets())
        subjets = pj.exclusive_subjets_up_to(3);
    }
    // no constituents (shouldn't be possible!)
    if (subjets.size() == 0) return 0.0;
    // only one constituent
    if (subjets.size() < 2) return subjets[0].m();
    // two constituents; take min. subjet mass
    if (subjets.size() == 2) return std::min(subjets[0].m(), subjets[1].m());
    
    // find minimum mass pairing
    double minMass = 1000000.0;
    for (unsigned i = 0; i < subjets.size() - 1; ++i) {
      for (unsigned j = i+1; j < subjets.size(); ++j) {
        if ((subjets[i] + subjets[j]).m() < minMass) {
          minMass = (subjets[i] + subjets[j]).m();
        }
      }
    }
    return minMass;
  }
};



/// zcell a la "Thaler & Wang top tagger"
class zCellFunction : public fastjet::FunctionOfPseudoJet<Double32_t> {
public:
  Double32_t result(const fastjet::PseudoJet& pj) const {
    if (!pj.has_pieces())
      return 0.0;
    std::vector<fastjet::PseudoJet> pieces = pj.pieces();
    
    // this function only sensible for a 2->1 splitting
    if (pieces.size() != 2)
      return 0.0;
  
    return std::min(pieces[0].E(), pieces[1].E())/pj.E();
  }
};



/// "ATLAS top tagger" z_cut[i] variables
class zCutFunction : public fastjet::FunctionOfPseudoJet<Double32_t> {
public:
  zCutFunction(unsigned int n) : m_n(n) {}
  
  Double32_t result(const fastjet::PseudoJet& pj) const {
    if (!pj.has_exclusive_subjets())
      return 0.0;
    
    // one of the N exclusive subjets corresponds to the merging we want
    std::vector<fastjet::PseudoJet> subjets = pj.exclusive_subjets_up_to(m_n);
    if (subjets.size() < 1) return 0.0;
    
    // in particular, the one with largest dmerge (this would be the next to uncluster)
    int max_i = 0;
    double max_dcut = subjets[0].exclusive_subdmerge(1);
    for (unsigned j = 1; j < subjets.size(); ++j) {
      double dcut_j = subjets[j].exclusive_subdmerge(1);
      if (dcut_j > max_dcut) {
        max_dcut = dcut_j;
        max_i = j;
      }
    }
    return max_dcut / (max_dcut + subjets[max_i].m2());
  }
private:
  unsigned int m_n;
};



FASTJET_END_NAMESPACE

#endif
