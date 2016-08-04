#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <random>

const double BETA = 1;

double ActivationFunction(double NeuronOutput)
{
	return 1 / (1 + exp(-BETA * NeuronOutput));
}

double CalculateDerivative(double Input)
{
	return	Input * (1 - Input);
}

#endif 
