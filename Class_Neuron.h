#ifndef CLASS_NEURON_H
#define CLASS_NEURON_H
#include <iostream>
#include <vector>
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
	Neuron(const int, std::vector<Connection>&, double[]);
	void ChangeInput(double newInput);
	double GetOutput();
	~Neuron();
};
#endif CLASS_NEURON_H