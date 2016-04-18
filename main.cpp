#include <iostream>
#include "BitMap.h"


using namespace std;

int main(){
	const char *path = "/Users/apple/Documents/b.bmp";
	BitMap newBmp = BitMap("/Users/apple/Documents/b.bmp");
	//newBmp.BmpToBinaryArrayConversion();
	//newBmp.PrintBitmapInBinaryArray();
	//std::cout << std::endl;
	newBmp.ProcessingBitmapIntoArrayForNeuralNet(0,1);

	return 0;
}