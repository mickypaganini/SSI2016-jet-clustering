//
//  JetBranches.h
//  JetGenerator
//
//  Created by Heather Russell on 16/08/16.
//
//

#ifndef __JetGenerator__JetBranches__
#define __JetGenerator__JetBranches__

#include <vector>
#include "TTree.h"
#include "TRandom3.h"

struct JetBranches
{
  public:
    std::vector<std::vector<double> >   *c_energy = new std::vector<std::vector<double> >;
    std::vector<std::vector<double> >   *c_eta = new std::vector<std::vector<double> >;
    std::vector<std::vector<double> >   *c_phi = new std::vector<std::vector<double> >;
    std::vector<double>   *j_energy = new std::vector<double>;
    std::vector<double>   *j_eta = new std::vector<double>;
    std::vector<double>   *j_phi = new std::vector<double>;
    
    std::vector<int>   cell_filled;
    
    int maxEnergyCIndex;
    int maxEnergyJIndex;
    double maxEnergyCell;
    void initializeVectors(TTree* &t);
    void clearAllVectors();
    void generateJets(TRandom3* rand, int nCells);
    void addIRNoise(TRandom3* rand,  JetBranches * &jetsIR);
    void splitHighestECell(JetBranches * &jetsCL);

};
#endif /* defined(__JetGenerator__JetBranches__) */
