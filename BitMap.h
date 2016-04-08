//
// Created by Szymek on 06.04.2016.
//

#ifndef NEURALNET_BITMAP_H
#define NEURALNET_BITMAP_H

#include<iostream>
#include<fstream>
#include <string>

class BitMap{
private:
	std::fstream m_bitmapFile;
	const char *m_FilePath;
	std::string m_bitmapInArray;

public:
	BitMap();

	BitMap(const char *pathToFile);

	void BmpToBinaryArrayConversion();

	void PrintBitmapInBinaryArray();

	void WhenPixelIsBlackInsert1ToArray(char *pixelTab);

	void WhenPixelIsWhiteInsert0ToArray(char *pixelTab);

	void FillingArrayWith0sAnd1s();
};


#endif //NEUrALNET_BITMAP_H
