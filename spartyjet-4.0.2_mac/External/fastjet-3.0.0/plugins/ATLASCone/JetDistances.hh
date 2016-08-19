// file taken from SpartyJet v2.20.0

#ifndef JETUTIL_JETDISTANCES_H
#define JETUTIL_JETDISTANCES_H


#include "Jet.hh"

#include <cmath>

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace atlas { 

struct JetDistances {


  // distance in eta
  inline static double deltaEta(const Jet& jet1, const Jet& jet2)
  { return jet1.eta() - jet2.eta(); }
  inline static double deltaEta(const Jet* jet1,
				const Jet* jet2)
  { return jet1->eta() - jet2->eta(); }
  inline static double deltaEta(const double eta1,
				const double eta2)
  { return (eta1 - eta2); }



  inline static double deltaPhi(const Jet& jet1, 
				const Jet& jet2)
  { 
    return fixedPhi(jet1.phi() - jet2.phi());
  }
  inline static double deltaPhi(const Jet* jet1,
				const Jet* jet2)
  { 
    return fixedPhi(jet1->phi()-jet2->phi());
  }
  inline static double deltaPhi(const double phi1,
				const double phi2)
  { 
    return fixedPhi( phi1 - phi2 );
  }


  // distance in (eta,phi)
  inline static double deltaR(const Jet& jet1, 
			      const Jet& jet2)
  { return sqrt( deltaEta(jet1,jet2) * deltaEta(jet1,jet2) + 
		 deltaPhi(jet1,jet2) * deltaPhi(jet1,jet2) ); }
  inline static double deltaR(const Jet* jet1,
			      const Jet* jet2)
  { return sqrt( deltaEta(jet1,jet2) * deltaEta(jet1,jet2) +
		 deltaPhi(jet1,jet2) * deltaPhi(jet1,jet2) ); }
  
  inline static double deltaR(const double eta1, const double phi1,
			      const double eta2, const double phi2 )
  { return sqrt( deltaEta(eta1,eta2) * deltaEta(eta1,eta2) +
		 deltaPhi(phi1,phi2) * deltaPhi(phi1,phi2) ); }
  

  
  // phi convention enforcement
  inline static double fixedPhi(double aPhi)
  {
    while ( aPhi < -M_PI )
      {
	aPhi += 2.*M_PI;
      }
    while ( aPhi > M_PI )
      {
	aPhi -= 2.*M_PI;
      }
    return aPhi;
  }

};

}  // namespace atlas

FASTJET_END_NAMESPACE
#endif
