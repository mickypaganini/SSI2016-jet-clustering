#ifndef _MIDPOINT_ALGORITHM_HH_
#define _MIDPOINT_ALGORITHM_HH_

#include "PhysicsTower.hh"
#include "Cluster.hh"
#include <vector>

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace cdf{

class MidPointAlgorithm
{
 public:
  enum SplitMergeScale {SM_pt, SM_Et, SM_mt, SM_pttilde};

 private:
  double _seedThreshold;
  double _coneRadius;
  double _coneAreaFraction;
  int    _maxPairSize;
  int    _maxIterations;
  double _overlapThreshold;
  SplitMergeScale _smScale;

 public:
  MidPointAlgorithm():
    _seedThreshold(1),
    _coneRadius(0.7),
    _coneAreaFraction(0.25),
    _maxPairSize(2),
    _maxIterations(100),
    _overlapThreshold(0.75),
    _smScale(SM_pt)
  {}
  MidPointAlgorithm(double st, double cr, double caf, int mps, int mi, double ot, SplitMergeScale sm = SM_pt):
    _seedThreshold(st),
    _coneRadius(cr),
    _coneAreaFraction(caf),
    _maxPairSize(mps),
    _maxIterations(mi),
    _overlapThreshold(ot),
    _smScale(sm)
  {}
  void findStableConesFromSeeds(std::vector<PhysicsTower>& particles, std::vector<Cluster>& stableCones);
  void findStableConesFromMidPoints(std::vector<PhysicsTower>& particles, std::vector<Cluster>& stableCones);
  void iterateCone(volatile double startRapidity, volatile double startPhi, volatile double startPt, std::vector<PhysicsTower>& particles,
		   std::vector<Cluster>& stableCones, bool reduceConeSize);
  void addClustersToPairs(std::vector<int>& testPair, std::vector< std::vector<int> >& pairs,
			  std::vector< std::vector<bool> >& distanceOK, int maxClustersInPair);
  void splitAndMerge(std::vector<Cluster>& stableCones, std::vector<Cluster>& jets);
  void run(std::vector<PhysicsTower>& particles, std::vector<Cluster>& jets);

  /// sort the clusters into whatever order is 
  void local_sort(std::vector<Cluster>&);

};

}  // namespace cdf

FASTJET_END_NAMESPACE

#endif
