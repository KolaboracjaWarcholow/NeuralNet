#ifndef CLASS_NEURON_H
#define CLASS_NEURON_H
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include "Struct_Topology.h"
#include "Class_Connection.h"

class Neuron
{
private:
	double m_Input;
	double m_Output;
	double m_Error;
public:
	Neuron();
	Neuron(double);
	Neuron(const int, std::vector<Connection>&);
	void SumUpOutputs(double);
	void ChangeOutput(double);
	double GetOutput();
	double GetInput();
	void ChangeError(double);
	~Neuron();
};
#endif CLASS_NEURON_H