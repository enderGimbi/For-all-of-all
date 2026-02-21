#include"BMPex.h"


void fillArrFromBMP(FILE* file,BMPHeader inf,COLOR** &arr) {
	for (int i = 0; i < inf.height_px; i++) {
		arr[i] = new COLOR[inf.width_px];
		fread(arr[i], sizeof(COLOR),inf.width_px,file);
		fseek(file, calcGap(inf.width_px, inf.bits_per_pixel),SEEK_CUR);
	}
}

int calcGap(int32_t with, uint16_t bitsPerPixel) {
	int addBits = ((bitsPerPixel * with+31) / 32) * 4, gap = with*bitsPerPixel/8;
	return addBits-gap;
}

void modifyPixels(COLOR** &colorArray, BMPHeader inf){
	COLOR start=colorArray[0][0], end=colorArray[inf.height_px-1][inf.width_px-1];
	if (inf.width_px!=1) {
		for (int y = 0; y < inf.height_px; y++) {
			for (int x = 0; x < inf.width_px; x++) {
				float t = (float)x / (float)(inf.width_px - 1);
				colorArray[y][x].blue = (start.blue * (1.0f - t) + end.blue * t);
				colorArray[y][x].green = (start.green * (1.0f - t) + end.green * t);
				colorArray[y][x].red = (start.red * (1.0f - t) + end.red * t);
			}
		}
	}
}

void writePixels(FILE* &file, COLOR** colorArray, BMPHeader inf)
{
	uint8_t end = 0x00;
	int gap = calcGap(inf.width_px, inf.bits_per_pixel);
	fseek(file, inf.offset, SEEK_SET);
	for (int i = 0; i < inf.height_px; i++){
		for (int j = 0; j < inf.width_px; j++) {
			fwrite(&colorArray[i][j],sizeof(COLOR),1,file);
		}
		fwrite(&end, 1, gap, file);
	}
}

void delArr(COLOR** &arr,int size) {
	for (int i = 0; i < size;i++) {
		delete[] arr[i];
	}
	delete[] arr;
}