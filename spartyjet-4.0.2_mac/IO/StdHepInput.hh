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

#ifndef _STDHEP_INPUT_HH_
#define _STDHEP_INPUT_HH_

//SpartyJet
#include "JetCore/InputMaker.hh"
//StdHep
#include "External/STDHEP/src/inc/stdhep.h"
#include "External/STDHEP/src/inc/stdlun.h"
#include "External/STDHEP/src/inc/stdcnt.h"
#include "External/STDHEP/src/inc/stdhep_mcfio.h"
//C++
#include <stdio.h>
#include <stdlib.h>

namespace SpartyJet { 

class StdHepInput : public InputMaker {
public:

  StdHepInput() : InputMaker("StdHepInput"), m_skip_empty_events(true) {}
  
  StdHepInput(std::string filename) : InputMaker("StdHepInput"),
    m_skip_empty_events(true) {
    init(filename);
  }

  ~StdHepInput() {}
  virtual void init() {}
  virtual void init(std::string filename);
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index=0);
  virtual bool fillNextInput(JetCollection& inputList, int start_index=0);
  virtual void moveToEventN(int n);
  void set_skip_empty_events(bool);

  virtual void init_collection(JetCollection& coll);

protected:
  int ierr;
  int lbl;
  int istr;
  int nevt;
  bool m_skip_empty_events;
  std::string m_filename;
};

}  // namespace SpartyJet
#endif
