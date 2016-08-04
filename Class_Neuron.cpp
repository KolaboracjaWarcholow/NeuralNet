#include "stdafx.h"
#include "Class_Neuron.h"
using namespace std;

Neuron::Neuron() 
{
	m_Input = 0;
	m_Output = 0;
	m_SquaredError = 0;
};
Neuron::Neuron(const int NeuronsInNextLayer, vector<Connection> &ConnectionsVector)
{
	m_Input = 0;
	m_Output = 0;
	m_SquaredError = 0;
	int min = -5;
	int max = 5;
	double RandomWeight;
	for ( int i = 0; i < NeuronsInNextLayer; i++)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(min, max);
		RandomWeight = uni(rng);
		RandomWeight = RandomWeight / 10;
		Connection myConnection(RandomWeight);
		ConnectionsVector.push_back(myConnection);
	}
}

void Neuron::SumUpOutputs(double newInput)
{
	m_Input = m_Input + newInput;
}
double Neuron::GetOutput()
{
	return m_Output;
}
void Neuron::ChangeOutput(double newOutput)
{
	m_Output = newOutput;
}
double Neuron::GetInput()
{
	return m_Input;
}
void Neuron::ChangeSquaredError(double newError)
{
	m_SquaredError = newError;
}
double Neuron::GetSquaredError()
{
	return m_SquaredError;
}
void Neuron::ChangeInput(double newInput)
{
	m_Input = newInput;
}
Neuron::~Neuron() {}