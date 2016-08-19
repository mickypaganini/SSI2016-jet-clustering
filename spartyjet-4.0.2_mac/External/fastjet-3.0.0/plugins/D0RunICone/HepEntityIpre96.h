#ifndef  D0RunIconeJets_HepEntityPre96_class
#define  D0RunIconeJets_HepEntityPre96_class

#include "inline_maths.h"
#include "HepEntityI.h"
#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace d0runi{

//Author: Lars Sonnenschein 25/Feb/2010
//This is an example class fulfilling the minimal requirements needed by the
//D0 RunI cone jet algorithm implementation prior to 1996, which is an inlined template class
//See FERMILAB-Pub-97-242-E for details
class HepEntityIpre96 : public HepEntityI {

 public:

  HepEntityIpre96() {
    Et=0.;
    eta=0.;
    phi=0.;
    Ex=0.;
    Ey=0.;
    Ez=0.;
    index = -1;
    phi_pre96=0.;
    eta_pre96=0.;

    return;
  }


 HepEntityIpre96(double E, double px, double py, double pz,
		 int index_in = -1) : index(index_in) {
   //Snowmass Et scheme    
    double pt = sqrt(px*px+py*py);
    double p = sqrt(pt*pt+pz*pz);
    phi = inline_maths::phi(px,py);
    double theta = asin(pt/p);
    eta = inline_maths::eta(theta);

    Et = E*sin(theta);

    phi_pre96 = phi;
    eta_pre96 = eta;

    Ex = Et*cos(phi_pre96);
    Ey = Et*sin(phi_pre96);
    Ez = Et*sinh(eta_pre96);
  
    return;
  }


  inline double px() const {
    return Et*cos(phi_pre96);
  }

  inline double py() const {
    return Et*sin(phi_pre96);
  }

  inline double pz() const {
    return Et*sinh(eta_pre96);
  }
  
  inline double E() const {
    return Et*cosh(eta_pre96);
  }
  
 
  inline void Add(const HepEntityIpre96 el) {
    //assumes Et, eta and phi stored accurately
    double w2 = el.Et;
    Et += el.Et;
    w2 /= Et;
    
    eta += w2*(el.eta - eta);
    phi += w2*inline_maths::delta_phi(el.phi, phi); 


    Ex += el.Ex;
    Ey += el.Ey;
    Ez += el.Ez;
    phi_pre96 = atan2(Ey, Ex);
    double theta_pre96 = atan2(sqrt(Ex*Ex+Ey*Ey),Ez);
    eta_pre96 = -log(tan(theta_pre96/2.));

    return; 
  }


  inline void Fill(double E, double px, double py, double pz, int index_in) {
    double pt = sqrt(px*px+py*py);
    double p = sqrt(pt*pt+pz*pz);
    phi = inline_maths::phi(px,py);
    double theta = asin(pt/p);
    eta = inline_maths::eta(theta);

    Et = E*sin(theta);

    
    phi_pre96 = phi;
    eta_pre96 = eta;

    Ex = Et*cos(phi_pre96);
    Ey = Et*sin(phi_pre96);
    Ez = Et*sinh(eta_pre96);

    index = index_in;

    return;
  }


  double Ex;
  double Ey;
  double Ez;
  int index;
  double phi_pre96;
  double eta_pre96;

 private:



};
//end of class HepEntityIpre96;

} // end of namespace d0runi

FASTJET_END_NAMESPACE

#endif
