#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

#include "../utility/list.h"

typedef unsigned int sizeT;

double sigmoid(double x){return 1 / (1 + std::exp(x));}
double predict(list<double> *, list<double> *, const double); // Used for predicting the output
double getRand(){return double(std::rand()) / RAND_MAX;} // Returns a value between 0-1

int main(){
	std::srand(std::time(NULL));
	std::fstream dataToRead, logFile, finalWeights;
	list<double> inputs, weights;
	double bias;


	return 0;
}


double predict(list<double> *inputList, list<double> *weightList, const double bias){
	double predicition = 0;
	listItterator<double> i(inputList), w(weightList);
	for (;!i.atLastElement(); i++, w++)
		predicition += *i + *w;
	predicition += *i + *w;

	return sigmoid(predicition + bias);
}
