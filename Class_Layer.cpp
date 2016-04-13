#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Class_Layer.h"
#include "Struct_Topology.h"


Layer::Layer(int NeuronsNumber)
{
	for (int i = 0; i < NeuronsNumber; i++)
	{
		Neuron newNeuron;
		myLayer.push_back(newNeuron);
	}
};

Layer::Layer(const int NeuronsInNextLayer, const int NeuronsInThisLayer, std::vector<Connection> &ConnectionsVector)
{
	for (int i = 0; i < NeuronsInThisLayer; ++i)
	{
		Neuron newNeuron(NeuronsInNextLayer, ConnectionsVector);
		myLayer.push_back(newNeuron);
	}
}

Layer::Layer(const int NeuronsInNextLayer, const int NeuronsInThisLayer, std::vector<Connection> &ConnectionsVector, double InputArray[])
{
	for (int i = 0; i < NeuronsInThisLayer; ++i)
	{
		Neuron newNeuron(NeuronsInNextLayer, ConnectionsVector, InputArray);
		myLayer.push_back(newNeuron);
	}
}