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

#include "CalchepPartonTextInput.hh"
#include "JetCore/JetCollection.hh"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// this is to avoid a gcc 3.2.3 problem
char* operator+( std::streampos&, char* );
namespace SpartyJet { 

void CalchepPartonTextInput::init() {
  unitIsGeV(); // SpartyJet default
  if (file != NULL)
    delete file;
  file = new ifstream(m_filename.c_str());

  m_currentEvnt = 0;
  num_in_particles = 0;
  num_fin_particles = 0;
  if(!file->is_open())
    m_log << ERROR << "CalchepPartonTextInput file " << m_filename << " did not open correctly!\n";
}


bool CalchepPartonTextInput::fillNextInput(JetCollection& inputList, int start_index) {
  double px,py,pz,E;
  double dummy;
  std::string word;   // dummy string variable

  inputList.clear();
  int num_inserted = start_index;
  
  *file >> dummy;      // get rid of the "Event" number
  for (int in = 0; in < num_in_particles; in++)
    *file >> dummy;
  for (int fin = 0; fin < num_fin_particles; fin++) {
    px = py = pz = -1;
    *file >> px >> py >> pz;
    if (px == -1 && py == -1 && pz == -1)
      return false;
    E = sqrt(px*px + py*py + pz*pz + mass[fin]*mass[fin]);
    Jet* j = new Jet(px, py, pz, E, num_inserted);
    if (!m_reject_bad_input || InputMaker::check_4vector(j)) {
      inputList.push_back(j);
      num_inserted++;
    }
  }
  getline(*file, word);
  
  if(inputList.size() > 0 && num_fin_particles) {         // event found with some jets
    m_currentEvnt++;
    return true;
  }
  else return false;                                         // no event found
}

void CalchepPartonTextInput::moveToEventN(int n) {

  init();                  // start from beginning of file
  
  char peek;
  m_currentEvnt = 0;
  std::string word;    // dummy variable
  double tempmass;
  bool end = false;

  do {
    peek = file->peek();
    if (peek == 35) {
      file->get();
      peek = file->peek();
      if (peek == 'T') {
        *file >> word;
        *file >> num_in_particles;
        *file >> word;
        *file >> num_fin_particles;
        if (num_fin_particles <=0)
          m_log << WARNING << "Number of final state particles invalid." << std::endl;
      } else if (peek == 'M') {   // assuming num_particles is already set, as it should be
        *file >> word;
        for (int in = 0; in < num_in_particles; in++)
          *file >> tempmass;
        for (int fin = 0; fin < num_fin_particles; fin++) {
          *file >> tempmass;
          mass.push_back(tempmass);
        }
      } else if (peek == 'N') {
        *file >> word;
        *file >> m_totalEvntN;
      } else if (peek == 'E') {
        getline(*file, word);
        m_currentEvnt = 0;
        for (int i = 0; i < n; i++) {
          getline(*file, word);
          m_currentEvnt++;
        }
        end = true;
      } else
        getline(*file, word);
    } else
      getline(*file, word);
  } while (*file && !end);
}

}  // namespace SpartyJet
