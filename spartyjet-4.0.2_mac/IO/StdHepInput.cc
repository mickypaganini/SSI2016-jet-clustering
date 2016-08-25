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

#include "StdHepInput.hh"
#include "JetCore/JetCollection.hh"
#include "JetCore/CustomMessage.hh"
#include <iostream>

// this is to avoid a gcc 3.2.3 problem
char* operator+( std::streampos&, char* );
namespace SpartyJet { 

void StdHepInput::init(std::string filename) {
  unitIsGeV(); // SpartyJet default
  istr=0;
  nevt = 10000000;  // StdHep requires one to guess number of events
  // this number hardly matters
  ierr = StdHepXdrReadInit(const_cast<char*>(filename.c_str()),nevt,istr);
  m_currentEvnt = 0;
  m_filename = filename;
  if(ierr != 0)
	  m_log << ERROR << "StdHepInput file " << filename << " did not open correctly!" << std::endl;
}
  
void StdHepInput::init_collection(JetCollection &coll){
    coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
}


void StdHepInput::fillInput(int eventn, JetCollection &inputList, int start_index) {
  moveToEventN(eventn);
  fillNextInput(inputList, start_index);
}

bool StdHepInput::fillNextInput(JetCollection &inputList, int start_index) {
  
  double px, py, pz, E;
  int pdgId;

  inputList.clear();

  int num_inserted=start_index;
  
  JetMomentMap *map = inputList.get_JetMomentMap();

	// read next event
	ierr = StdHepXdrRead(&lbl,istr);
	if (ierr != 0) m_log << ERROR << "StdHepXdrRead returned error" << std::endl;
	m_currentEvnt++;
	if (ierr == 0) {
		do { 
			for (int i = 0; i < hepevt_.nhep; i++) {   // loop through particles
				if (hepevt_.isthep[i] != 1) continue;     // only want final state particles

				px = hepevt_.phep[i][0];          // [i][4] = mass if needed
				py = hepevt_.phep[i][1];
				pz = hepevt_.phep[i][2];
				E  = hepevt_.phep[i][3];
				pdgId = hepevt_.idhep[i];

				Jet* j = new Jet(px,py,pz,E, num_inserted);
				if (!m_reject_bad_input || check_4vector(j) ) inputList.push_back(j);
				num_inserted++;
				map->set_jet_moment("pdgId", j , pdgId); // add moment
			}

			if(m_skip_empty_events && inputList.size() == 0) {
				m_log << WARNING << "Skipping empty event." << std::endl;
				ierr = StdHepXdrRead(&lbl,istr);
				m_currentEvnt++;	
			} else {
				break;           // leave while loop and return true
			}

		} while(ierr == 0);   // if problem, quit loop and return false
	}
  
  if (ierr == 0 && hepevt_.nevhep != -2)
    return true;         // no problems
  else
    return false;        // problem found (or nevhep == -2, last event)
}

void StdHepInput::set_skip_empty_events(bool s) {
  m_skip_empty_events = s;
}


void StdHepInput::moveToEventN(int n) {
  if (n == m_currentEvnt) return;        // already happen to be at that event

  if (n < m_currentEvnt)
    init(m_filename);                  // start from beginning of file

  do {
    ierr = StdHepXdrRead(&lbl,istr);
    if(ierr != 0) {
			m_log << ERROR << "StdHepXdrRead returned error" << std::endl;
			return;                      // something went wrong, or end of file
		}
		m_currentEvnt++;	
  } while(n != m_currentEvnt);

  return;
}

}  // namespace SpartyJet
