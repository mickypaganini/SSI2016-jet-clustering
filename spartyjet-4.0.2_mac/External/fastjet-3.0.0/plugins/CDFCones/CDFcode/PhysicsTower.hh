#ifndef _PHYSICS_TOWER_HH_
#define _PHYSICS_TOWER_HH_

#include "LorentzVector.hh"
#include "CalTower.hh"

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cdf{

class PhysicsTower
{
 public:

  LorentzVector fourVector;
  CalTower calTower;

  PhysicsTower(): fourVector(LorentzVector()), calTower(CalTower()), fjindex(-1) {}
  PhysicsTower(LorentzVector v, CalTower c): fourVector(v), calTower(c), fjindex(-1) {}
  PhysicsTower(const PhysicsTower& p): fourVector(p.fourVector), calTower(p.calTower), fjindex(p.fjindex) {}
  PhysicsTower(CalTower c):
    fourVector(LorentzVector(c.Et*cos(c.phi),c.Et*sin(c.phi),c.Et*sinh(c.eta),c.Et*cosh(c.eta))), calTower(c), fjindex(-1) {}
  PhysicsTower(LorentzVector v): fourVector(v), calTower(CalTower(v.Et(),v.eta(),v.phi())), fjindex(-1) {}
  double Et()   const {return calTower.Et;}
  double eta()  const {return calTower.eta;}
  double phi()  const {return calTower.phi;}
  int    iEta() const {return calTower.iEta;}
  int    iPhi() const {return calTower.iPhi;}
  bool isEqual(PhysicsTower p)
  {
    return fourVector.isEqual(p.fourVector) && calTower.isEqual(p.calTower);
  }
  /// addition by GPS (2008-08-15) for tracking within fastjet
  int fjindex;
};

} // namespace cdf

FASTJET_END_NAMESPACE

#endif
