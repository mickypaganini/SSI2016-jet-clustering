#ifndef JETREC_JETSPLITMERGETOOL_H
#define JETREC_JETSPLITMERGETOOL_H
//******************************************************************************
// Filename :  JetSplitMergeTool   
// Author   :  Ambreesh Gupta
// Created  :  November, 2001
//
// DESCRIPTION:
//
// Cone algorithms generally produce overlapping jets. These jets are then
// passed through a Split Merge algorithm to create seperated jets. This
// is an implementation of one such algorithm.
// 
// The steps of the algorithm are:
//          - <to be written>
//
// PROPERTIES (JobOption Parameters):
//
//    ProtoJetContainerLoc  string "Default"   Key for ProtoJet input.
//    JetContainerLoc       string "Default"   Key for Jet list to output.
//    OverlapFraction       double 0.5
//
// HISTORY
//   05Nov01 agupta.  First version
//   15Aug02 agupta.  Fix phi-wrapping. 
//   
// NOTES
//   taken from SpartyJet v2.20.0
//   removed the Message logs
//   replaced StatusCode by int
//*****************************************************************************


//class StoreGateSvc;

//Includes
#include "Jet.hh"

#include <vector>
#include <list>

//#include "JetCore/CustomMessage.hh"

#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

namespace atlas { 

//typedef int StatusCode ;

class JetSplitMergeTool 
{
public:
  typedef Jet::jet_list_t jetcollection_t;
    //Constructors
    JetSplitMergeTool();

    //Destructor
    virtual ~JetSplitMergeTool();

    virtual int execute( jetcollection_t* theJets );

    //Handle negative energy ProtoJets:
    double etaTrue(Jet::constit_vect_t::iterator pj);
    double phiTrue(Jet::constit_vect_t::iterator pj);

    //private:
    void                                     split_merge();   
    double                                             m_f;
    jetcollection_t                               m_preJet;
    jetcollection_t                                  m_jet;
    jetcollection_t*                              m_jetVec;

    int m_ctr;
    int m_dctr;

  //    Message m_log;
};

}  // namespace atlas

FASTJET_END_NAMESPACE

#endif // JETREC_JETSPLITMERGETOOL_H











