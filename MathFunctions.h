#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cmath>

const double BETA = 0.01;

double ActivationFunction(double NeuronOutput)
{
	return 1 / (1 + exp(-BETA * NeuronOutput));
}

double Derivative(double Input)
{
	return	exp(-Input) / pow((1 + exp(-Input)), 2);
}
#endif 
