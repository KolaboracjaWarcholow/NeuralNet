#ifndef PROCESSING_DATA_H
#define PROCESSING_DATA_H
#include <iostream>
#include <vector>
#include "Class_Layer.h"
#include "MathFunctions.h"
void ProcessDataForward(Layer LeftLayer, Layer &RightLayer, std::vector<Connection> Connections)
{
	double Result = 0;
	double OutputAfterActivation = 0;
	int ConnectionsCounter = 0;

	for (int i = 0; i < RightLayer.myLayer.size() - 1; i++)
	{
		for (int j = 0; j < LeftLayer.myLayer.size(); j++)
		{

			Result = LeftLayer.myLayer[j].GetOutput() * Connections[ConnectionsCounter].GetWeight();
			RightLayer.myLayer[i].SumUpOutputs(Result);
			ConnectionsCounter++;
		}
		OutputAfterActivation = ActivationFunction(RightLayer.myLayer[i].GetInput());
		RightLayer.myLayer[i].ChangeOutput(OutputAfterActivation);
	}
}

void ProcessDataForwardToOutputLayer(Layer LeftLayer, Layer &RightLayer, std::vector<Connection> Connections)
{
	double Result = 0;
	double OutputAfterActivation = 0;
	int ConnectionsCounter = 0;

	for (int i = 0; i < RightLayer.myLayer.size(); i++)
	{
		for (int j = 0; j < LeftLayer.myLayer.size(); j++)
		{

			Result = LeftLayer.myLayer[j].GetOutput() * Connections[ConnectionsCounter].GetWeight();
			RightLayer.myLayer[i].SumUpOutputs(Result);
			ConnectionsCounter++;
		}
		OutputAfterActivation = ActivationFunction(RightLayer.myLayer[i].GetInput());
		RightLayer.myLayer[i].ChangeOutput(OutputAfterActivation);
	}
}

void SetOutputOfBiasNeuron(Layer &BiasLayer)
{
	if (!BiasLayer.myLayer.empty())
		BiasLayer.myLayer.back().ChangeOutput(1);
}

void CalculateErrorOnOutputLayer(Layer &OutputLayer, double DesignedOutputs[])
{
	double Error;
	for (int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		Error = DesignedOutputs[i] - OutputLayer.myLayer[i].GetOutput();
		OutputLayer.myLayer[i].ChangeError(Error);
	}
}
#endif
