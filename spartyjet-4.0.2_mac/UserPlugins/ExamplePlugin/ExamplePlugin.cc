#include "ExamplePlugin.hh"

#include <string>
#include <sstream>


FASTJET_BEGIN_NAMESPACE      // defined in fastjet/internal/base.hh


ExamplePlugin::ExamplePlugin(JetDefinition * seed_jet_def)
  : m_jet_def(seed_jet_def)
{
}

std::string ExamplePlugin::description () const {
  std::ostringstream desc;
  desc << "ExamplePlugin: I do nothing";
  return desc.str();
}	


void ExamplePlugin::run_clustering(ClusterSequence & clust_seq) const {
	// Make some jets
}
FASTJET_END_NAMESPACE      // defined in fastjet/internal/base.hh
