#ifndef JETREC_JETCONEFINDERTOOL_H
#define JETREC_JETCONEFINDERTOOL_H
//******************************************************************************
// Filename :  JetConeFinderTool
// Author   :  Ambreesh Gupta
// Created  :  September, 2002
//
// DESCRIPTION:
//  TESTING cone algorithm created from JetSeedLessCone algorithm. The algorithm
//  only lookps over seed of certain Pt that is configurable trought the 
//  jobOption file.
//
// PROPERTIES (JobOption Parameters):
//
//  declareProperty("ConeParam",m_coneR);
//    ProtoJetContainerLoc  string "Default"   Key for ProtoJet input.
//    JetContainerLoc       string "Default"   Key for Jet list to output.
//    ConeR                 double 0.5         Cone radius
//    PtCut                 double 0.0         Pt Cut applied on ProtoJet.
//    Epsilon               double 0.05        
//    SeedPt                double 2.0         Pt Cut for ProtoJet to be a seed.
//
// HISTORY
//
// BUGS
//
// NOTES
//   file taken from SpartyJet v.2.20.0
//   removed the Message logs
//   replaced StatusCode by int
//*****************************************************************************

//Library Includes
#include <string>
#include <vector>
#include <list>

//#include "JetCore/CustomMessage.hh"
//typedef int StatusCode;

// class JetCollection;
#include "Jet.hh"

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace atlas{

class JetConeFinderTool 
{
public:
  typedef Jet::jet_list_t jetcollection_t;
  

  JetConeFinderTool();

  virtual ~JetConeFinderTool();

  virtual int execute(jetcollection_t &theJets);


  //private:
    void  reconstruct();   
    Jet*  calc_cone(double, double); 

    // Configured through jobOption
    std::string m_protoJetContainerLoc;
    std::string m_jetContainerLoc;

    double      m_coneR; // Cone Radius
    double      m_ptcut; // Pt Cut
    double      m_eps;   // Arbitrary parameter
    double      m_seedPt;
    double      m_etaMax;

    // Internals 
    //std::list<Jet*>*       m_pjetV;
    jetcollection_t*       m_pjetV;
    jetcollection_t*       m_jetOV;

    int             m_cone_in_tower;

    std::vector<double>*     m_veta;
    std::vector<double>*     m_vphi;

    int m_ctr;
    int m_dctr;

  //Message m_log;
};

}  // namespace atlas

FASTJET_END_NAMESPACE 
#endif // JETREC_JETCONEFINDERTOOL_H
