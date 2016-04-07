#include <iostream>
#include <fstream>

#include "BitMap.h"
#include "BinaryArray.h"

using namespace std;

int main(){
	const char *path ="/Users/apple/ClionProjects/NeuralNet/a.bmp";
	BitMap newBmp = BitMap(path);
	newBmp.BmpToBinaryArrayConversion();
	cout << "eloeleo";
	cout << sizeof(BITMAPFILEHEADER)<<endl;
	cout << sizeof(BITMAPINFOHEADER)<<endl;



	return 0;
}