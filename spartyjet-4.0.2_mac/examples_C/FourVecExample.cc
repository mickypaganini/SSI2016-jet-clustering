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
 *  $> ./FourVecExample.exe
 *
 * This example demonstrates using input directly from memory, i.e., the output
 * of other code as opposed to a file.
 */

#include "SJconfig.h"

#include "JetCore/JetBuilder.hh"
#include "IO/FourVecInput.hh"
#include "FastJetTools/FastJetFinder.hh"

#include "fastjet/JetDefinition.hh"

using namespace fastjet;
using namespace SpartyJet;
using namespace SpartyJet::FastJet;

#include <string>
#include <cmath>
using namespace std;

/// A really simple four-vector class.  You can use anything that provides this interface
/// E.g., fastjet::PseudoJet, TLorentzVector, CLHEP vector, etc.
struct StupidFourVector {
  double x,y,z,t;
  // all you need is this operator:  (no error checking in this dummy implementation)
  double operator[](int i) const
    {switch(i) {case 0: return x; case 1: return y; case 2: return z; case 3: default: return t;}}
};

/// A skeleton class that provides the four-vector input -- presumably wraps
/// some other code.  Functions defined below.
class Reader {
public:
  Reader() : event(0), n_particles(0) {}
  
  // These three functions must be implemented in your Reader class!  next() can return any four-vector class.
  bool empty() const;
  const StupidFourVector& next(); // can also return by value, but this is cheaper
  //StupidFourVector next();
  bool event_done() const;

private:
  int event;
  int n_particles;
  StupidFourVector v;
};



int main() {

  // Create a builder object
  JetBuilder builder(DEBUG);
  //builder.silent_mode(); // turn off debugging

  // Create an input object and open the input file
  Reader reader;
  FourVecInput<Reader> input(reader);
  builder.configure_input(&input);

  // Add an algorithm (AntiKt)
  FastJetFinder *anti4 = new FastJetFinder("AntiKt4", antikt_algorithm, 0.4, false);
  builder.add_default_analysis(anti4);

  // Add a text output file to easily list all of the jets
  builder.add_text_output(string(SPARTYJET_DIR)+"/data/output/fourvec.dat");

  // Configure the output (name of tree, root file)
  builder.configure_output("SpartyJet_Tree",string(SPARTYJET_DIR)+"/data/output/fourvec.root");

  // Run the builder on the events
  builder.process_events();

  return 0;
}

bool Reader::empty() const {return (event >= 10);}
bool Reader::event_done() const {return (n_particles >= 20);}

/// generate some pseudo-data (obviously not at all random)
/// events are produced in identical pairs, just as a check
const StupidFourVector& Reader::next() {
  if (event_done()) n_particles = 0;

  n_particles++;  
  double n = n_particles * (event / 2);
  v.x = 10.0 + n;
  v.y = 5.0 + n;
  v.z = 20.0 * (10.0 - n);
  v.t = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

  if (event_done()) event++;
  return v;
}


