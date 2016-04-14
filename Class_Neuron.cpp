#include "stdafx.h"
#include "Class_Neuron.h"
#include "Struct_Topology.h"
#include <iostream>
#include <vector>
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
	for ( int i = 0; i < NeuronsInNextLayer; i++)
	{
		Connection myConnection(5);
		ConnectionsVector.push_back(myConnection);
	}
}
Neuron::Neuron(const int NeuronsInNextLayer, vector<Connection> &ConnectionsVector, double InputArray[])
{
	m_Output = 0;
	m_Error = 0;
	for ( int i = 0; i < NeuronsInNextLayer; i++)
	{
		m_Input = InputArray[0];
		Connection myConnection(5);
		ConnectionsVector.push_back(myConnection);
	}
}
void Neuron::ChangeInput(double newInput)
{
	m_Input = newInput;
}
double Neuron::GetOutput()
{
	return m_Output;
}

Neuron::~Neuron() {}