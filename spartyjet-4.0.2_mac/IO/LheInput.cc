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

#include "LheInput.hh"
#include "JetCore/JetCollection.hh"

#include <iostream>
#include <sstream>
using namespace std;
// this is to avoid a gcc 3.2.3 problem
char* operator+( std::streampos&, char* );
namespace SpartyJet { 

void LheInput::init() {
  if (file != NULL) delete file;
  file = new ifstream(m_filename.c_str());

  unitIsGeV(); // SpartyJet default

  m_currentEvnt = 0;
  invert = false;
  if (!file->is_open())
    m_log << ERROR << "LheInput file " << m_filename << " did not open correctly!" << std::endl;
}

void LheInput::init_collection(JetCollection& coll){
    coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
}

bool LheInput::fillNextInput(JetCollection &inputList, int start_index) {
  std::string line;
  double px, py, pz, E, mass;
  int pdgid, status, mother1, mother2, color1, color2;
  int num_inserted = 0;

  JetMomentMap* map = inputList.get_JetMomentMap();

  // Read from file
  while (*file) {
    //  Look for <event> tag
    getline(*file, line);
    if (line.find("<event>") != std::string::npos) {
      // First Line after <event> contains event information
      getline(*file, line);

      // Fill event info

      // Get particle info
      getline(*file, line); // 1st particle
      while (line.find("</event>") == std::string::npos) {
        std::istringstream iss(line);
        iss >> pdgid >> status >> mother1 >> mother2 >> color1 >> color2 >> px >> py >> pz >> E >> mass;

        bool isStable = (status==1 );
        bool isParton = (status==22 || status==23);

        if (((m_doParton && isParton) || (m_doStable && isStable)) && px != -1 && py != -1 && pz != -1 && E != -1) {
          Jet* j = new Jet(px, py, pz, E, num_inserted+start_index);
          if (!m_reject_bad_input || check_4vector(j)) inputList.push_back(j);
          map->set_jet_moment("pdgId", j, pdgid); // add moment
          num_inserted++;
        }
        // Skip any comment lines in the file
        do {
          getline(*file, line);
        }	while (line[0]=='#');
      }
    }

    if (num_inserted > 0) {
      m_currentEvnt++;
      return true;
    }
  } // end while(*file)

  // Something wrong, shouldn't have reached here
  return false;
}

void LheInput::moveToEventN(int n) {
  std::string line;
  if (n == m_currentEvnt) return; // already happen to be at that event
  init();                         // start from beginning of file
  if (m_currentEvnt == n) return; // if n == 0, this is needed

  while (*file) {
    getline(*file, line);
    if (line.find("<event>") != std::string::npos) {
      m_currentEvnt++;
      if (m_currentEvnt == n) return;
    }
  }
  return;
}

}  // namespace SpartyJet
