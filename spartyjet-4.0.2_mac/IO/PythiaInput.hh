// Copyright (c) 2010-11, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
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

#ifndef _PYTHIA_INPUT_HH_
#define _PYTHIA_INPUT_HH_

// Class to run pythia generation and
// feed output to SpartyJet 


#include "JetCore/InputMaker.hh"
#include "TGenerator.h"

namespace SpartyJet { 

class PythiaInput : public HepInputMaker {
public:

  PythiaInput() : HepInputMaker()
  {
    m_currentEvnt = -1;
    m_name = "PythiaInput";
    m_log.set_name(m_name);
    m_doStable = true;
    m_doParton = false;
    m_minBarcode = 5;
    m_maxBarcode = 10;
    m_printEvent = false;
  }

  PythiaInput(TGenerator* pythia) : HepInputMaker()
  {
    m_pythia = pythia;
    m_currentEvnt = 0;
    m_name = "PythiaInput";
    m_log.set_name(m_name);
    m_doStable = true;
    m_doParton = false;
    m_minBarcode = 5;
    m_maxBarcode = 10;
    m_printEvent = false;
    init("");
  }
  
  virtual ~PythiaInput() {}

  virtual void init(std::string filename="");
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index=0);
  virtual bool fillNextInput(JetCollection& inputList, int start_index = 0);
  virtual void moveToEventN(int n);

  virtual void init_collection(JetCollection& coll);
  virtual void reject_bad_input(bool v) {m_reject_bad_input = v;}

  void setPythia(TGenerator* pythia) {m_pythia=pythia;}
  void printEvent(bool print=true) {m_printEvent = print;}
  void usePartonLevel() {m_doStable = false; m_doParton = true;}
  void set_barcodeCuts(int min, int max) {m_minBarcode = min; m_maxBarcode = max;}

protected:
  TGenerator* m_pythia;
  TClonesArray* m_particles;
  bool m_doParton;
  bool m_doStable;
  bool m_printEvent;
  int m_minBarcode;
  int m_maxBarcode;
};

}  // namespace SpartyJet
#endif
