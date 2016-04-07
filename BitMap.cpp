//
// Created by Szymek on 06.04.2016.
//

#include "BitMap.h"
#include "BMPInfoStructures.h"

BitMap::BitMap(){
	m_FilePath = NULL;
}

BitMap::BitMap(const char *pathToFile){
	m_FilePath = pathToFile;
	m_bitmapFile.open(pathToFile, std::ios::in | std::ios::binary);

	m_bitmapFile.seekg(0, std::ios::beg);

	char *tempFileHeader = new char[sizeof(BITMAPFILEHEADER)];
	m_bitmapFile.read(tempFileHeader, 14);
	m_fileHeader = (BITMAPFILEHEADER *)(tempFileHeader);
	m_bitmapFile.seekg(39, std::ios::beg);
	char *tempInfoHeader = new char[sizeof(BITMAPINFOHEADER)];
	m_bitmapFile.read(tempInfoHeader, 40);
	m_infoHeader = (BITMAPINFOHEADER *)(tempInfoHeader);

}

void BitMap::BmpToBinaryArrayConversion(){
	if(m_bitmapFile.good()){
		m_bitmapFile.seekg(54, std::ios::beg);
		std::string bitmapInArray;
		char onePixel[3];

		while(!m_bitmapFile.eof()){
			m_bitmapFile.read(onePixel, 3);
			if((onePixel[0] == '\0') && (onePixel[1] == '\0') && (onePixel[2] == '\0'))
				bitmapInArray = bitmapInArray + "1";
			if((onePixel[0] == '\xff') && (onePixel[1] == '\xff') && (onePixel[2] == '\xff'))
				bitmapInArray = bitmapInArray + "0";
			m_bitmapFile.seekg(1, std::ios::cur);
		}
		int stringNoControl = 0;
		for(int loopControl1 = 0; loopControl1 <= 15; loopControl1++){
			for(int loopControl2 = 0; loopControl2 <= 15; loopControl2++){
				std::cout << bitmapInArray[stringNoControl];
				stringNoControl++;
			}
			std::cout<<std::endl;
		}
	}
}