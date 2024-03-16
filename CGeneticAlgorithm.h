#pragma once
#include <iostream>
#include "CIndividual.h"
#include "CKnapsackProblem.h"
using namespace std;
class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int population_size,CKnapsackProblem pr);
	void crossing(); //warunek konca krzyrzowania
	void mutation();
	CKnapsackProblem* getProblem() ;
	CIndividual chooseParent(CIndividual& par);
	void renewBestIndividual();
	void printPop();
private:
	int popSize;
	double crossProb=0.7;
	double mutProb=0.2;
	std::vector<CIndividual> population;
	CKnapsackProblem problem;
	CIndividual bestIndividual;
};

