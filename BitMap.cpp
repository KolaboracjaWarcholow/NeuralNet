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
}

void BitMap::BmpToBinaryArrayConversion(){
	if(m_bitmapFile.good()){
		m_bitmapFile.seekg(bitsOffSet, std::ios::beg);
		BitMap::FillingArrayWith0sAnd1s();

	}

}

void BitMap::PrintBitmapInBinaryArray(){
	int stringNoControl = 0;
	for(int loopControl1 = 0; loopControl1 <= 15; loopControl1++){
		for(int loopControl2 = 0; loopControl2 <= 15; loopControl2++){
			std::cout << m_bitmapInArray[stringNoControl];
			stringNoControl++;
		}
		std::cout << std::endl;
	}
}

void BitMap::WhenPixelIsBlackInsert1ToArray(char *pixelTab){
	if((pixelTab[0] == blackColor) && (pixelTab[1] == blackColor) && (pixelTab[2] == blackColor))
		m_bitmapInArray = m_bitmapInArray + "1";
}

void BitMap::WhenPixelIsWhiteInsert0ToArray(char *pixelTab){
	if((pixelTab[0] == whiteColor) && (pixelTab[1] == whiteColor) && (pixelTab[2] == whiteColor))
		m_bitmapInArray = m_bitmapInArray + "0";
}

void BitMap::FillingArrayWith0sAnd1s(){
	char onePixel[bitsInPixel];
	while(!m_bitmapFile.eof()){
		m_bitmapFile.read(onePixel, bitsInPixel);
		BitMap::WhenPixelIsBlackInsert1ToArray(onePixel);
		BitMap::WhenPixelIsWhiteInsert0ToArray(onePixel);
		m_bitmapFile.seekg(1, std::ios::cur);
	}
}


void BitMap::PrintingArrayWithOtherValues(double valueForWhite, double valueForBlack){
	int stringNoControl = 0;
	for(int loopControl1 = 0; loopControl1 <= 15; loopControl1++){
		for(int loopControl2 = 0; loopControl2 <= 15; loopControl2++){
			if(m_bitmapInArray[stringNoControl] == '1')
				std::cout << valueForBlack << " ";
			else
				std::cout << valueForWhite << " ";
			stringNoControl++;
		}
		std::cout << std::endl;
	}
}
