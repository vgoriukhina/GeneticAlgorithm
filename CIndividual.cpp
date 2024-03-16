#include "CIndividual.h"
#include<random>

/*
CIndividual::CIndividual(CIndividual& copy)
{
    genotypeSize = copy.genotypeSize;
    for (int i = 0; i < copy.genotypeSize; i++) {
        genotype[i] = copy.genotype[i];
    }
}
*/

CIndividual::CIndividual(int genSize)
{
    genotypeSize = genSize;
    dFitness = 0;
}

double CIndividual::fitness(CKnapsackProblem& pr)
{
    dFitness = (pr).evaluate(genotype);
    return dFitness;
}

 void CIndividual::mutation(double mutProb)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0, 1);

    for (int j = 0; j < genotypeSize; j++) {
        double mutationProb = distrib(gen);
        if (mutationProb < mutProb)
        {
            if (genotype[j] == 0)
                genotype[j] = 1;
            else
                genotype[j] = 0;
        }
    }
}

CIndividual CIndividual::crossing(CIndividual& par2) //wskaźnik???
{
    CIndividual child(genotypeSize);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, genotypeSize - 1);

   // cout << "parents:" << endl;
   // cout << "par1: ";
    //printGen();
    //cout << "par2: ";
    //par2->printGen();
    int edgeOfGen = distrib(gen);
    //cout << "edge: " << edgeOfGen;
    for (int i =0; i < genotypeSize; i++) 
    {
        if (i < edgeOfGen)
        {
            child.genotype.push_back(genotype[i]);
        }
        else
        {
            child.genotype.push_back(par2.genotype[i]);
        }
    }
    //cout << "child: ";
   // child.printGen();
    return child;
}

int CIndividual::getGenotypeSize()
{
    return genotypeSize;
}


std::vector<int>* CIndividual::getGenotype()
{
    return &genotype;
}

void CIndividual::printGen()
{
    for (int i = 0; i < genotype.size(); i++) {
        cout << genotype[i];
    }
}

void CIndividual::copy(CIndividual& otherIndividual)
{
    genotype.clear();
    genotypeSize = otherIndividual.genotypeSize;
   // cout <<"size"<< genotypeSize << endl;
    //cout << "fitness" << dFitness << endl;
    dFitness = otherIndividual.dFitness;
    
    //cout << "fitness" << otherIndividual.dFitness << endl;

    for (int i = 0; i < genotypeSize; i++)
    {
        genotype.push_back(otherIndividual.genotype[i]);
    }
}

double CIndividual::getFitness()
{
    return dFitness;
}
