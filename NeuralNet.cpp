#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Class_Neuron.h"
#include "MathFunctions.h"
#include "Class_Connection.h"
#include "Class_Layer.h"
#include "Struct_Topology.h"
#include "FunctionsProcessingData.h"
using namespace std;

void CalculateErrorOnOutputLayer(Layer &OutputLayer, double DesignedOutputs[])
{
	double Error;
	for (int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		Error = DesignedOutputs[i] - OutputLayer.myLayer[i].GetOutput();
		OutputLayer.myLayer[i].ChangeError(Error);
	}
}
int main()

{
	double InputArray1[256];
	std::fill_n(InputArray1, 256, 0.5);
	double TestingArray[4] = { 0.3, 0.4, 0.6, 0.9 };
	double DesignedOutputs[26];
	std::fill_n(DesignedOutputs, 26, 0.5);
	Topology myTopology;
	vector<Connection> FirstConnectionsVector;
	vector<Connection> SecondConnectionsVector;
	vector<Connection> ThirdConnectionsVector;
	Layer OutputLayer(myTopology.NeuronsInOutputLayer);
	Layer SecondHiddenLayer(myTopology.NeuronsInOutputLayer, myTopology.NeuronsInSecondHiddenLayer, ThirdConnectionsVector);
	Layer FirstHiddenLayer(myTopology.NeuronsInSecondHiddenLayer, myTopology.NeuronsInFirstHiddenLayer, SecondConnectionsVector);
	Layer InputLayer(myTopology.NeuronsInFirstHiddenLayer, myTopology.NeuronsInInputLayer, FirstConnectionsVector, InputArray1);
	SetOutputOfBiasNeuron(InputLayer);
	SetOutputOfBiasNeuron(FirstHiddenLayer);
	SetOutputOfBiasNeuron(SecondHiddenLayer);
	ProcessDataForward(InputLayer, FirstHiddenLayer, FirstConnectionsVector);
	ProcessDataForward(FirstHiddenLayer, SecondHiddenLayer, SecondConnectionsVector);
	ProcessDataForwardToOutputLayer(SecondHiddenLayer, OutputLayer, ThirdConnectionsVector);
	CalculateErrorOnOutputLayer(OutputLayer, DesignedOutputs);
	getchar();
    return 0;
}


