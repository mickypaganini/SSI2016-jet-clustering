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

#ifndef _HEPMC_INPUT_HH_
#define _HEPMC_INPUT_HH_

/// \class HepMCInput
/// \brief Reads HepMC-format input files
///
/// Uses our own code to avoid having to link against HepMC (one more
/// dependency...).  The format is assumed to be consistent with HepMC 2.X, as
/// described here:
/// http://lcgapp.cern.ch/project/simu/HepMC/20400/HepMC2_user_manual.pdf


#include "JetCore/InputMaker.hh"

namespace SpartyJet { 

class HepMCInput : public TextInputMaker {
public:

  HepMCInput(std::string filename) : TextInputMaker(filename, "HepMCInput"),
    invert(false),
    m_doParton(true),
    m_doStable(true)
  {}
  
  virtual ~HepMCInput() {}

  virtual void init();
  virtual bool fillNextInput(JetCollection& inputList, int start_index=0);
  virtual void moveToEventN(int n);

  virtual void init_collection(JetCollection& coll);

  void invert_input_order(bool in) {invert = in;}
  void usePartonLevel() {m_doStable = false; m_doParton = true;}

protected:

  bool invert;
  bool m_doParton;
  bool m_doStable;
};

}  // namespace SpartyJet
#endif
