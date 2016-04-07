//
// Created by Szymek on 06.04.2016.
//

#include "BinaryArray.h"
#include "BitMap.h"

BinaryArray::BinaryArray(){
	m_bmpInBinary = "Error";
}

BinaryArray::BinaryArray(std::string bmpArray){
	m_bmpInBinary = bmpArray;
}

void BinaryArray::Print(){
	std::cout<<"elo";
	//for(int i = 0; i <= BitMap::m_heightInPixels; i ++){
	//	std::cout << std::endl;
	//	for(int j = 0; j <= BitMap::m_widthInPixels; j ++)
	//		std::cout << m_bmpInBinary[j + i];
	}
//}