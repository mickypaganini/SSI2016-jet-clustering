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

#ifndef _LHE_INPUT_HH_
#define _LHE_INPUT_HH_

#include "JetCore/InputMaker.hh"

namespace SpartyJet { 

class LheInput : public TextInputMaker {
public:

  LheInput(std::string filename) : TextInputMaker(filename, "LHEInput"),
    invert(false),
    m_doParton(false),
    m_doStable(true)
  {}
  
  virtual ~LheInput() {}

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
