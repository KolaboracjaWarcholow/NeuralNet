#include <iostream>
#include "BitMap.h"

using namespace std;

int main(){
	const char *path = "/Users/apple/ClionProjects/NeuralNet/x.bmp";
	BitMap newBmp = BitMap(path);
	newBmp.BmpToBinaryArrayConversion();
	newBmp.PrintBitmapInBinaryArray();
	std::cout << std::endl;
	newBmp.PrintingArrayWithOtherValues(0.9,1);
	return 0;
}