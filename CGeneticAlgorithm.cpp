#include "CGeneticAlgorithm.h"
#include <random>


CGeneticAlgorithm::CGeneticAlgorithm(int population_size,CKnapsackProblem pr)
{
	
	popSize = population_size;
	problem = pr;
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> distrib(0, 1);
	if (pr.getNumberOfValues() > 0&&pr.getCapacity()>0) {
		cout << "capacity: " << problem.getCapacity() << endl;
		cout << "\nfirst population" << endl;
		for (int i = 0; i < popSize; i++)
		{
			CIndividual firstPopChild = CIndividual(problem.getNumberOfValues());
			for (int j = 0; j < firstPopChild.getGenotypeSize(); j++)
			{
				firstPopChild.getGenotype()->push_back(distrib(gen));
			}
			firstPopChild.fitness(problem);
			population.push_back(firstPopChild);
		}
		//printPop();

		bestIndividual.copy(population[0]);
		for (int i = 0; i < 1000; i++)
		{
			crossing();
			mutation();
			renewBestIndividual();
			//printPop();
		}
		cout << "Best individual fitness: " << bestIndividual.getFitness() << endl;
		cout << "Best individual gen: ";
		bestIndividual.printGen();
	}
}

void CGeneticAlgorithm::crossing()  //find 2 best parents(fitness)
{
	vector<CIndividual> newPopulation;
	int counter = 0;
	while (counter < popSize)
	{
		CIndividual par1(getProblem()->getNumberOfValues());
		CIndividual par2(getProblem()->getNumberOfValues());
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, popSize - 1);

		chooseParent(par1);
		chooseParent(par2);

		std::uniform_real_distribution<> (0, 1);
		if (distrib(gen) > crossProb)
		{
			CIndividual child = (par1.crossing(par2));
			//cout << "child:";
			//child.printGen();
			//cout << endl;

			newPopulation.push_back(child); //wyciek pamieci?
			counter++;
		}
		else
		{
			//cout << "no crossing\n";
			if ((popSize - 2) > newPopulation.size())
			{
				newPopulation.push_back(par1);
				newPopulation.push_back(par2);
			}
			else newPopulation.push_back(par1);
			
		}

	}
	population.clear();
	population = newPopulation;
	
}

void CGeneticAlgorithm::mutation()
{
	int genSize = population[0].getGenotypeSize();
	for (int i = 0; i < popSize; i++)
	{
		population[i].mutation(mutProb);
	}
}

CKnapsackProblem* CGeneticAlgorithm::getProblem()
{
	return &problem;
}

CIndividual CGeneticAlgorithm::chooseParent(CIndividual& par)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, popSize - 1);

	int index1 = distrib(gen);
	int index2 = distrib(gen);
	//cout <<"ind1: "<< index1 << " ind2: " << index2 << endl;
	CIndividual par1 = population[index1];
	CIndividual par2 = population[index2];
	//par11.getGenotype();
	//par12.getGenotype();
	//cout << "finding parent1" << endl;
	if (par1.fitness(problem) > par2.fitness(problem))
	{
		par = par1;
	}
	else par = par2;
	//cout << "par1: ";
	//par1.printGen();

	//cout << "ind1: " << index1 << " ind2: " << index2 << endl;
	//cout << "finding parent2" << endl;

	return par;
}

void CGeneticAlgorithm::renewBestIndividual()
{
	 
	for (int i = 0; i < popSize; i++) {
		if (bestIndividual.getFitness()<population[i].fitness(problem)) {
			bestIndividual.copy(population[i]);
		}
	}
}

void CGeneticAlgorithm::printPop()
{
	cout << endl;
	for (int i = 0; i < popSize; i++) 
	{
		cout << i << ")";
		population[i].printGen();
		cout << "   ";
	}
	cout << endl;
}
