#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_

#include "PhysicsTower.hh"
#include "LorentzVector.hh"
#include "Centroid.hh"
#include <vector>

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cdf{

class Cluster
{
 public:
  std::vector<PhysicsTower> towerList;
  LorentzVector fourVector;
  Centroid centroid;
  // addition by G.P.Salam; pt_tilde = sum |p_{ti}|. Maintaining this
  // seems to add about 1% (3%) to overall timings for midpoint
  // (jetclu) but it is useful because it makes it easy to look at
  // other scales in the split-merge procedure
  double pt_tilde; 

  Cluster()
  {
    clear();
  }
  void clear()
  {
    towerList.clear();
    fourVector = LorentzVector();
    centroid = Centroid();
    pt_tilde = 0.0;
  }
  void addTower(PhysicsTower p)
  {
    towerList.push_back(p);
    fourVector.add(p.fourVector);
    centroid.add(Centroid(p.Et(),p.eta(),p.phi()));
    pt_tilde += p.fourVector.pt();
  }
  void removeTower(PhysicsTower p)
  {
    for(std::vector<PhysicsTower>::iterator towerIter = towerList.begin(); towerIter != towerList.end(); towerIter++)
      if(towerIter->isEqual(p)){
	fourVector.subtract(towerIter->fourVector);
	centroid.subtract(Centroid(towerIter->Et(),towerIter->eta(),towerIter->phi()));
        pt_tilde -= towerIter->fourVector.pt();
	towerList.erase(towerIter);
	break;
      }
  }
  int size(){return towerList.size();}
};

}  // namespace cdf

FASTJET_END_NAMESPACE

#endif
