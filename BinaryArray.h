//
// Created by Szymek on 06.04.2016.
//

#ifndef NEURALNET_BINARYARRAY_H
#define NEURALNET_BINARYARRAY_H

#include<iostream>

class BinaryArray{
private:
	std::string m_bmpInBinary;
public:
	BinaryArray();

	BinaryArray(std::string bmpArray);

	void Print();


};


#endif //NEURALNET_BINARYARRAY_H
