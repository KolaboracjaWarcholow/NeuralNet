#include <iostream>
#include <fstream>

#include "BitMap.h"
#include "BinaryArray.h"
using namespace std;

int main(){
	const char *path ="/Users/apple/ClionProjects/NeuralNet/example.bmp";
	BitMap newBmp = BitMap(path);
	newBmp.BmpToBinaryArrayConversion();
	cout << "eloeleo";


	return 0;
}