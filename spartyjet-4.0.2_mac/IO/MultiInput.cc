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

#include "MultiInput.hh"
#include "JetCore/JetCollection.hh"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

namespace SpartyJet {

void MultiInput::init() {
  m_currentEvnt = 0;
  if (m_inputMakers.size() == 0)
    m_log << ERROR << "Calling init on MultiInput but no InputMakers are loaded!" << endl;
  // initialize the first inputmaker; the rest are initialized as needed
  m_inputMakers.front()->init();
}

// haven't tested if this works!
// really only makes sense to init one input maker, since this is generally
// used to schedule jet/event moments like PDGID's.  If they don't all store the
// same moments, you're in trouble anyway
void MultiInput::init_collection(JetCollection &coll) {
  m_inputMakers.front()->init_collection(coll);
}

void MultiInput::fillInput(int eventn, JetCollection &inputList, int start_index) {
  moveToEventN(eventn);
  fillNextInput(inputList, start_index);
}

bool MultiInput::fillNextInput(JetCollection &inputList, int start_index) {
  InputMaker *currentInput = m_inputMakers.front();
  
  // get event from current input maker
  while ( !(currentInput->fillNextInput(inputList, start_index)) ) {
    m_log << INFO << "Done with InputMaker " << currentInput->name() << endl;
    delete m_inputMakers.front();
    if (m_inputMakers.size() <= 1)
      return false;
    m_inputMakers.pop_front();
    currentInput = m_inputMakers.front();
    currentInput->init();
    m_log << INFO << "  Moving to " << currentInput->name() << endl;
  }
  // if we make it to the end, we filled an input
  m_currentEvnt++;
  return true;
}

void MultiInput::moveToEventN(int n) {
  m_log << INFO << "Moving to Event " << n  << " from Event " << m_currentEvnt << endl;
  if (n == m_currentEvnt) {
    m_log << INFO << "  Already there!" << endl;
    return; // already happen to be at that event
  }
  if (n < m_currentEvnt) {
    m_log << ERROR << "  Past that event, MultiInput doesn't support going back!" << endl;
    return;
  }
  int eventsNeeded = n - m_currentEvnt;
  while (eventsNeeded > 0) {
    InputMaker *currentInput = m_inputMakers.front();
    m_log << INFO << "  Trying to read " << eventsNeeded << " events from " << currentInput->name() << endl;
    int initialEvent = currentInput->current_event();
    currentInput->moveToEventN(initialEvent + eventsNeeded);
    int eventsMoved = currentInput->current_event() - initialEvent;
    m_log << INFO << "  Read " << eventsMoved << " events" << endl;
    m_currentEvnt += eventsMoved;
    eventsNeeded -= eventsMoved;
    if (eventsNeeded > 0) {
      // go to next inputMaker
      delete currentInput;
      m_inputMakers.pop_front();
      if (m_inputMakers.size() == 0) {
        m_log << ERROR << "Ran out of input events before reaching Event " << n << endl;
        return;
      }
      m_inputMakers.front()->init();
    }
    
  }
  return;
}

}  // namespace SpartyJet
