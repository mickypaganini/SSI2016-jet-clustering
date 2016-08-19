#ifndef  D0RunIconeJets_HepEntity_class
#define  D0RunIconeJets_HepEntity_class

#include "inline_maths.h"
#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace d0runi{

//Author: Lars Sonnenschein 15/Sep/2009
//This is an example class fulfilling the minimal requirements needed by the
//D0 RunI cone jet algorithm implementation, which is an inlined template class

class HepEntityI {

 public:

  HepEntityI() {
    Et=0.;
    eta=0.;
    phi=0.;
    index = -1;
    return;
  }


  HepEntityI(double E, double px, double py, double pz,
	     int index_in = -1) : index(index_in) {
    //Snowmass Et scheme    
    double pt = sqrt(px*px+py*py);
    double p = sqrt(pt*pt+pz*pz);
    phi = inline_maths::phi(px,py);
    double theta = asin(pt/p);
    eta = inline_maths::eta(theta);

    Et = E*sin(theta);
    
    return;
  }



   HepEntityI(const HepEntityI& in) : Et(in.Et), eta(in.eta), phi(in.phi), index(in.index) {
    return;
  }



  
  inline double pT() const {
    return Et;
  }

  inline double px() const {
    return Et*cos(phi);
  }

  inline double py() const {
    return Et*sin(phi);
  }

  inline double pz() const {
    return Et*sinh(eta);
  }
  
  inline double E() const {
    return Et*cosh(eta);
  }

  
  inline void p4vec(float* p) const {
    p[0] = Et*cos(phi);
    p[1] = Et*sin(phi);
    p[2] = Et*sinh(eta);
    p[3] = Et*cosh(eta); //E
    return;
  }
  

  inline void Add(const HepEntityI el) {
    //assumes Et, eta and phi stored accurately
    double w2 = el.Et;
    Et += el.Et;
    w2 /= Et;
    
    eta += w2*(el.eta - eta);
    phi += w2*inline_maths::delta_phi(el.phi, phi); 

    return; 
  }


  inline void Fill(double E, double px, double py, double pz, int index_in) {
    double pt = sqrt(px*px+py*py);
    double p = sqrt(pt*pt+pz*pz);
    phi = inline_maths::phi(px,py);
    double theta = asin(pt/p);
    eta = inline_maths::eta(theta);
    
    Et = E*sin(theta);

    index = index_in;
    
    return;
  }


  double Et;
  double eta;
  double phi;
  int index;

 private:



};
//end of class HepEntityI;

} // end of namespace d0runi

FASTJET_END_NAMESPACE

#endif
