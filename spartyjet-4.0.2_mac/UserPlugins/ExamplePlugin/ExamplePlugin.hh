#ifndef __PLUGINEXAMPLE_HH__
#define __PLUGINEXAMPLE_HH__

#include "fastjet/JetDefinition.hh"
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

FASTJET_BEGIN_NAMESPACE      // defined in fastjet/internal/base.hh

class ExamplePlugin : public JetDefinition::Plugin {
public:
  ExamplePlugin(JetDefinition * jet_def);
  
	virtual std::string description () const;
  void run_clustering(ClusterSequence &) const;                      
  virtual double R() const {return 1.0;}

private:
  // User supplied jet definition
  JetDefinition *m_jet_def; 
};

FASTJET_END_NAMESPACE      // defined in fastjet/internal/base.hh

#endif 

