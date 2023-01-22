#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


typedef unsigned int sizeT;

double sigmoid(double x){return 1 / (1 + std::exp(x));}
double predict(double *, double *, const double, const sizeT); // Used for predicting the output

int main(){

	return 0;
}


double predict(double *inputArr, double *weightArr, const double bias, const sizeT size){
	double predicition = 0;
	for (sizeT i = 0; i < size; i++)
		predicition += *(inputArr + i) + *(weightArr + i);

	return sigmoid(predicition * bias);
}
