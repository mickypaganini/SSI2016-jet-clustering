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

#ifdef __CINT__

#pragma link off all global;
#pragma link off all classes;
#pragma link off all function;

#pragma link C++ class SpartyJet::NtupleInputBase;
#pragma link C++ class SpartyJet::NtupleInputMaker; 
#pragma link C++ class SpartyJet::DelphesInputMaker; 
#pragma link C++ class SpartyJet::TextInputMaker;
#pragma link C++ class SpartyJet::StdTextInput;
#pragma link C++ class SpartyJet::HepMCInput;
#pragma link C++ class SpartyJet::LheInput;
#pragma link C++ class SpartyJet::CalchepPartonTextInput;
#pragma link C++ class SpartyJet::HuskyInput;
#pragma link C++ class SpartyJet::MultiInput;

// define or not stdhep. This will be handle automatically at compilation
#ifdef DO_STDHEP
#pragma link C++ class SpartyJet::StdHepInput;
#endif

#ifdef DO_PYTHIA
#pragma link C++ class SpartyJet::PythiaInput;
#endif

#endif
