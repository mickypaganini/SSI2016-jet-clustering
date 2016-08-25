#ifndef _CENTROID_HH_
#define _CENTROID_HH_

#include <cmath>

#ifndef M_PI
#define M_PI  3.141592653589793238462643383279502884197 
#endif

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cdf{

class Centroid
{
 public:

  double Et,eta,phi;

  Centroid(): Et(0), eta(0), phi(0) {}
  Centroid(double centroidEt, double centroidEta, double centroidPhi): Et(centroidEt), eta(centroidEta), phi(centroidPhi) {}
  Centroid(const Centroid& c): Et(c.Et), eta(c.eta), phi(c.phi) {}
  void add(Centroid c)
  {
    double newEt = Et + c.Et;
    eta = (Et*eta + c.Et*c.eta)/newEt;
    double dPhi = c.phi - phi;
    if(dPhi > M_PI)
      dPhi -= 2*M_PI;
    else if(dPhi < -M_PI)
      dPhi += 2*M_PI;
    phi += dPhi*c.Et/newEt;
    while(phi < 0)
      phi += 2*M_PI;
    while(phi >= 2*M_PI)
      phi -= 2*M_PI;
    Et = newEt;
  }
  void subtract(Centroid c)
  {
    double newEt = Et - c.Et;
    eta = (Et*eta - c.Et*c.eta)/newEt;
    double dPhi = c.phi - phi;
    if(dPhi > M_PI)
      dPhi -= 2*M_PI;
    else if(dPhi < -M_PI)
      dPhi += 2*M_PI;
    phi -= dPhi*c.Et/newEt;
    while(phi < 0)
      phi += 2*M_PI;
    while(phi >= 2*M_PI)
      phi -= 2*M_PI;
    Et = newEt;
  }
  bool isEqual(Centroid c)
  {
    return Et == c.Et && eta == c.eta && phi == c.phi;
  }
};

}  // namespace cdf

FASTJET_END_NAMESPACE

#endif
