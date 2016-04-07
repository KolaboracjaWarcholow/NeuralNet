//
// Created by Szymek on 07.04.2016.
//

#ifndef NEURALNET_BMPINFOSTRUCTURES_H
#define NEURALNET_BMPINFOSTRUCTURES_H


struct BITMAPFILEHEADER{
	wchar_t bfType;
	int bfSize;
	short bfReserved1;
	short bfReserved2;
	unsigned int bfOffBits;
};

struct BITMAPINFOHEADER{
	int biSize;
	int biWidth;
	int biHeight;
	short biPlanes;
	short biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;
};



#endif //NEURALNET_BMPINFOSTRUCTURES_H
