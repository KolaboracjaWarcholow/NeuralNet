#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Class_Neuron.h"
#include "Functions.h"
#include "Class_Connection.h"
#include "Class_Layer.h"
#include "Struct_Topology.h"
using namespace std;




int main()

{
	Topology myTopology;
	vector<Connection> LastAndThird;
	vector<Connection> ThirdAndSecond;
	vector<Connection> SecondAndFirst;
	Layer OutputLayer(myTopology.NeuronsInOutputLayer);
	Layer SecondHiddenLayer(myTopology.NeuronsInOutputLayer, myTopology.NeuronsInSecondHiddenLayer, LastAndThird);
	Layer FirstHiddenLayer(myTopology.NeuronsInSecondHiddenLayer, myTopology.NeuronsInFirstHiddenLayer, ThirdAndSecond);
	Layer InputLayer(myTopology.NeuronsInFirstHiddenLayer, myTopology.NeuronsInInputLayer, SecondAndFirst);
	cout << SecondAndFirst.size() << endl;
	getchar();
    return 0;
}

