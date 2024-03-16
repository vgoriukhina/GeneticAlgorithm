#pragma once
using namespace std;
#include <vector>
#include <iostream>
#include "CKnapsackProblem.h"
class CIndividual
{
public:
	CIndividual() { genotypeSize = 0; dFitness = 0; };
	CIndividual(int genSize);
	//CIndividual(CIndividual& copy);
	
	double fitness(CKnapsackProblem &pr); //NIE REF ABY NIE ZMIENIAC
	void mutation(double mutProb);
	CIndividual crossing(CIndividual& par2);
	int getGenotypeSize();
	std::vector<int>* getGenotype();
	void printGen();
	void copy(CIndividual& otherIndividual);
	double getFitness();
private:
	std::vector<int> genotype;
	double dFitness;
	int genotypeSize;
};


