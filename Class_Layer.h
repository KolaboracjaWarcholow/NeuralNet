#ifndef CLASS_LAYER_H
#define CLASS_LAYER_H
#include <iostream>
#include <vector>
#include "Class_Neuron.h"
#include "Class_Connection.h"
#include "Struct_Topology.h"

class Layer
{
public:

	std::vector <Neuron> myLayer;
	Layer();
	void FillOutputLayer(int);
	void FillLayer(const int, const int, std::vector<Connection>&);
};
#endif
