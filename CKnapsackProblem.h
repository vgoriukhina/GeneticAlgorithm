#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <string>
class CKnapsackProblem
{
public:
	CKnapsackProblem();
	CKnapsackProblem(int n, vector<double>& values, vector<double>& weights, double capacity);
	CKnapsackProblem(const string fileName);
	~CKnapsackProblem();
	double evaluate(const std::vector<int>& genotype);
	
	int getNumberOfValues();
	double getCapacity();
	void printVal();
	void printWeight();
private:
	void inputInfo();

	int n;
	std::vector<double> values;
	std::vector<double> weights;
	double capacity;
	string fName;
};

