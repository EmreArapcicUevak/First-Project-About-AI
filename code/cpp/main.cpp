#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

#include "../utility/list.h"

typedef unsigned int sizeT;

double sigmoid(double x){return 1 / (1 + std::exp(x));}
double predict(list<double> *, list<double> *, const double); // Used for predicting the output
double getRand(){return double(std::rand()) / RAND_MAX;} // Returns a value between 0-1
void train(list<double> &,list<double>&,list<list<double>>&, double &, unsigned int, double, std::fstream&);

int main(){
	std::srand(std::time(NULL));

	std::fstream dataToRead, logFile, savedWeights;
	list<list<double>> inputs;
	list<double> result, weights;
	double bias;

	dataToRead.open("../../data/data.txt", std::ios::in);
	if (!dataToRead.is_open())
		return -1;

	while (!dataToRead.eof()){
		if (dataToRead.peek() == '#')
			dataToRead.ignore(200, '\n');
		else {
			list<double> input;
			double i;

			for (unsigned int j = 0; j < 2; j++){
				dataToRead >> i;
				input.add(i, input.getSize());
			}

			dataToRead >> i;
			result.add(i, result.getSize());
			inputs.add(input, inputs.getSize());

		}
	}
	dataToRead.close();
	
	savedWeights.open("../../data/savedWeights.txt", std::ios::in);

	if (savedWeights.is_open()){
		double weight;
		for (unsigned int i = 0; i <  2; i++){
			savedWeights >> weight;
			weights.add(weight, weights.getSize());
		}


		savedWeights.close();
	}else
		for (unsigned int i = 0; i < 2; i++)
			weights.add(rand());


	for (listItterator<double> r(result); !r.isOutside(); r++)
		std::cout << *r << ' ';
	std::cout << std::endl;

	for (listItterator<list<double>> i(inputs); !i.isOutside(); i++){
		for (listItterator<double> j(*i); !j.isOutside(); j++)
			std::cout << *j << ' ';
		std::cout << std::endl;
	}


	for (listItterator<double> r(weights); !r.isOutside(); r++)
		std::cout << *r << ' ';

	logFile.open("../../data/log.txt", std::ios::ate);

	if (!logFile.is_open())
		logFile.open("../../data/log.txt", std::ios::out);
		

	train(weights, result, inputs, bias, 1000, .001, logFile);

	savedWeights.open("../../data/savedWeights.txt", std::ios::out  | std::ios::trunc);
	for (listItterator<double> w(weights); !w.isOutside(); w++)
		savedWeights << *w << ' '; 
	savedWeights.close();

	


	logFile.close();
	std::cin >> bias;
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

void train(list<double> & weights, list<double>& results, list<list<double>>& inputs,double &bias ,unsigned int epoch, double step, std::fstream& Ostream){
	listItterator<list<double>> inputIt(inputs);
	listItterator<double> r(results);

	step = step < 0 ? step : -step;

	for (unsigned int i = 0; i < inputs.getSize(); i++, inputIt++, r++){
		for (unsigned int j = 0; j < epoch; j++) {
			double pred = sigmoid(weights[0] * (*inputIt)[0] + weights[1] * (*inputIt)[1] + bias);
			double error = pred - *r;
			error *= error;

			Ostream << error << '\n';
			weights[0] += 2*(pred - *r) * pred * (1 - pred) * (*inputIt)[0] * step;
			weights[1] += 2*(pred - *r) * pred * (1 - pred) * (*inputIt)[1] * step;
			bias += 2*(pred - *r) * pred * (1 - pred) * step; 
		}
	}
}
