#include "Pythia.h"

#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/FastPrunePlugin.hh"

#define ETALOW -5
#define ETAHIGH 5.
#define ETABINS 100
#define PHIBINS 63 
//#define PI 3.1415926536
#include "wtag.h"

using namespace Pythia8;
using namespace fastjet;

void copy_momentum(Particle &par, double p[])
{
   p[0] = par.e();
   p[1] = par.px();
   p[2] = par.py();
   p[3] = par.pz();

}

int poisson(double nAvg, Rndm& rndm) {

  // Set maximum to avoid overflow.
  const int NMAX = 100;

  // Random number.
  double rPoisson = rndm.flat() * exp(nAvg);

  // Initialize.
  double rSum  = 0.;
  double rTerm = 1.;
  
  // Add to sum and check whether done.
  for (int i = 0; i < NMAX; ) {
    rSum += rTerm;
    if (rSum > rPoisson) return i;

    // Evaluate next term. 
    ++i;
    rTerm *= nAvg / i;
  }

  // Emergency return.
  return NMAX; 
}

vector <PseudoJet> pythia_input(Pythia & pythia)
{
    vector<PseudoJet> fjInputs;
    fjInputs.resize(0);

    //loop over particles
    for (int i = 0; i < pythia.event.size(); ++i) 
    {
        // Final state only
        if (!pythia.event[i].isFinal()) continue;
    
        // No neutrinos
        if (pythia.event[i].idAbs() == 12 || pythia.event[i].idAbs() == 14 ||
            pythia.event[i].idAbs() == 16) continue;

        // Only |eta| < ETAHIGH
        if (fabs(pythia.event[i].eta()) > ETAHIGH) continue;
        
        // Store as input to Fastjet
	PseudoJet onepseudojet(pythia.event[i].px(),
    						pythia.event[i].py(), pythia.event[i].pz(),
   						pythia.event[i].e());
        onepseudojet.set_user_index(i);
        fjInputs.push_back(onepseudojet);
    }
    
    return fjInputs;
}

vector<PseudoJet> fill_cal(Pythia & pythia, vector <int> & excluded)
//fill calorimeter cells from a pythia event
{
    vector<PseudoJet> fjInputs;
    fjInputs.resize(0);

    double cells[ETABINS][PHIBINS];
    for (int i = 0; i < ETABINS; i ++)
      for (int j = 0; j < PHIBINS; j ++)
        cells[i][j] = 0;
    double deta = (ETAHIGH - ETALOW)/ETABINS;
    double dphi = 2*PI/PHIBINS;
    
    //loop over particles
    
    for (int i = 0; i < pythia.event.size(); ++i) 
    {
        // Final state only
        if (!pythia.event[i].isFinal()) continue;
        bool exclude = false;
        for (int j = 0; j < excluded.size(); j ++)
	  if (i == excluded[j]) exclude = true;
        if (exclude) continue;
        // No neutrinos
        if (pythia.event[i].idAbs() == 12 || pythia.event[i].idAbs() == 14 ||
            pythia.event[i].idAbs() == 16) continue;

        // Only |eta| < ETAHIGH
        if (fabs(pythia.event[i].eta()) >= ETAHIGH) continue;
        
        
	PseudoJet tempjet(pythia.event[i].px(), pythia.event[i].py(), 
                                pythia.event[i].pz(), pythia.event[i].e());
        int ieta = (int) ((tempjet.eta() - ETALOW)/deta);
        int iphi = (int) (tempjet.phi()/dphi);
        cells[ieta][iphi] += tempjet.e();
        
    }
    
    for (int i = 0; i < ETABINS; i ++)
    for (int j = 0; j < PHIBINS; j ++)
    {
       double p = cells[i][j];
       if (p < 0.01) continue;
       double eta = ETALOW + (i + 0.5)*deta;
       double phi = (j + 0.5)*dphi;
     
       double pt = p/cosh(eta);
       double px, py, pz;
       px = pt*cos(phi);
       py = pt*sin(phi);
       pz = pt*sinh(eta);
       
       PseudoJet onepseudojet(px, py, pz, p);
       // Store as input to Fastjet
       fjInputs.push_back(onepseudojet);
    }
    return fjInputs;

}

vector<PseudoJet> fill_cal(Pythia & pythia)
//fill calorimeter cells from a pythia event
{
    vector<PseudoJet> fjInputs;
    fjInputs.resize(0);

    double cells[ETABINS][PHIBINS];
    for (int i = 0; i < ETABINS; i ++)
      for (int j = 0; j < PHIBINS; j ++)
        cells[i][j] = 0;
    double deta = (ETAHIGH - ETALOW)/ETABINS;
    double dphi = 2*PI/PHIBINS;
    
    //loop over particles
    
    for (int i = 0; i < pythia.event.size(); ++i) 
    {
        // Final state only
        if (!pythia.event[i].isFinal()) continue;
       
        // No neutrinos
        if (pythia.event[i].idAbs() == 12 || pythia.event[i].idAbs() == 14 ||
            pythia.event[i].idAbs() == 16) continue;

        // Only |eta| < ETAHIGH
        if (fabs(pythia.event[i].eta()) >= ETAHIGH) continue;
        
        
	PseudoJet tempjet(pythia.event[i].px(), pythia.event[i].py(), 
                                pythia.event[i].pz(), pythia.event[i].e());
        int ieta = (int) ((tempjet.eta() - ETALOW)/deta);
        int iphi = (int) (tempjet.phi()/dphi);
        cells[ieta][iphi] += tempjet.e();
        
    }
    
    for (int i = 0; i < ETABINS; i ++)
    for (int j = 0; j < PHIBINS; j ++)
    {
       double p = cells[i][j];
       if (p < 0.1) continue;
       double eta = ETALOW + (i + 0.5)*deta;
       double phi = (j + 0.5)*dphi;
     
       double pt = p/cosh(eta);
       double px, py, pz;
       px = pt*cos(phi);
       py = pt*sin(phi);
       pz = pt*sinh(eta);
       
       PseudoJet onepseudojet(px, py, pz, p);
       // Store as input to Fastjet
       fjInputs.push_back(onepseudojet);
    }
    return fjInputs;

}

vector<PseudoJet> fill_cal(Event & event, vector <int> excluded)
//fill calorimeter cells from a pythia event
{
    vector<PseudoJet> fjInputs;
    fjInputs.resize(0);

    double cells[ETABINS][PHIBINS];
    for (int i = 0; i < ETABINS; i ++)
      for (int j = 0; j < PHIBINS; j ++)
        cells[i][j] = 0;
    double deta = (ETAHIGH - ETALOW)/ETABINS;
    double dphi = 2*PI/PHIBINS;
    
    //loop over particles
    
    for (int i = 0; i < event.size(); ++i) 
    {
        // Final state only
        if (!event[i].isFinal()) continue;
       
        bool exclude = false;
        for (int j = 0; j < excluded.size(); j ++)
	   if (i == excluded[j]) 
	   {
               exclude = true;
               //cout << "excluded particle  ID = " << event[i].id() << "  status = " << event[i].status() << "  pt = " << event[i].pT() << endl;
           }
        if (exclude) continue;

        // No neutrinos
        if (event[i].idAbs() == 12 || event[i].idAbs() == 14 || event[i].idAbs() == 16) continue;

        // Only |eta| < ETAHIGH
        if (fabs(event[i].eta()) >= ETAHIGH) continue;
        
        
	PseudoJet tempjet(event[i].px(), event[i].py(), event[i].pz(), event[i].e());
        int ieta = (int) ((tempjet.eta() - ETALOW)/deta);
        int iphi = (int) (tempjet.phi()/dphi);
        cells[ieta][iphi] += tempjet.e();
        
    }
    
    for (int i = 0; i < ETABINS; i ++)
    for (int j = 0; j < PHIBINS; j ++)
    {
       double p = cells[i][j];
       if (p < 0.1) continue;
       double eta = ETALOW + (i + 0.5)*deta;
       double phi = (j + 0.5)*dphi;
     
       double pt = p/cosh(eta);
       double px, py, pz;
       px = pt*cos(phi);
       py = pt*sin(phi);
       pz = pt*sinh(eta);
       
       PseudoJet onepseudojet(px, py, pz, p);
       // Store as input to Fastjet
       fjInputs.push_back(onepseudojet);
    }
    return fjInputs;

}

vector<PseudoJet> fill_cal(Event & event)
//fill calorimeter cells from a pythia event
{
    vector<PseudoJet> fjInputs;
    fjInputs.resize(0);

    double cells[ETABINS][PHIBINS];
    for (int i = 0; i < ETABINS; i ++)
      for (int j = 0; j < PHIBINS; j ++)
        cells[i][j] = 0;
    double deta = (ETAHIGH - ETALOW)/ETABINS;
    double dphi = 2*PI/PHIBINS;
    
    //loop over particles
    
    for (int i = 0; i < event.size(); ++i) 
    {
        // Final state only
        if (!event[i].isFinal()) continue;
       
     
        // No neutrinos
        if (event[i].idAbs() == 12 || event[i].idAbs() == 14 || event[i].idAbs() == 16) continue;

        // Only |eta| < ETAHIGH
        if (fabs(event[i].eta()) >= ETAHIGH) continue;
        
        
	PseudoJet tempjet(event[i].px(), event[i].py(), event[i].pz(), event[i].e());
        int ieta = (int) ((tempjet.eta() - ETALOW)/deta);
        int iphi = (int) (tempjet.phi()/dphi);
        cells[ieta][iphi] += tempjet.e();
        
    }
    
    for (int i = 0; i < ETABINS; i ++)
    for (int j = 0; j < PHIBINS; j ++)
    {
       double p = cells[i][j];
       if (p < 0.1) continue;
       double eta = ETALOW + (i + 0.5)*deta;
       double phi = (j + 0.5)*dphi;
     
       double pt = p/cosh(eta);
       double px, py, pz;
       px = pt*cos(phi);
       py = pt*sin(phi);
       pz = pt*sinh(eta);
       
       PseudoJet onepseudojet(px, py, pz, p);
       // Store as input to Fastjet
       fjInputs.push_back(onepseudojet);
    }
    return fjInputs;

}

void add_pileup(Event & sumEvent)
{
   // Beam Energy.
   double eBeam = 7000.; 

   // Average number of pileup events per signal event.
   double nPileupAvg = 2.5;

   // Average number of beam-gas events per signal ones, on two sides.
   double nBeamAGasAvg = 0.5;
   double nBeamBGasAvg = 0.5;
   static bool inited = false;
   static Pythia pythiaPileup;
   static Pythia pythiaBeamAGas;
   static Pythia pythiaBeamBGas;
   
   if (!inited)
   {
      // Initialize generator for pileup (background) processes.
      pythiaPileup.readString("Random:setSeed = on");    
      pythiaPileup.readString("Random:seed = 10000002");     
      pythiaPileup.readString("SoftQCD:all = on");    
      pythiaPileup.init( 2212, 2212, 2. * eBeam);

      // Initialize generators for beam A - gas (background) processes. 
      pythiaBeamAGas.readString("Random:setSeed = on");    
      pythiaBeamAGas.readString("Random:seed = 10000003");     
      pythiaBeamAGas.readString("SoftQCD:all = on");    
      pythiaBeamAGas.init( 2212, 2212, eBeam, 0.);

      // Initialize generators for beam B - gas (background) processes. 
      pythiaBeamBGas.readString("Random:setSeed = on");    
      pythiaBeamBGas.readString("Random:seed = 10000004");     
      pythiaBeamBGas.readString("SoftQCD:all = on");    
      pythiaBeamBGas.init( 2212, 2212, 0., eBeam);
      inited = true;
   }
  
   // Select the number of pileup events to generate.
   int nPileup = poisson(nPileupAvg, pythiaPileup.rndm); 
  

   // Generate a number of pileup events. Add them to sumEvent.      
   for (int iPileup = 0; iPileup < nPileup; ++iPileup)
   {
       pythiaPileup.next();
       sumEvent += pythiaPileup.event;
   }

   // Select the number of beam A + gas events to generate.
   int nBeamAGas = poisson(nBeamAGasAvg, pythiaBeamAGas.rndm); 
 

   // Generate a number of beam A + gas events. Add them to sumEvent.      
   for (int iAG = 0; iAG < nBeamAGas; ++iAG) 
   {
       pythiaBeamAGas.next();
       sumEvent += pythiaBeamAGas.event;
   }
  
   // Select the number of beam B + gas events to generate.
   int nBeamBGas = poisson(nBeamBGasAvg, pythiaBeamBGas.rndm); 
  

   // Generate a number of beam B + gas events. Add them to sumEvent.      
   for (int iBG = 0; iBG < nBeamBGas; ++iBG) 
   {
      pythiaBeamBGas.next();
      sumEvent += pythiaBeamBGas.event;
   }
   
}
bool find_w(Event event, double pw[])
{
    bool found = false;
    for (int i = 0; i < event.size(); i ++)
    {
        if (event[i].idAbs() == 24) 
        {
           vector<int> daughters = event.daughterList(i);   

           for (int j = 0; j < daughters.size(); j++)   
           if (event[daughters[j]].idAbs() < 5)
           {
              found = true;
              copy_momentum(event[i], pw);
              break;
           }  
     
        }   
        if (found) break;
    }      
    return found;
}

//find the charged lepton from W decay.
int find_wlep(Event &event)
{
   
    for (int i = 0; i < event.size(); i ++)
    {
       if ((event[i].idAbs() == 11 || event[i].idAbs() == 13) && event[i].isFinal())//found a stable lepton
       {
          int lepid = event[i].id(); 
          int imother = event[i].mother1(); //mother index
          while (event[imother].id() == lepid) imother = event[imother].mother1(); //go back in event history, find the decaying particle
          if (event[imother].idAbs() == 24) return i;//mother is a W boson
       }
    }
    return -1;
}

bool prepare_inputs_ca(Event & event, int ifile, double ptmin, double ptmax, vector <PseudoJet> & fjInputs, double R0 = 1.2)
{
   //double R0 = 1.2;
   fjInputs.resize(0);

   //find the lepton from W decay
   int ilep = find_wlep(event);
   //cout << "ilep = " << ilep << endl;
   if (ilep < 0)
   {
       cout << "cannot find lepton from W decay" << endl;
       return false;
   }

   vector<int> excluded;
   excluded.resize(0); 
   excluded.push_back(ilep);   
   
   //use a large R0 to cluster
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   //use R0 for clustering
   jetDef = new JetDefinition(cambridge_algorithm, R0, recombScheme, strategy);
   
   vector <PseudoJet> input = fill_cal(event, excluded);

   ClusterSequence clustSeq(input, *jetDef);
   vector <PseudoJet> inclusiveJets = clustSeq.inclusive_jets();
   vector <PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   int njets= sortedJets.size();

   if (njets < 1) return false;

   if (sortedJets[0].perp() < ptmin || sortedJets[0].perp() > ptmax) return false;  
   
     
   if (ifile == 0)
   {
      double wp[4];
      bool foundw = find_w(event, wp);
      if (!foundw)
      {
         cout << " Cannot find W boson" << endl;
         return false;
      }

     
      int mini = 0;
      //for (int i = 0; i < njets; i ++)
      for (int i = 0; i < 1; i ++)
      {
         if (sortedJets[i].perp() < ptmin || sortedJets[i].perp() > ptmax) break;
         PseudoJet wparton(wp[1], wp[2], wp[3], wp[0]); 
         
        
      }  
      //if (mindr > 1.) return false;
      fjInputs = clustSeq.constituents(sortedJets[mini]);  
      return true;
      
   }

  if (ifile == 1)
  {
      fjInputs = clustSeq.constituents(sortedJets[0]);
      return true;
  }
}

bool prepare_inputs(Event & event, int ifile, double ptmin, double ptmax, vector <PseudoJet> & fjInputs)
{
   double R0 = 1.2;
   fjInputs.resize(0);

   //find the lepton from W decay
   int ilep = find_wlep(event);
   //cout << "ilep = " << ilep << endl;
   if (ilep < 0)
   {
       cout << "cannot find lepton from W decay" << endl;
       return false;
   }

   vector<int> excluded;
   excluded.resize(0); 
   excluded.push_back(ilep);   
   
   //use a large R0 to cluster
   Strategy               strategy = Best;
   RecombinationScheme    recombScheme = E_scheme;
   JetDefinition         *jetDef = NULL;
   //use R0 for clustering
   jetDef = new JetDefinition(kt_algorithm, R0, recombScheme, strategy);
   
   vector <PseudoJet> input = fill_cal(event, excluded);

   ClusterSequence clustSeq(input, *jetDef);
   vector <PseudoJet> inclusiveJets = clustSeq.inclusive_jets();
   vector <PseudoJet> sortedJets    = sorted_by_pt(inclusiveJets); 
   int njets= sortedJets.size();

   if (njets < 1) return false;

   if (sortedJets[0].perp() < ptmin || sortedJets[0].perp() > ptmax) return false;  
   //excluded.push_back(ilep);
     
   if (ifile == 0)
   {
      double wp[4];
      bool foundw = find_w(event, wp);
      if (!foundw)
      {
         cout << " Cannot find W boson" << endl;
         return false;
      }

    
      int mini = -1;
      //for (int i = 0; i < njets; i ++)
      for (int i = 0; i < 1; i ++)
      {
         if (sortedJets[i].perp() < ptmin || sortedJets[i].perp() > ptmax) break;
         PseudoJet wparton(wp[1], wp[2], wp[3], wp[0]); 
         
      }  
     
      fjInputs = clustSeq.constituents(sortedJets[mini]);  
      return true;
      
   }

  if (ifile == 1)
  {
      fjInputs = clustSeq.constituents(sortedJets[0]);
      return true;
  }
}


