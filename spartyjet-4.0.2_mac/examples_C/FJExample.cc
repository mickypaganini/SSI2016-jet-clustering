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

/*
 * This is an example C++ program to drive SpartyJet.  Can be used:
 *  $> ./FJExample.exe
 *
 * NB: Python scripts are now the preferred way to use SpartyJet!
 */

#include "SJconfig.h"

#include "JetCore/JetBuilder.hh"
#include "IO/StdTextInput.hh"
#include "IO/HepMCInput.hh"
#include "FastJetTools/FastJetFinder.hh"

#include "fastjet/JetDefinition.hh"
//#include "fastjet/SISConePlugin.hh"

using namespace fastjet;
using namespace SpartyJet;
using namespace SpartyJet::FastJet;

#include <string>
using namespace std;

int main() {

  // Create a builder object
  JetBuilder builder(DEBUG);
  //builder.silent_mode(); // turn off debugging

  // Create an input object and open the input file
  StdTextInput textinput(string(SPARTYJET_DIR)+"/data/J1_Clusters.dat");
  builder.configure_input(&textinput);

  // Add an algorithm (AntiKt)
  FastJetFinder *anti4 = new FastJetFinder("AntiKt4", antikt_algorithm, 0.4, false);
  builder.add_default_analysis(anti4);

  // Same algorithm, uses your own JetDefinition
  JetDefinition jet_def(antikt_algorithm, 0.4);
  FastJetFinder *anti4_2 = new FastJetFinder(&jet_def, "AntiKt4two", false);
  builder.add_default_analysis(anti4_2);

  // More interesting example: FastJet Plugin
  // Note that SISCone is included in FastJet, but is implemented as a plugin
  // To use your own plugin, you will need to link against the relevant library
  /*
  double coneRadius = 0.4;
  double overlapThreshold = 0.75;
  SISConePlugin plugin(coneRadius, overlapThreshold);
  JetDefinition plugin_jet_def(&plugin);
  FastJetFinder *siscone4 = new FastJetFinder(&plugin_jet_def, "SISCone4", false);
  builder.add_default_analysis(siscone4);
  */

  // Add a text output file to easily list all of the jets
  builder.add_text_output(string(SPARTYJET_DIR)+"/data/output/simple.dat");

  // Configure the output (name of tree, root file)
  builder.configure_output("SpartyJet_Tree",string(SPARTYJET_DIR)+"/data/output/simple.root");

  // Run the builder on the first 10 events
  builder.process_events();

  return 0;
}
