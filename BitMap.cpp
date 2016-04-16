//
// Created by Szymek on 06.04.2016.
//

#include "BitMap.h"

static const int bitsOffSet = 54; //Number of bits from beginning of the file to the beginning of the image.
static const int bitsInPixel = 3;
static const char blackColor = '\0';
static const char whiteColor = '\xff';

BitMap::BitMap(){
	m_FilePath = NULL;
}

BitMap::BitMap(const char *pathToFile){
	m_FilePath = pathToFile;
	m_bitmapFile.open(pathToFile, std::ios::in | std::ios::binary);
	m_bitmapArray = new double;
}


double *BitMap::ProcessingBitmapIntoArrayForNeuralNet(double valueForWhite, double valueForBlack){
	m_bitmapFile.seekg(bitsOffSet, std::ios::beg);
	int arrayNumberControl = 0;
	char onePixel[bitsInPixel];
	while(!m_bitmapFile.eof()){
		m_bitmapFile.read(onePixel, bitsInPixel);
		BlackPixelToNumber(onePixel, valueForBlack, arrayNumberControl);
		WhitePixelToNumber(onePixel, valueForWhite, arrayNumberControl);
		//m_bitmapFile.seekg(1, std::ios::cur);
		arrayNumberControl++;
	}
	RevertingBitmapArray(arrayNumberControl, 16, 16);
	for(int i = 0; i <= 256; i++)
		std::cout << m_bitmapArray[i];
	return m_bitmapArray;
}

void BitMap::BlackPixelToNumber(char onePixel[bitsInPixel], double valueForBlack, int arrayNumberControl){
	if((onePixel[0] == blackColor) && (onePixel[1] == blackColor) && (onePixel[2] == blackColor))
		m_bitmapArray[arrayNumberControl] = valueForBlack;
}

void BitMap::WhitePixelToNumber(char onePixel[bitsInPixel], double valueForWhite, int arrayNumberControl){
	if((onePixel[0] == whiteColor) && (onePixel[1] == whiteColor) && (onePixel[2] == whiteColor))
		m_bitmapArray[arrayNumberControl] = valueForWhite;
}

void BitMap::RevertingBitmapArray(int arrayNumberControl, int bitmapWidth, int bitmapHeight){
	double *temp = new double;
	int row = bitmapHeight - 1;
	int tempArrayNumberControl = 0;
	do{
		for(arrayNumberControl = 0; arrayNumberControl < 16; arrayNumberControl++){
			temp[tempArrayNumberControl] = m_bitmapArray[((row * bitmapWidth) + arrayNumberControl)];
		}
		row++;
	} while(row != 0);
	m_bitmapArray = temp;
	delete temp;
}