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

#ifndef _JETNEGENERGYTOOL_HH_
#define _JETNEGENERGYTOOL_HH_

/// JetNegEnergyTool. A JetTool to manage jet constituent with e<0

// TODO next :
// Use moment to store amounts of negative energy detected

#include "JetTool.hh"
#include <set>

namespace SpartyJet { 

class JetNegEnergyTool : public JetTool {
public :
  JetNegEnergyTool(std::string name) : JetTool(name), m_acquiring(true) {}

  /// execute() call either acquisition() or correction() depending on m_acquiring switch
  virtual void execute(JetCollection &inputJets);
  
protected:
  typedef std::set<Jet*> jet_list_t;

  /// acquisition is supposed to run before jet finding
  /// It keeps tracks of all jets constituent having negative energy, changing
  ///  the energy sign so jet finding can correctly handle this constituent
  void acquisition(JetCollection& inputJets);

  /// correction is supposed to run after jet finding
  /// It loop on constituents of each jets, checking if a constituent has been kept as negative.
  /// if so it substracts the amount of energy to the parent jet
  void correction(JetCollection& inputJets);

  jet_list_t m_neg_constits;
  bool m_acquiring;
};

}  // namespace SpartyJet
#endif
