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

#pragma link C++ nestedtypedef;
#pragma link C++ nestedclass;

#pragma link C++ class std::vector<int>; // this one is known by default in ROOT 5.20
#pragma link C++ class std::vector<double>;
#pragma link C++ class std::vector<float>;
#pragma link C++ class std::vector<std::string>;
#pragma link C++ class std::vector< std::vector<float> >;
#pragma link C++ class std::vector< std::vector<double> >;

#pragma link C++ class SpartyJet::Jet;
//#pragma link C++ class std::vector<SpartyJet::Jet*>;
#pragma link C++ class SpartyJet::JetCollection;
#pragma link C++ class SpartyJet::JetAnalysis;
#pragma link C++ class SpartyJet::JetTool;
#pragma link C++ class SpartyJet::JetNegEnergyTool;
#pragma link C++ class SpartyJet::JetBuilder;

#pragma link C++ class SpartyJet::InputMaker;

#pragma link C++ namespace SpartyJet;
#pragma link C++ enum SpartyJet::MessageLevel;

#pragma link C++ enum SpartyJet::ArrayType;
#pragma link C++ enum SpartyJet::BaseType;


#endif
