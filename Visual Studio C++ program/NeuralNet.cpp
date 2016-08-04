#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include "Class_Neuron.h"
#include "Class_Connection.h"
#include "Class_Layer.h"
#include "Class_Net.h"
#include "Struct_Topology.h"
#include "FunctionsProcessingData.h"
#include "LearningData.h"
#include "FunctionsForFiles.h"
using namespace std;
const char *FilePathForErrors = "ErrorsFile.txt";
const char *FilePathForDesiredOutputs = "DesiredOutputs.txt";
const char *FirstConnectionsVectorFilePath = "FirstConnectionsVectorWeights.txt";
const char *SecondConnectionsVectorFilePath = "SecondConnectionsVectorWeights.txt";
const char *ThirdConnectionsVectorFilePath = "ThirdConnectionsVectorWeights.txt";
const double LearningRate = 0.4;
const int BIAS_OUTPUT = 1;
const int AlphabetSize = 23;

int main()

{
	vector<double> ErrorsVector;
	vector<vector<double>> LearningSet;
	vector<vector<double>> DesiredOutputs;
	Topology myTopology;
	cout << "Creating a net with " << myTopology.NeuronsInInputLayer << " neurons in input layer and with " << myTopology.NeuronsInOutputLayer << " neurons in output layer." << endl;
	cout << "Learning rate is equal to: " << LearningRate << endl;
	Net myNet(myTopology);
	cout << "Net successfully created!" << endl;
	SetOutputOfBiasNeuron(myNet.InputLayer, BIAS_OUTPUT);
	SetOutputOfBiasNeuron(myNet.FirstHiddenLayer,BIAS_OUTPUT);
	SetOutputOfBiasNeuron(myNet.SecondHiddenLayer, BIAS_OUTPUT);
	cout << "Loading in a training set..." << endl;
	LoadInLearningSet(LearningSet, myTopology.NeuronsInInputLayer);
	cout << "Training set succesfully loaded, it contains " << LearningSet.size()/AlphabetSize << " examples of an alfabet." << endl;
	cout << "Loading in Desired outputs for letters..." << endl;
	LoadInDesiredOutputs(DesiredOutputs, myTopology.NeuronsInOutputLayer, FilePathForDesiredOutputs);
	cout << "Desired outputs successfully loaded!" << endl;
	cout << "Learning in process..." << endl;
	double TotalError = 1;
	int ErrorsIndex = 0;
	double ErrorSum = 10;
	int i = 0;
	while (ErrorSum > 0.007)
	{
		ErrorSum = 0;
		for (unsigned int k = 0; k < AlphabetSize; k++)
		{
			myNet.Learn(LearningSet[i], DesiredOutputs[k], LearningRate);
			TotalError = myNet.SumUpSquaredErrors();
			cout << TotalError << endl;
			myNet.UpdateWeights();
			i++;
			ErrorSum = ErrorSum + TotalError;
			if (i == LearningSet.size())
				i = 0;
		}
		ErrorsIndex++;
		cout << "                          " << ErrorSum << endl;
		if (ErrorsIndex % 12 == 0)
		ErrorsVector.push_back(ErrorSum);
	}
	cout << "Learning done!" << endl;
	cout << "Printing Weights to a file..." << endl;
	myNet.PrintWeightsToFile(FirstConnectionsVectorFilePath, SecondConnectionsVectorFilePath, ThirdConnectionsVectorFilePath);
	cout << "Weights printed!" << endl;
	PrintErrorsToFile(FilePathForErrors, ErrorsVector);

    return 0;
}
