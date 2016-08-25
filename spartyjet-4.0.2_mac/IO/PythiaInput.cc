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

#include "PythiaInput.hh"
#include "JetCore/JetCollection.hh"

#include "TParticle.h"
#include "TDatabasePDG.h"
#include "TClonesArray.h"
#include "TPythia8.h"

#include <cmath>
using namespace std;

namespace SpartyJet { 

void PythiaInput::init(string filename)
{
  unitIsGeV(); // SpartyJet default
  m_currentEvnt = 0;
  // Array of particles
  m_particles = new TClonesArray("TParticle", 10000);
}

void PythiaInput::init_collection(JetCollection& coll)
{
    coll.get_JetMomentMap()->schedule_jet_moment<int>("pdgId");
}

void PythiaInput::fillInput(int eventn, JetCollection& inputList, int start_index)
{
    moveToEventN(eventn);
    fillNextInput(inputList, start_index);
}

bool PythiaInput::fillNextInput(JetCollection& inputList, int start_index)
{
  double px, py, pz, E, mass;
  int status, pdgid, barcode=0;
  int num_inserted=0;

  JetMomentMap* map = inputList.get_JetMomentMap();

    m_pythia->GenerateEvent();
		if (m_printEvent)
      ((TPythia8*)m_pythia)->EventListing();
    m_pythia->ImportParticles(m_particles, "All");
    Int_t np = m_particles->GetEntriesFast();
    m_log << DEBUG << "Retieved: " << np << " particles from pythia." << endl;
    // Particle loop
    for (Int_t ip = 0; ip < np; ip++) {
      TParticle* part = (TParticle*) m_particles->At(ip);
      status = part->GetStatusCode();
      pdgid = part->GetPdgCode();
      //Float_t charge = TDatabasePDG::Instance()->GetParticle(pdg)->Charge();
      px  = part->Px();
      py  = part->Py();
      pz  = part->Pz();
      E   = part->Energy();
      if (!(TDatabasePDG::Instance()->GetParticle(pdgid)))
          mass = 0.134*m_GeV;
      else
          mass = part->GetMass();

      bool isStable = (status > 0);
      bool isParton = (barcode > m_minBarcode) && (barcode < m_maxBarcode);

      m_log << DEBUG << " Particle " << ip << ", E = " << E << ", isStable? " << isStable << ", status = " << status << ", isPrimary? " << part->IsPrimary() << endl;
      if (((m_doStable && isStable) || (m_doParton && isParton))  && px != -1 && py != -1 && pz != -1 && E != -1) {
        Jet* j = new Jet(px,py,pz,E, num_inserted+start_index);
        if(!m_reject_bad_input || check_4vector(j) ) 
        {
             inputList.push_back(j);
             num_inserted++;
             map->set_jet_moment("pdgId", j, pdgid); // add moment
        }
      }
      barcode++;
    }
    m_currentEvnt++;
    return true;
}

void PythiaInput::moveToEventN(int n)
{
  if (n == m_currentEvnt) return; // already happen to be at that event
  init("");                       // start from beginning of file
  if (m_currentEvnt == n) return; // if n == 0, this is needed

  while (m_currentEvnt != n) {
    m_pythia->GenerateEvent();
    m_currentEvnt++;
  } 

  return;
}

}  // namespace SpartyJet
