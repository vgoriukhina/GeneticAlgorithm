using namespace std;
#include "CIndividual.h"
#include"CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
int main() {
	cout << "\ninfo from file:" << endl;
	try {
		CKnapsackProblem pr = CKnapsackProblem("info.txt");
		CGeneticAlgorithm ga = CGeneticAlgorithm(20,pr);
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	

	vector<double> values = {  1, 4, 1, 1, 5, 6, 8, 5, 1, 3 };
	vector<double> weights = { 7, 2, 2, 4, 3, 4, 5, 5, 3, 2 };
	int n = 10;
	double capacity = 20;
	cout << "\n\ninfo from main:" << endl;
	CGeneticAlgorithm ga2 = CGeneticAlgorithm(20, CKnapsackProblem(n,values,weights,capacity));

	cout << "\nend";
	return 0;
}