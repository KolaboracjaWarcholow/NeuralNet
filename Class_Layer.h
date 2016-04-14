#ifndef CLASS_LAYER_H
#define CLASS_LAYER_H
#include <iostream>
#include <vector>
#include "Class_Neuron.h"
#include "Class_Connection.h"

class Layer
{
public:

	std::vector <Neuron> myLayer;

	Layer(int);
	Layer(const int, const int, std::vector<Connection>&);
	Layer(const int, const int, std::vector<Connection>&, double[]);
};
#endif
