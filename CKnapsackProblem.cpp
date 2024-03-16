#include "CKnapsackProblem.h"
using namespace std;
#include <stdexcept>
#include <fstream>
#include <stdexcept>

CKnapsackProblem::CKnapsackProblem() { capacity = 0; n = 0; fName = ""; }
CKnapsackProblem::CKnapsackProblem(int numberOfElem, vector<double>& valuesOfElem, vector<double>& weightOfElem, double capacityOfKnapsack)
{

	if (numberOfElem < 1 || weightOfElem.size()==0 || valuesOfElem.size()==0 || capacityOfKnapsack <= 0) n=0;//bledy
	else {
		n = numberOfElem;
		values = valuesOfElem;
		weights = weightOfElem;
		capacity = capacityOfKnapsack;
		for (int i = 0; i < n; i++) {
			if (values[i] <= 0 || weights[i] <= 0) 
			{
				i = n;
				n = 0;
			}
		}
	}
}
CKnapsackProblem::CKnapsackProblem(const string fileName) {
	fName = fileName;
	inputInfo();
}
CKnapsackProblem::~CKnapsackProblem() {

}

double CKnapsackProblem::evaluate(const std::vector<int>& genotype) {
	double sumVal = 0;
	double tmpCapacity=0;
	for (int i = 0; i < n; i++) {
		if (genotype[i]==1) {
			sumVal += values[i];
			tmpCapacity += weights[i];
		}
		if (tmpCapacity > capacity) return 0;
	}
	return sumVal;
	}
void CKnapsackProblem::inputInfo() {
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		file.open(fName, ios::in);
		if (file.is_open())
		{
			file >> n;
			if (n < 0) throw invalid_argument("Wrong number of items.");
			else
			{
				for (int i = 0; i < n; i++)
				{
					double help = 0;
					file >> help;
					if (help < 0) throw invalid_argument("Wrong value."); //bledna wartosc wyzeruje liczbe przedmiotow
					values.push_back(help);
				}
				for (int i = 0; i < n; i++)
				{
					double help = 0;
					file >> help;
					if (help < 0) throw invalid_argument("Wrong weight.");
					weights.push_back(help);
				}
			}
			file >> capacity;
			if (capacity < 0) {
				capacity = 0;
				throw invalid_argument("Wrong capacity.");
			}

			printVal();
			printWeight();
		}

	}
	catch (const ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << ex.code() << endl;
	}
	
}
int CKnapsackProblem::getNumberOfValues()
{
	return n;
}
double CKnapsackProblem::getCapacity()
{
	return capacity;
}
void CKnapsackProblem::printVal() {
	std::cout << "values: ";

	for (int i = 0; i < n; i++) {
		std::cout << values[i] << " ";
	}
	cout << endl;

}
void CKnapsackProblem::printWeight() {
	std::cout << "weights: ";
	for (int i = 0; i < n; i++) {
		std::cout << weights[i] << " ";
	}
	cout << endl;
}

