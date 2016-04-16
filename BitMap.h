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
	double *m_bitmapArray;

public:
	BitMap();

	BitMap(const char *pathToFile);

	double *ProcessingBitmapIntoArrayForNeuralNet(double valueForWhite, double valueForBlack);

	void BlackPixelToNumber(char *onePixel, double valueForBlack, int arrayNumberControl);

	void WhitePixelToNumber(char *onePixel, double valueForWhite, int arrayNumberControl);

	void RevertingBitmapArray(int arrayNumberControl, int bitmapWidth, int bitmapHeight);
};


#endif //NEUrALNET_BITMAP_H
