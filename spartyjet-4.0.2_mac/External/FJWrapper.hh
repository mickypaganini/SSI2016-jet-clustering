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

#ifndef _FJWRAPPER_HH_
#define _FJWRAPPER_HH_

#include <vector>

#include "fastjet/ClusterSequence.hh"
#include "fastjet/Selector.hh"

namespace fastjet {

class JetDefinition;

// CINT can't generate dictionary for templated CS constructor, so create a
//  non-templated helper version.
inline ClusterSequence make_ClusterSequence(const std::vector<PseudoJet>& jets,
                                     const JetDefinition& jd,
                                     const bool& writeout_combinations=false) {
  return ClusterSequence(jets, jd, writeout_combinations);
}

// CINT wants to call PseudoJet(TRootIOCtor*), so we need to prevent this calling
//  the templated PseudoJet(const L&) constructor by giving an explicit template
//  instantiation.
// This is just a copy of the default constructor PseudoJet().
template<> inline PseudoJet::PseudoJet(TRootIOCtor* const& ptr)
  : _px(0), _py(0), _pz(0), _E(0) {printf("Fake constructor\n"); _finish_init(); _reset_indices();}


// PyROOT won't do global operator overloading like s = Selector1 * Selector2,
//  so create some global functions and let __init__.py add them to Selector
inline Selector Selector_or (const Selector& s1, const Selector& s2) {return s1 || s2;}
inline Selector Selector_and(const Selector& s1, const Selector& s2) {return s1 && s2;}
inline Selector Selector_mul(const Selector& s1, const Selector& s2) {return s1 * s2;}

}

// CINT doesn't handle scoping properly; fix with a using directive in dict generation and compilation
#ifdef G__DICTIONARY
using namespace fastjet;
#endif

#ifdef __CINT__
using namespace fastjet;
#endif

#endif


