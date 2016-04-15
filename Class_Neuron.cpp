#include "stdafx.h"
#include "Class_Neuron.h"
using namespace std;

Neuron::Neuron() 
{
	m_Input = 0;
	m_Output = 0;
	m_Error = 0;
};
Neuron::Neuron(double inInput)
{
	m_Input = inInput;
	m_Output = 0;
	m_Error = 0;
}

Neuron::Neuron(const int NeuronsInNextLayer, vector<Connection> &ConnectionsVector)
{
	m_Input = 0;
	m_Output = 0;
	m_Error = 0;
	double RandomWeight;
	srand((unsigned)time(0));
	for ( int i = 0; i < NeuronsInNextLayer; i++)
	{
		RandomWeight = rand() % 10;
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

void Neuron::ChangeError(double newError)
{
	m_Error = newError;
}

Neuron::~Neuron() {}