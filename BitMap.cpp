//
// Created by Szymek on 06.04.2016.
//

#include "BitMap.h"

BitMap::BitMap(){
	m_FilePath = NULL;
	m_numberOfHeaderBytes = 0;
	m_widthInPixels = 0;
	m_heightInPixels = 0;
}

BitMap::BitMap(const char* pathToFile){
	m_FilePath = pathToFile;
	m_bitmapFile.open(pathToFile,std::ios::binary);
	m_widthInPixels = 16;
	m_heightInPixels = 16;
}

void BitMap::BmpToBinaryArrayConversion()
{
	char binaryArray[8000];
	if(m_bitmapFile.good())
	{
		//do{
			m_bitmapFile.read(binaryArray,8000);
		//}while(m_bitmapFile.eof());
	}
	std::cout << binaryArray;
}