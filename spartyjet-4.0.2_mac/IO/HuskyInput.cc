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

#include "HuskyInput.hh"
#include "JetCore/JetCollection.hh"

#include <iostream>
#include <typeinfo>
using namespace std;

// this is to avoid a gcc 3.2.3 problem
//char* operator+( std::streampos&, char* );
namespace SpartyJet { 

void HuskyInput::init() {
  if (file != NULL)
    delete file;
  file = new ifstream(m_filename.c_str());

  setGeVUnits(1);

  m_currentEvnt = 0;
  if(!file->is_open())
    std::cout << "HuskyInput :  file " << m_filename << " did not open correctly!\n";
}
  
void HuskyInput::init_collection(JetCollection &coll){
  coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
}

bool HuskyInput::fillNextInput(JetCollection &inputList, int start_index) {
  double px,py,pz,E;
  int barcode,pdgid;
  bool end = false;

  inputList.clear();

  int num_inserted=start_index;
    
  JetMomentMap *map = inputList.get_JetMomentMap();
  //-------------
  int nLines = 0;
  do 
  {
	  px = py = pz = E = -1;
	  *file >> barcode >> px >> py >> pz >> E >> pdgid;
	  if(barcode > 0 && px != -1 && py != -1 && pz != -1 && E != -1) 
	  {
		  Jet* j = new Jet(px,py,pz,E, num_inserted);
		  if(!m_reject_bad_input || check_4vector(j) ) inputList.push_back(j);
		  num_inserted++;
		  if(map) map->set_jet_moment("pdgId", j , pdgid); // add moment
	  }
	 end = (barcode==0 && nLines !=0); // barcode is zero for first line of an event
	  nLines++;
  } while(*file && !end);
  if(inputList.size() > 0) {
	  m_currentEvnt++;
	  return true;
  }
  else return false;                                         // no event found
  }

// does not work yet!
void HuskyInput::moveToEventN(int n) {
  if(n == m_currentEvnt) return;        // already happen to be at that event
  
  init();                  // start from beginning of file
  if(m_currentEvnt == n) return;     // if n == 0, this is needed


  double px,py,pz,E;
  int barcode,pdgid;
  bool end = false;


  //-------------
  do {
    int nLines = 0;
    do 
    {
      px = py = pz = E = -1;
      *file >> barcode >> px >> py >> pz >> E >> pdgid;

      end = (barcode==0 && nLines !=0); // barcode is zero for first line of an event
      nLines++;
  } while (*file && !end);

    m_currentEvnt++;
    if (m_currentEvnt == n) return;
  } while (*file);
  
  return;
}

}  // namespace SpartyJet
