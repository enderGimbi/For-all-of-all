#include <iostream>


#pragma pack(push, 1)
struct BMPHeader {				// Total: 54 bytes
	uint16_t type;				// Magic identifier: 0x4d42
	uint32_t size;				// File size in bytes
	uint32_t reserved;			// Not used
	uint32_t offset;			// Offset to image data in bytes from beginning of file (54 bytes)

	uint32_t dib_header_size;	// DIB Header size in bytes (40 bytes)
	int32_t width_px;			// Width of the image
	int32_t height_px;			// Height of image
	uint16_t num_planes;		// Number of color planes
	uint16_t bits_per_pixel;	// Bits per pixel
	uint32_t compression;		// Compression type
	uint32_t image_size_bytes;	// Image size in bytes

	int32_t x_resolution_ppm;	// Pixels per meter
	int32_t y_resolution_ppm;	// Pixels per meter
	uint32_t num_colors;		// Number of colors
	uint32_t important_colors;	// Important colors
};

struct COLOR {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};
#pragma pack(pop)


int calcGap(int32_t with, uint16_t bitsPerPixel);

void modifyPixels(COLOR**& colorArray, BMPHeader inf);

void writePixels(FILE*& file, COLOR** colorArray, BMPHeader inf);

void fillArrFromBMP(FILE* file, BMPHeader inf, COLOR** &arr);

void delArr(COLOR**& arr, int size);