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

#ifndef _PSEUDOJET_MOMENT_HH_
#define _PSEUDOJET_MOMENT_HH_

#include "JetCore/JetMoment.hh"
#include "JetTools/JetMomentTool.hh"
#include "fastjet/FunctionOfPseudoJet.hh"

#include <vector>

/** PseudoJetMoment and PseudoJetMomentTool provide simple SpartyJet wrappers
 *  for FastJet-based jet measurements, using FunctionOfPseudoJet.  To use a
 *  particle FunctionOfPseudoJet<class T> MyFunc, a ROOT dictionary must be
 *  generated for JetMoment<T> (see JetTools/JetToolsLinkDef.hpp).  To use
 *  MyFunc most easily in a PyROOT script, generate dictionaries for MyFunc and
 *  PseudoJetMomentTool<T> (see ExternalToolsLinkDef.hpp).
 *
 *  The result of these tools is to store a JetMoment<T> for each jet,
 *  accessible in the output ROOT file, e.g., through the GUI.
 *  
 *
 * Both PseudoJetMoment and PseudoJetMomentTool take a non-const pointer to a
 * function and adopt ownership -- don't pass the same function to multiple
 * tools!  If you want to use the same function more than once, use the tool
 * more than once, not the function.
 *
 *  See examples_py/FJToolExample.py for usage examples.
 */

namespace SpartyJet {
namespace FastJet {

/// JetMoment using a fastjet::FunctionOfPseudoJet
template <class T=float>
class PseudoJetMoment : public JetMoment<T> {
public:
  PseudoJetMoment(fastjet::FunctionOfPseudoJet<T>* func, std::string name) : JetMoment<T>(name), _func(func) {}
  virtual ~PseudoJetMoment() {delete _func;}

  virtual void CalculateMoment(Jet* j, JetCollection& jc) {JetMoment<T>::m_value = (*_func)(*j);}

protected:
  fastjet::FunctionOfPseudoJet<T>* _func;
};


/// Save a step: Directly creates a JetTool from a FunctionOfPseudoJet
template <class T=Double32_t>
class PseudoJetMomentTool : public JetMomentTool {
public:
  PseudoJetMomentTool(fastjet::FunctionOfPseudoJet<T>* func, std::string name)
    : JetMomentTool(name+"Tool", new PseudoJetMoment<T>(func, name)) {}
};


/// A (trivial) example of a PseudoJetMoment  (see ExternalTools/BoostVariables.hh for more examples)
class MassFunction : public fastjet::FunctionOfPseudoJet<Double32_t> {
  Double32_t result(const fastjet::PseudoJet& pj) const {return pj.m();}
};

} // namespace FastJet
} // namespace SpartyJet

#endif
