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

#ifndef _JETINPUTMAKER_HH_
#define _JETINPUTMAKER_HH_

#include "CustomMessage.hh"
#include "Jet.hh"

#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

namespace SpartyJet { 

class JetCollection;


/** \class InputMaker
 *  \brief The basic input facility for SpartyJet.
 *
 * An InputMaker wraps some external resource of particle information.
 * Generally this just consists of four vectors, but it can also include other
 * information such as PDG ID's, hard process partons, etc., which are stored
 * as jet or event moments in the input JetCollection.
 *
 * In the Python interface, a \c getInputMaker(filename) helper function creates
 * the appropriate InputMaker using the file name's extension.
 */

class InputMaker {
public:
  InputMaker(std::string name = "Input")
    : m_name(name), m_GeV(1.), m_MeV(0.001), m_currentEvnt(0),
      m_reject_bad_input(false), m_log(name) {}
  virtual ~InputMaker() {}
  
  /// Initialize.  This step should handle any expensive resource acquisition
  /// like opening files, since InputMakers are sometimes used in sequence.
  virtual void init() = 0;
  
  /// Read event number \param eventn from the input stream and store the
  /// particles in \param inputList.  Jets are stored with an index that starts
  /// with \param start_index.
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index=0) = 0;
  
  /// Read the next event from the stream and store in \param inputList.
  /// Jets are stored with an index that starts with \param start_index.
  virtual bool fillNextInput(JetCollection& inputList, int start_index=0) = 0;
  
  /// Advance the stream to event \param n
  virtual void moveToEventN(int n) = 0;
  
  /// \return the current event position in the stream.  This is the event that
  /// would be returned by the next \c fillNextInput() call.
  int current_event() {return m_currentEvnt;}

  /// Schedule any moments with \param coll's \c JetMomentMap that this
  /// InputMaker will store.
  virtual void init_collection(JetCollection &coll) {}

  /// Units are fixed by input. Following funcs should be called in the init() method
  /// Default is GeV
  void setGeVUnits(double unit) {m_GeV=unit; m_MeV=m_GeV/1000.;}
  void setMeVUnits(double unit) {m_MeV=unit; m_GeV=m_MeV*1000.;}
  void unitIsGeV() {m_GeV=1.; m_MeV=m_GeV/1000.;}
  void unitIsMeV() {m_MeV=1.; m_GeV=m_MeV*1000.;}

  double getGeV() {return m_GeV;}
  double getMeV() {return m_MeV;}

  std::string name() {return m_name;}
  void set_name(std::string name) {m_name = name;}
  
  /// If \param v is \c true, input four-vectors will be checked that they have
  /// a physical mass and positive energy
  virtual void reject_bad_input(bool v) {m_reject_bad_input = v;}
  static bool check_4vector(const Jet* jet) {return check_neg_energy(jet) && check_pz_energy(jet);}
  static bool check_neg_energy(const Jet* jet) {return jet->e()>0;}
  static bool check_pz_energy(const Jet* jet) {return std::fabs(jet->pz()) < jet->e();}

protected:
  
  std::string m_name;
  
  double m_GeV;
  double m_MeV;
  
  int m_currentEvnt;

  bool m_reject_bad_input; // if true
  
  Message m_log;
};



/// A generic type of InputMaker that reads events from a text file
/// The file should not be opened until init() is called.

class TextInputMaker : public InputMaker {
public:
  
  TextInputMaker(std::string filename, std::string name="TextInput")
    : InputMaker(name), file(NULL), m_filename(filename) {}

  virtual ~TextInputMaker() {delete file;}
  virtual void init() {}
  virtual void fillInput(int eventn, JetCollection& inputList, int start_index=0);
  virtual bool fillNextInput(JetCollection& inputList, int start_index=0) = 0;

  virtual void moveToEventN(int n) = 0;

protected:
  std::ifstream* file;
  std::string m_filename;
};


/// Text files are read sequentially, so they all do fillInput this way.
inline void TextInputMaker::fillInput(int eventn, JetCollection& inputList, int start_index) {
  moveToEventN(eventn);
  fillNextInput(inputList, start_index);
}


}  // namespace SpartyJet
#endif
