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

#ifndef _MULTI_INPUT_HH_
#define _MULTI_INPUT_HH_

#include "JetCore/InputMaker.hh"

#include <deque>
#include <string>

namespace SpartyJet { 

class MultiInput : public InputMaker {
public:

  MultiInput() : InputMaker("MultiInput") {}
  // Takes all IM*'s from inputMakers and stores.  Passed vector is cleared.
  //MultiInput(std::vector<InputMaker*> &inputMakers);

  void addInputMaker(InputMaker* inputMaker) {m_inputMakers.push_back(inputMaker);}

  virtual void init();
  virtual void fillInput(int eventn, JetCollection &inputList, int start_index = 0);
  virtual bool fillNextInput(JetCollection &inputList, int start_index = 0);
  virtual void moveToEventN(int n);

  virtual void init_collection(JetCollection &coll);

protected:

  std::deque<InputMaker*> m_inputMakers;
};

}  // namespace SpartyJet
#endif
