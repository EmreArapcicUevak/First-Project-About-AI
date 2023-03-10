#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "../utility/list.h"

typedef unsigned int sizeT;

double sigmoid(double x){return 1 / (1 + std::exp(-x));}
double predict(list<double> *, list<double> *, const double); // Used for predicting the output
double getRand(){return double(std::rand()) / RAND_MAX;} // Returns a value between 0-1
void printProgressBar(unsigned int);
void train(list<double> &,list<double>&,list<list<double> >&, double &, unsigned int, double, std::fstream&);

int main(){
	std::srand(std::time(NULL));

	std::fstream dataToRead, logFile, savedWeights;
	list<list<double> > inputs;
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

		savedWeights >> weight;
		bias = weight;

		savedWeights.close();
	}else{
		for (unsigned int i = 0; i < 2; i++)
			weights.add(getRand());
		bias = getRand();
	}

	logFile.open("../../data/log.txt", std::ios::ate);

	if (!logFile.is_open())
		logFile.open("../../data/log.txt", std::ios::out);
		
try{
	train(weights, result, inputs, bias, 999, .01, logFile);
}catch(char const *e){
	std::cout << e; 
}

	savedWeights.open("../../data/savedWeights.txt", std::ios::out  | std::ios::trunc);
	for (listItterator<double> w(weights); !w.isOutside(); w++)
		savedWeights << *w << ' '; 
	savedWeights << bias;
	savedWeights.close();

	


	logFile.close();
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

void printProgressBar(unsigned int percentage){
	static unsigned int previousProgress = 0,numberOfChars = 10;
	static bool newBar = true;
	static unsigned int npp = 100/numberOfChars;
	if (previousProgress == percentage && !newBar)
		return;

	newBar = false;
	std::cout << ' ' << '\r' << '[';
	for (unsigned int i = 1; i <= numberOfChars ; i++)
		if (percentage >= npp*i) 
			std::cout << '*';
		else 
			std::cout << ' ';
	std::cout << ']' << percentage << '%' << std::endl;
	previousProgress = percentage;

	if (percentage == 100)
		newBar = true;
}
void train(list<double> & weights, list<double>& results, list<list<double> >& inputs,double &bias ,unsigned int epoch, double step, std::fstream& Ostream){
	listItterator<double> r(results);

	step = step < 0 ? step : -step;
	printProgressBar(0);
	for (unsigned int j = 0; j < epoch; j++) {
		double error = 0;
		double tempBias = bias;
		list<double> tempWeights = weights;
		for (listItterator<list<double> > inputIt(inputs); !inputIt.isOutside(); inputIt++, r++){
			double pred = sigmoid(weights[0] * (*inputIt)[0] + weights[1] * (*inputIt)[1] + bias);
			error += (pred - *r)*(pred - *r);

			for (unsigned int i = 0; i < tempWeights.getSize(); i++)
				tempWeights[i] += 2*(pred - *r) * pred * (1 - pred) * (*inputIt)[i] * step;
			
			tempBias += 2*(pred - *r) * pred * (1 - pred) * step; 
		}

		printProgressBar(double(j+1)/epoch * 100);
		Ostream << error / inputs.getSize() << '\n';
		weights = tempWeights;
		bias = tempBias;
		r.putAtStart();
	}
}
