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


#include "HepMCInput.hh"
#include "JetCore/JetCollection.hh"

#include "fastjet/PseudoJet.hh"
using namespace fastjet;

#include <iostream>
using namespace std;

// this is to avoid a gcc 3.2.3 problem
char* operator+(streampos&, char*);

namespace SpartyJet { 

void HepMCInput::init() {
  if (file != NULL)
    delete file;
  file = new ifstream(m_filename.c_str());

  unitIsGeV(); // SpartyJet default

  m_currentEvnt = 0;
  invert = false;
  if (!file->is_open())
    m_log << ERROR << "HepMCInput file " << m_filename << " did not open correctly!" << endl;
}


void HepMCInput::init_collection(JetCollection& coll){
  coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
  coll.get_JetMomentMap()->schedule_event_moment<vector<PseudoJet> >("HardProcess");
}


bool HepMCInput::fillNextInput(JetCollection& inputList, int start_index) {
  char peek;
  double px,py,pz,E,theta,phi,mass;
  int barcode,status,pdgid,endVtxBarcode,flow;
  bool end = false;
  int num_inserted=0;

  JetMomentMap* map = inputList.get_JetMomentMap();
  vector<PseudoJet> hardPartons; // hard process partons to store as extra event information

  do {
    peek = file->peek();
    if (peek == 'E') {                                        // E - New Event
      file->ignore(1000,'\n'); 
      if(num_inserted > 0)
        end = true;
    } else if (peek == 'P') {                                 // Particle Found
      peek = file->get(); // pull the P off the stream
      px = py = pz = E = -1;
      *file >> barcode >> pdgid >> px >> py >> pz >> E >> mass      // grab the rest of the information
            >> status >> theta >> phi >> endVtxBarcode >> flow;
      file->ignore(1000,'\n');                               // ignore anything else


      // this is HepMC standard (does not depend on MC!)
      bool isStable = (status==1);

      // this is generator-specific and current works for Pythia8!
      // See pythia8xxx/htmldoc/ParticleProperties.html for status codes
      // 21: incoming parton
      // 22: intermediate particle in hard process
      // 23: outgoing parton
      bool isParton = (status==23); //(status==22 || status==23);

      // ignore electrons and muons; these aren't the hard partons we're interested in
      isParton &= (abs(pdgid) != 11) && (abs(pdgid) != 13);

      if ( ( (m_doParton && isParton) || (m_doStable && isStable) ) && px != -1 && py != -1 && pz != -1 && E != -1) 
      {
        if (isStable) {
          Jet* j = new Jet(px,py,pz,E, num_inserted+start_index);
          if (!m_reject_bad_input || check_4vector(j)) {
            inputList.push_back(j);
            num_inserted++;
            map->set_jet_moment("pdgId", j , pdgid); // add moment
          }
        } else {
          //m_log << ERROR << "Read in hard parton with id, E:" << pdgid << " " << E << endl;
          PseudoJet pj(px, py, pz, E);
          pj.set_user_index(pdgid);
          hardPartons.push_back(pj);
        }
      }
    } else 
     file->ignore(1000,'\n');                    // must be a comment or nothing
  } while(*file && !end);
  if (num_inserted > 0) {                        // event found with some jets
    m_currentEvnt++;
    map->set_event_moment<vector<PseudoJet> >("HardProcess", hardPartons);
   return true;
  }
  return false;                                  // no event found
}


void HepMCInput::moveToEventN(int n) {
  if (n == m_currentEvnt) return;    // already happen to be at that event
  init();                  // start from beginning of file
  if (m_currentEvnt == n) return;    // if n == 0, this is needed

  char peek;
  do {
    peek = file->peek();
    if (peek == 'E') { // Found beginning of new event 
      file->ignore(1000, '\n'); 
      m_currentEvnt++;
      if (m_currentEvnt == n) return;
    } else 
      file->ignore(1000, '\n');     // ignore anything else
  } while (*file);

  return;
}

}  // namespace SpartyJet
