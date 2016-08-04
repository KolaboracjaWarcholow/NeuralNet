#include "stdafx.h"
#include "Class_Layer.h"

Layer::Layer()
{}
void Layer::FillOutputLayer(int NeuronsNumber)
{
	for (int i = 0; i < NeuronsNumber; i++)
	{
		Neuron newNeuron;
		myLayer.push_back(newNeuron);
	}
};

void Layer::FillLayer(const int NeuronsInNextLayer, const int NeuronsInThisLayer, std::vector<Connection> &ConnectionsVector)
{
	for (int i = 0; i < NeuronsInThisLayer + 1; ++i)
	{
		Neuron newNeuron(NeuronsInNextLayer, ConnectionsVector);
		myLayer.push_back(newNeuron);
	}
}

//Layer::Layer(const int NeuronsInNextLayer, const int NeuronsInThisLayer, std::vector<Connection> &ConnectionsVector, double InputArray[])
//{
//	for (int i = 0; i < NeuronsInThisLayer + 1; i++)
//	{
//		Neuron newNeuron(NeuronsInNextLayer, ConnectionsVector);
//		newNeuron.ChangeOutput(InputArray[i]);
//		myLayer.push_back(newNeuron);
//	}
//}