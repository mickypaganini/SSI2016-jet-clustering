#ifndef _CAL_TOWER_HH_
#define _CAL_TOWER_HH_

#include <cmath>

#ifndef M_PI
#define M_PI  3.141592653589793238462643383279502884197 
#endif

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cdf{

const double TOWER_THETA[23] = {  3.000,  5.700,  8.400, 11.100, 13.800, 16.500, 19.200, 21.900, 24.600, 27.300, 30.000, 33.524,
				  36.822, 40.261, 43.614, 47.436, 51.790, 56.735, 62.310, 68.516, 75.297, 82.526, 90.000 };

class CalTower
{
 public:

  double Et,eta,phi;
  int iEta,iPhi;

  CalTower(): Et(0), eta(0), phi(0), iEta(-1), iPhi(-1) {}
  CalTower(double Et0, double eta0, double phi0): Et(Et0), eta(eta0), phi(phi0)
  {
    if(fabs(eta) < -log(tan(TOWER_THETA[0]*M_PI/180/2))){
      if(eta <= 0){
	for(int i = 0; i < 22; i++)
	  if(eta < -log(tan((180 - TOWER_THETA[i + 1])*M_PI/180/2))){
	    iEta = 4 + i;
	    break;
	  }
      }
      else{
	for(int i = 0; i < 22; i++)
	  if(-eta < -log(tan((180 - TOWER_THETA[i + 1])*M_PI/180/2))){
	    iEta = 47 - i;
	    break;
	  }
      }
      if(iEta >= 8 && iEta < 14 || iEta >= 38 && iEta < 44)
	iPhi = int(phi/2/M_PI*48)%48;
      else
	iPhi = int(phi/2/M_PI*24)%24;
    }
    else{
      iEta = -1;
      iPhi = -1;
    }
  }
  CalTower(double Et0, double eta0, double phi0, int iEta0, int iPhi0): Et(Et0), eta(eta0), phi(phi0), iEta(iEta0), iPhi(iPhi0) {}
  CalTower(const CalTower& c): Et(c.Et), eta(c.eta), phi(c.phi), iEta(c.iEta), iPhi(c.iPhi) {}
  bool isEqual(CalTower c)
  {
    return Et == c.Et && eta == c.eta && phi == c.phi && iEta == c.iEta && iPhi == c.iPhi;
  }
};

}  // namespace cdf

FASTJET_END_NAMESPACE

#endif
