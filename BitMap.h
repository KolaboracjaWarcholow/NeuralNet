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
	const char* m_FilePath;
	int m_numberOfHeaderBytes;
	int m_widthInPixels;
	int m_heightInPixels;
public:
	BitMap();
	BitMap(const char* pathToFile);
	void BmpToBinaryArrayConversion();
};


#endif //NEUrALNET_BITMAP_H
