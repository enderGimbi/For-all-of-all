#include "BMPex.h"
#include<clocale>

int main() {
	setlocale(LC_ALL, "rus");

	FILE* mPic; fopen_s(&mPic,"square13.bmp","r+b");
	BMPHeader inf;

	if (!mPic) {
		printf("Ошибка открытия файла!");
		return -1;
	}
	if (!fread(&inf, sizeof(BMPHeader), 1, mPic)) {
		printf("Ошибка чтения данных о файле!");
		return -2;
	}

	COLOR** colorArray = new COLOR* [inf.height_px];
	fillArrFromBMP(mPic, inf, colorArray);

	modifyPixels(colorArray, inf);
	writePixels(mPic, colorArray, inf);

	delArr(colorArray,inf.height_px);
	fclose(mPic);
}

