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

#include "StdTextInput.hh"
#include "JetCore/JetCollection.hh"
#include <iostream>
using namespace std;
// this is to avoid a gcc 3.2.3 problem
char* operator+( std::streampos&, char* );
namespace SpartyJet { 

void StdTextInput::init() {
  if (file != NULL)
    delete file;
  file = new ifstream(m_filename.c_str());

  unitIsGeV(); // SpartyJet default

  m_currentEvnt = 0;
  invert = false;
  if (!file->is_open())
    m_log << ERROR << "StdTextInput :  file " << m_filename << " did not open correctly!\n";
}

bool StdTextInput::fillNextInput(JetCollection& inputList, int start_index) {
  char peek;
  double px, py, pz, E;
  bool end = false;

  inputList.clear();

  int num_inserted = start_index;

  do {
    peek = file->peek();
    if (peek == 'n' || peek == 'N') {                           // n or N (new event)
      file->ignore(1000,'\n');
      if (inputList.size() > 0)
        end = true;
    } else if (peek == 'e' || peek == 'E') {                    // e or E (end of file)
      end = true;
    } else if (peek == 46) {                                    // dot
      file->get();
      peek = file->peek();
      file->ignore(1000,'\n');
      if (peek == 'e' || peek == 'E') {                         // .e or .E also ends the event
        if (inputList.size() > 0)
          end = true;
      }
    } else if (peek == 47 || peek ==35) {                       // slash or #
      file->ignore(1000,'\n');
    } else {                                                    // data
      px = py = pz = E = -1;
      if (invert)
        *file >> px >> py >> pz >> E;
      else
        *file >> E >> px >> py >> pz;
      file->ignore(1000,'\n');
      if (px != -1 && py != -1 && pz != -1 && E != -1) {
        Jet* j = new Jet(px,py,pz,E, num_inserted);
        if (!m_reject_bad_input || InputMaker::check_4vector(j) ) {
          inputList.push_back(j);
          num_inserted++;
        }
      }
    }
  } while (*file && !end);
  
  if (inputList.size() > 0) {                              // event found with some jets
    m_currentEvnt++;
    return true;
  }
  return false;                                            // no event found
}

void StdTextInput::moveToEventN(int n) {
  if (n == m_currentEvnt) return;        // already happen to be at that event
  
  init();                                // start from beginning of file

  char peek;
  int jets = 0;
  double px, py, pz, E;                  // dummy variables
  bool end = false;

  if (n == m_currentEvnt) return;

  do {
    peek = file->peek();
    if (peek == 'n' || peek == 'N') {                           // n or N (new event)
      file->ignore(1000,'\n');
      if (jets > 0) {
        m_currentEvnt++;
        jets = 0;
        if (m_currentEvnt == n) return;
      }
    } else if (peek == 'e' || peek == 'E') {                    // e or E (end of file)
      end = true;
      if (jets > 0) {
        m_currentEvnt++;
        jets = 0;
        if (m_currentEvnt == n) return;
      }
    } else if (peek == 46) {                                    // dot
      file->get();
      peek = file->peek();
      file->ignore(1000,'\n');
      if (peek == 'e' || peek == 'E') {                         // .e or .E also new event
        if (jets > 0) {
          m_currentEvnt++;
          jets = 0;
          if (m_currentEvnt == n) return;
        }
      }
    } else if (peek == 47 || peek ==35) {                       // dot, slash or #
      file->ignore(1000,'\n');
    } else {                                                    // data
      *file >> px >> py >> pz >> E;
      jets++;
      file->ignore(1000,'\n');
    }
  } while (*file && !end);
  return;
}

}  // namespace SpartyJet
