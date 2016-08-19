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

#ifndef JETUTIL_JETDISTANCES_H
#define JETUTIL_JETDISTANCES_H


#include "Jet.hh"

#include <cmath>
namespace SpartyJet { 

struct JetDistances {

  inline static double sq(double x) {return x*x;}

  // distance in eta
  inline static double deltaEta(const Jet& jet1, const Jet& jet2)
    {return jet1.eta() - jet2.eta();}
  inline static double deltaEta(const Jet* jet1, const Jet* jet2)
    {return jet1->eta() - jet2->eta();}
  inline static double deltaEta(const double eta1, const double eta2)
    {return (eta1 - eta2);}

  inline static double deltaPhi(const Jet& jet1, const Jet& jet2)
    {return fixedPhi(jet1.phi() - jet2.phi());}
  inline static double deltaPhi(const Jet* jet1, const Jet* jet2)
    {return fixedPhi(jet1->phi()-jet2->phi());}
  inline static double deltaPhi(const double phi1, const double phi2)
    {return fixedPhi(phi1 - phi2);}

  // distance in (eta,phi)
  inline static double deltaR(const Jet& jet1, const Jet& jet2)
    {return sqrt(sq(deltaEta(jet1, jet2)) + sq(deltaPhi(jet1, jet2)));}
  inline static double deltaR(const Jet* jet1, const Jet* jet2)
    {return sqrt(sq(deltaEta(jet1, jet2)) + sq(deltaPhi(jet1, jet2)));}
  
  inline static double deltaR(const double eta1, const double phi1,
                              const double eta2, const double phi2)
    {return sqrt(sq(deltaEta(eta1, eta2)) + sq(deltaPhi(phi1, phi2)));}


  // phi convention enforcement
  inline static double fixedPhi(double aPhi) {
    while (aPhi < -M_PI) aPhi += 2.*M_PI;
    while (aPhi > M_PI) aPhi -= 2.*M_PI;
    return aPhi;
  }

};

}  // namespace SpartyJet
#endif
