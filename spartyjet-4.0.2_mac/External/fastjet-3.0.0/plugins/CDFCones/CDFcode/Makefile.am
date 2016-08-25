noinst_LTLIBRARIES = libCDFcode.la

libCDFcode_la_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir) -I$(srcdir)/../../../include
libCDFcode_la_SOURCES = LorentzVector.cc  CalTower.cc Centroid.cc\
  Cluster.cc ClusterComparisons.cc PhysicsTower.cc\
  JetCluAlgorithm.cc MidPointAlgorithm.cc

EXTRA_DIST = CalTower.hh Centroid.hh ClusterComparisons.hh\
  Cluster.hh JetCluAlgorithm.hh LorentzVector.hh MidPointAlgorithm.hh\
  PhysicsTower.hh makefile.static
