#include "stdafx.h"
#include "Class_Net.h"
#include "MathFunctions.h"
using namespace std;

Net::Net(Topology myTopology)
{
	OutputLayer.FillOutputLayer(myTopology.NeuronsInOutputLayer);
	SecondHiddenLayer.FillLayer(myTopology.NeuronsInOutputLayer, myTopology.NeuronsInSecondHiddenLayer, ThirdConnectionVector);
	FirstHiddenLayer.FillLayer(myTopology.NeuronsInSecondHiddenLayer, myTopology.NeuronsInFirstHiddenLayer, SecondConnectionVector);
	InputLayer.FillLayer(myTopology.NeuronsInFirstHiddenLayer, myTopology.NeuronsInInputLayer, FirstConnectionVector);
}

void Net::ProcessDataForwardToFirstHiddenLayer()
{
	const int BIAS_NEURON = 1;
	double Result = 0;
	double OutputAfterActivation = 0;
	int ConnectionsCounter = 0;

	for (unsigned int i = 0; i < FirstHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		ConnectionsCounter = i;
		for (unsigned int j = 0; j < InputLayer.myLayer.size(); j++)
		{

			Result = InputLayer.myLayer[j].GetOutput() * FirstConnectionVector[ConnectionsCounter].GetWeight();
			FirstHiddenLayer.myLayer[i].SumUpOutputs(Result);
			ConnectionsCounter = ConnectionsCounter + (FirstHiddenLayer.myLayer.size() - BIAS_NEURON);
		}
		OutputAfterActivation = ActivationFunction(FirstHiddenLayer.myLayer[i].GetInput());
		FirstHiddenLayer.myLayer[i].ChangeOutput(OutputAfterActivation);
	}
}
void Net::ProcessDataForwardToSecondHiddenLayer()
{
	const int BIAS_NEURON = 1;
	double Result = 0;
	double OutputAfterActivation = 0;
	int ConnectionsCounter = 0;

	for (unsigned int i = 0; i < SecondHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		ConnectionsCounter = i;
		for (unsigned int j = 0; j < FirstHiddenLayer.myLayer.size(); j++)
		{

			Result = FirstHiddenLayer.myLayer[j].GetOutput() * SecondConnectionVector[ConnectionsCounter].GetWeight();
			SecondHiddenLayer.myLayer[i].SumUpOutputs(Result);
			ConnectionsCounter = ConnectionsCounter + (SecondHiddenLayer.myLayer.size() - BIAS_NEURON);
		}
		OutputAfterActivation = ActivationFunction(SecondHiddenLayer.myLayer[i].GetInput());
		SecondHiddenLayer.myLayer[i].ChangeOutput(OutputAfterActivation);
	}
}
void Net::ProcessDataForwardToOutputLayer()
{
	double Result = 0;
	double OutputAfterActivation = 0;
	int ConnectionsCounter = 0;

	for (unsigned int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		ConnectionsCounter = i;
		for (unsigned int j = 0; j < SecondHiddenLayer.myLayer.size(); j++)
		{

			Result = SecondHiddenLayer.myLayer[j].GetOutput() * ThirdConnectionVector[ConnectionsCounter].GetWeight();
			OutputLayer.myLayer[i].SumUpOutputs(Result);
			ConnectionsCounter = ConnectionsCounter + OutputLayer.myLayer.size();
		}
		OutputAfterActivation = ActivationFunction(OutputLayer.myLayer[i].GetInput());
		OutputLayer.myLayer[i].ChangeOutput(OutputAfterActivation);

	}
}
void Net::ChangeOutputsInInputLayer(const std::vector<double> NewInputs)
{
	const int BIAS_NEURON = 1;
	for (unsigned int i = 0; i < InputLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		InputLayer.myLayer[i].ChangeOutput(NewInputs[i]);
	}
}
void Net::BackPropFirstHiddenLayer(const double LearningRate)
{
	const int BIAS_NEURON = 1;
	double Epsilon = 0;
	double Derivative = 0;
	double newDeltaWeight = 0;
	int RightConnectionsCounter = 0;
	int LeftConnectionsCounter = 0;
	for (unsigned int i = 0; i < FirstHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		Epsilon = 0;
		LeftConnectionsCounter = i;
		for (unsigned int j = 0; j < SecondHiddenLayer.myLayer.size() - BIAS_NEURON; j++)
		{
			Epsilon = Epsilon + (SecondConnectionVector[RightConnectionsCounter].GetWeight() * SecondConnectionVector[RightConnectionsCounter].GetDeltaWeight());
			RightConnectionsCounter++;
		}
		Derivative = CalculateDerivative(FirstHiddenLayer.myLayer[i].GetOutput());
		for (unsigned int k = 0; k < InputLayer.myLayer.size(); k++)
		{
			newDeltaWeight = (2 * LearningRate * Derivative * Epsilon * InputLayer.myLayer[k].GetOutput()) + FirstConnectionVector[LeftConnectionsCounter].GetDeltaWeight();
			FirstConnectionVector[LeftConnectionsCounter].ChangeDeltaWeight(newDeltaWeight);
			LeftConnectionsCounter = LeftConnectionsCounter + FirstHiddenLayer.myLayer.size() - BIAS_NEURON;
		}
	}
}
void Net::BackPropSecondHiddenLayer(const double LearningRate)
{
	const int BIAS_NEURON = 1;
	double Epsilon = 0;
	double Derivative = 0;
	double newDeltaWeight = 0;
	int RightConnectionsCounter = 0;
	int LeftConnectionsCounter = 0;
	for (unsigned int i = 0; i < SecondHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		Epsilon = 0;
		LeftConnectionsCounter = i;
		for (unsigned int j = 0; j < OutputLayer.myLayer.size(); j++)
		{
			Epsilon = Epsilon + (ThirdConnectionVector[RightConnectionsCounter].GetWeight() * ThirdConnectionVector[RightConnectionsCounter].GetDeltaWeight());
			RightConnectionsCounter++;
		}
		Derivative = CalculateDerivative(SecondHiddenLayer.myLayer[i].GetOutput());
		for (unsigned int k = 0; k < FirstHiddenLayer.myLayer.size(); k++)
		{
			newDeltaWeight = (2 * LearningRate * Derivative * Epsilon * FirstHiddenLayer.myLayer[k].GetOutput()) + SecondConnectionVector[LeftConnectionsCounter].GetDeltaWeight();
			SecondConnectionVector[LeftConnectionsCounter].ChangeDeltaWeight(newDeltaWeight);
			LeftConnectionsCounter = LeftConnectionsCounter + SecondHiddenLayer.myLayer.size() - BIAS_NEURON;
		}
	}
}
void Net::BackPropOutputLayer(const double LearningRate, std::vector<double> DesiredOutputs)
{
	double newDeltaWeight = 0;
	int LeftConnectionsCounter = 0;
	for (unsigned int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		LeftConnectionsCounter = i;
		for (unsigned int j = 0; j < SecondHiddenLayer.myLayer.size(); j++)
		{
			newDeltaWeight = (2 * LearningRate * (DesiredOutputs[i] - OutputLayer.myLayer[i].GetOutput()) * CalculateDerivative(OutputLayer.myLayer[i].GetOutput())  * SecondHiddenLayer.myLayer[j].GetOutput()) + ThirdConnectionVector[LeftConnectionsCounter].GetDeltaWeight();
			ThirdConnectionVector[LeftConnectionsCounter].ChangeDeltaWeight(newDeltaWeight);
			LeftConnectionsCounter = LeftConnectionsCounter + OutputLayer.myLayer.size();
		}
	}
}
void Net::UpdateWeightsFirstHiddenLayer()
{
	const int BIAS_NEURON = 1;
	double newWeight = 0;
	int ConnectionsCounter = 0;
	for (unsigned i = 0; i < FirstHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		ConnectionsCounter = i;
		for (unsigned int j = 0; j < InputLayer.myLayer.size(); j++)
		{
			newWeight = FirstConnectionVector[ConnectionsCounter].GetWeight() + FirstConnectionVector[ConnectionsCounter].GetDeltaWeight();
			FirstConnectionVector[ConnectionsCounter].ChangeWeight(newWeight);
			ConnectionsCounter = ConnectionsCounter + FirstHiddenLayer.myLayer.size() - BIAS_NEURON;
		}
	}
}
void Net::UpdateWeightsSecondHiddenLayer()
{
	const int BIAS_NEURON = 1;
	double newWeight = 0;
	int ConnectionsCounter = 0;
	for (unsigned i = 0; i < SecondHiddenLayer.myLayer.size() - BIAS_NEURON; i++)
	{
		ConnectionsCounter = i;
		for (unsigned int j = 0; j < FirstHiddenLayer.myLayer.size(); j++)
		{
			newWeight = SecondConnectionVector[ConnectionsCounter].GetWeight() + SecondConnectionVector[ConnectionsCounter].GetDeltaWeight();
			SecondConnectionVector[ConnectionsCounter].ChangeWeight(newWeight);
			ConnectionsCounter = ConnectionsCounter + SecondHiddenLayer.myLayer.size() - BIAS_NEURON;
		}
	}
}
void Net::UpdateWeightsOutputLayer()
{
	double newWeight = 0;
	int ThirdConnectionsVectorCounter = 0;
	for (unsigned i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		ThirdConnectionsVectorCounter = i;
		for (unsigned int j = 0; j < SecondHiddenLayer.myLayer.size(); j++)
		{
			newWeight = ThirdConnectionVector[ThirdConnectionsVectorCounter].GetWeight() + ThirdConnectionVector[ThirdConnectionsVectorCounter].GetDeltaWeight();
			ThirdConnectionVector[ThirdConnectionsVectorCounter].ChangeWeight(newWeight);
			ThirdConnectionsVectorCounter = ThirdConnectionsVectorCounter + OutputLayer.myLayer.size();
		}
	}
}
void Net::ResetSquaredError()
{
	for (unsigned int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		OutputLayer.myLayer[i].ChangeSquaredError(0);
	}
}
double Net::SumUpSquaredErrors()
{
	double SumOfErrors = 0;
	for (unsigned int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		SumOfErrors = SumOfErrors + OutputLayer.myLayer[i].GetSquaredError();
	}
	return SumOfErrors;
}
void Net::CalculateSquaredErrorOnOutputLayer(std::vector<double> DesignedOutputs)
{
	double Error = 0;
	for (unsigned int i = 0; i < OutputLayer.myLayer.size(); i++)
	{
		Error = ((pow(DesignedOutputs[i] - OutputLayer.myLayer[i].GetOutput(), 2)) / 2) + OutputLayer.myLayer[i].GetSquaredError();
		OutputLayer.myLayer[i].ChangeSquaredError(Error);
	}
}
void Net::ResetInputs(Layer &CurrentLayer)
{
	{
		for (unsigned int i = 0; i < CurrentLayer.myLayer.size(); i++)
		{
			CurrentLayer.myLayer[i].ChangeInput(0);
		}
	}
}
void Net::ResetDeltaWeight(std::vector<Connection> &Connections)
{
	for (unsigned int i = 0; i < Connections.size(); i++)
	{
		Connections[i].ChangeDeltaWeight(0);
	}
}

void Net::Learn(const std::vector<double> Inputs, std::vector<double> OutputArray, const double LearningRate)
{
	this->ChangeOutputsInInputLayer(Inputs);
	this->ProcessDataForwardToFirstHiddenLayer();
	this->ProcessDataForwardToSecondHiddenLayer();
	this->ProcessDataForwardToOutputLayer();
	this->CalculateSquaredErrorOnOutputLayer(OutputArray);
	this->BackPropOutputLayer(LearningRate, OutputArray);
	this->BackPropSecondHiddenLayer(LearningRate);
	this->BackPropFirstHiddenLayer(LearningRate);
	ResetInputs(this->FirstHiddenLayer);
	ResetInputs(this->SecondHiddenLayer);
	ResetInputs(this->OutputLayer);
}
void Net::UpdateWeights()
{
	this->UpdateWeightsFirstHiddenLayer();
	this->UpdateWeightsSecondHiddenLayer();
	this->UpdateWeightsOutputLayer();
	this->ResetSquaredError();
	this->ResetDeltaWeight(this->FirstConnectionVector);
	this->ResetDeltaWeight(this->SecondConnectionVector);
	this->ResetDeltaWeight(this->ThirdConnectionVector);
}
void Net::PrintWeightsToFile(const char* FirstVectorFilePath, const char* SecondVectorFilePath, const char* ThirdVectorFilePath)
{
	std::ofstream myFile;
	myFile.open(FirstVectorFilePath, ios::trunc);
	for (unsigned int i = 0; i < this->FirstConnectionVector.size(); i++)
	{
		myFile << this->FirstConnectionVector[i].GetWeight() << std::endl;
	}
	myFile.close();
	myFile.open(SecondVectorFilePath, ios::trunc);
	for (unsigned int i = 0; i < this->SecondConnectionVector.size(); i++)
	{
		myFile << this->SecondConnectionVector[i].GetWeight() << std::endl;
	}
	myFile.close();
	myFile.open(ThirdVectorFilePath, ios::trunc);
	for (unsigned int i = 0; i < this->ThirdConnectionVector.size(); i++)
	{
		myFile << this->ThirdConnectionVector[i].GetWeight() << std::endl;
	}
}
void Net::LoadInWeights(const char* FirstVectorFilePath, const char* SecondVectorFilePath, const char* ThirdVectorFilePath)
{
	string line;
	ifstream myFile;
	double ReadValue = 0;
	myFile.open(FirstVectorFilePath);
	for (unsigned int i = 0; i < this->FirstConnectionVector.size(); i++)
	{
		getline(myFile, line);
		ReadValue = stod(line);
		this->FirstConnectionVector[i].ChangeWeight(ReadValue);
	}
	myFile.close();
	myFile.open(SecondVectorFilePath);
	for (unsigned int i = 0; i < this->SecondConnectionVector.size(); i++)
	{
		getline(myFile, line);
		ReadValue = stod(line);
		this->SecondConnectionVector[i].ChangeWeight(ReadValue);
	}
	myFile.close();
	myFile.open(ThirdVectorFilePath);
	for (unsigned int i = 0; i < this->ThirdConnectionVector.size(); i++)
	{
		getline(myFile, line);
		ReadValue = stod(line);
		this->ThirdConnectionVector[i].ChangeWeight(ReadValue);
	}
}
void Net::CheckPrecision(vector<vector<double>> trainingSet, vector<vector<double>> DesiredOutputs)
{
	struct Answers
	{
		double RightAnswers = 0;
		const double AllAnswers = 50;
		int LetterIndex = 0;
	};
	double max = 1;
	double min = 1;
	unsigned int i = 0;
	unsigned int y = 0;
	Answers myAnswers;
		myAnswers.RightAnswers = 0;
		while (y < 23)
		{
			myAnswers.RightAnswers = 0;
			i = y;
			while(i < trainingSet.size())
			{
				this->Learn(trainingSet[i], DesiredOutputs[0], 0.1);
				for (unsigned int j = 0; j < 23; j++)
				{
					double Temporary = 0;
					Temporary = max - OutputLayer.myLayer[j].GetOutput();
					if (Temporary < min)
					{
						min = Temporary;
						myAnswers.LetterIndex = j;
					}
				}
				if (myAnswers.LetterIndex == y)
					myAnswers.RightAnswers++;
				i = i + 23;
				min = 1;
			}
			cout << endl << myAnswers.LetterIndex << "  " << myAnswers.RightAnswers / myAnswers.AllAnswers * 100 << "%" << endl;
			y++;
		}
}