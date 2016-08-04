#ifndef CLASS_NET
#define CLASS_NET
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Class_Connection.h"
#include "Class_Layer.h"
#include "Class_Neuron.h"
#include "Struct_Topology.h"

class Net
{
public:
	std::vector<Connection> FirstConnectionVector;
	std::vector<Connection> SecondConnectionVector;
	std::vector<Connection> ThirdConnectionVector;
	Layer InputLayer;
	Layer FirstHiddenLayer;
	Layer SecondHiddenLayer;
	Layer OutputLayer;

	Net(Topology);
	void ProcessDataForwardToFirstHiddenLayer();
	void ProcessDataForwardToSecondHiddenLayer();
	void ProcessDataForwardToOutputLayer();
	void ChangeOutputsInInputLayer(const std::vector<double> NewInputs);
	void BackPropFirstHiddenLayer(const double LearningRate);
	void BackPropSecondHiddenLayer(const double LearningRate);
	void BackPropOutputLayer(const double LearningRate, std::vector<double> DesiredOutputs);
	void UpdateWeightsFirstHiddenLayer();
	void UpdateWeightsSecondHiddenLayer();
	void UpdateWeightsOutputLayer();
	void ResetSquaredError();
	double SumUpSquaredErrors();
	void CalculateSquaredErrorOnOutputLayer(std::vector<double> DesignedOutputs);
	void ResetInputs(Layer & CurrentLayer);
	void ResetDeltaWeight(std::vector<Connection>& Connections);
	void Learn(const std::vector<double> Inputs, std::vector<double> OutputArray, const double LearningRate);
	void UpdateWeights();
	void PrintWeightsToFile(const char * FirstVectorFilePath, const char * SecondVectorFilePath, const char * ThirdVectorFilePath);
	void LoadInWeights(const char * FirstVectorFilePath, const char * SecondVectorFilePath, const char * ThirdVectorFilePath);
	void CheckPrecision(std::vector<std::vector<double>> trainingSet, std::vector<std::vector<double>> DesiredOutputs);
};
#endif 
