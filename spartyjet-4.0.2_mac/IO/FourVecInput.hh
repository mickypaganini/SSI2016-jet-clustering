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

#ifndef _FOURVEC_INPUT_HH_
#define _FOURVEC_INPUT_HH_

#include "JetCore/InputMaker.hh"

namespace SpartyJet {


/// This class serves as an interface to some other piece of code that generates input particles.
/*
 * It is templated on a class T that it asks for four vectors.  T should provide:
 * bool T::empty()       : true if no events left
 * bool T::event_done()  : returns false if there are more particles left in this event
 * const V& T::next()    : returns some vector that a Jet or PseudoJet can be made from
 *                           -- this includes anything with xyzt access via v[0-3]
 * Notes:
 * - only saves 4-vectors; no indices or PDG IDs
 * - not tested yet
 * - will work in C++ code where you have defined some reader class.  Not in
 *   Python yet, since PyROOT (or SWIG) would need to know about the reader class.
 */ 
template<class T>
class FourVecInput : public InputMaker {
public:

  FourVecInput(T& reader) : InputMaker("FourVecInput"), m_reader(reader) {}

  virtual void init() {}
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index=0);
  virtual bool fillNextInput(JetCollection& inputList, int start_index=0);
  virtual void moveToEventN(int n);

  virtual void init_collection(JetCollection& coll) {}

protected:
  /// this object is where we read four-vectors from
  T& m_reader;
};

template<class T>
void FourVecInput<T>::fillInput(int eventn, JetCollection& inputList, int start_index) {
  moveToEventN(eventn);
  fillNextInput(inputList, start_index);
}

template<class T>
bool FourVecInput<T>::fillNextInput(JetCollection& inputList, int start_index) {
  inputList.clear();
    
  if (m_reader.empty()) return false;
  do {
    try {
      inputList.push_back(new Jet(m_reader.next()));
    } catch (...) {
      m_log << ERROR << "Unhandled exception in 4-vec reader!  Ignorning and moving on." << std::endl;
    }
  } while (!m_reader.event_done());

  if (inputList.size() > 0) {
	  m_currentEvnt++;
	  return true;
  }
  return false;
}

template<class T>
void FourVecInput<T>::moveToEventN(int n) {
  if (n == m_currentEvnt) return;        // already happen to be at that event

  if (n < m_currentEvnt) {
    m_log << ERROR << "Can't move backward in FourVecInput!  (Tred to move from event " << m_currentEvnt << " to " << n << std::endl;
    return;
  }
  
  while (m_currentEvnt < n && !m_reader.empty()) {
    do m_reader.next(); while (!m_reader.event_done());
    m_currentEvnt++;
  }
}

}  // namespace SpartyJet
#endif
