#include <iostream>
#include "BitMap.h"


using namespace std;

int main(){
	const char *path = "/Users/apple/Documents/b.bmp";
	BitMap newBmp("/Users/apple/Documents/b.bmp");
	newBmp.ProcessingBitmapIntoArrayForNeuralNet(0,1);
	return 0;
}