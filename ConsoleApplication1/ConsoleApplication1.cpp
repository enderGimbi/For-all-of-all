//
//#include<iostream>
//#include<clocale>
//
//void execArr2D(int** arr2D, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			printf("%d ", arr2D[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void execArr(int* arr, int size) {
//	for (int i = 0; i < size; i++) printf("%d ", arr[i]); printf("\n"); printf("\n");
//}
//
//void errProc(FILE* &f,int** &arr,int rows) {
//	fclose(f);
//	for (int i = 0; i < rows; i++)delete[] arr[i];
//	delete[] arr;
//}
//
//int** arrFromFile(char* fileName,int &rows,int &cols,int** &arr2D) {
//	FILE* fileFromLMS;
//	fopen_s(&fileFromLMS,fileName,"r");
//	if (fileFromLMS) {
//		fscanf_s(fileFromLMS, "%d %d", &rows,&cols);
//		if (rows < 1 || cols < 1) {
//			perror("Неверные размеры для матрицы!");
//			errProc(fileFromLMS, arr2D, rows);
//			exit(EXIT_FAILURE);
//		}
//		arr2D = new int* [rows];
//		for (int i = 0; i < rows; i++) arr2D[i] = new int[cols];
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < cols; j++) {
//				if (!fscanf_s(fileFromLMS, "%d", &arr2D[i][j])) {
//					perror("В файле неверный формат одного из элементов для матрицы!");
//					errProc(fileFromLMS, arr2D, rows);
//					exit(EXIT_FAILURE);
//				}
//				if (feof(fileFromLMS)&&!(j==cols-1)) {
//					perror("В файле не хватает элементов для матрицы!");
//					errProc(fileFromLMS, arr2D, rows);
//					exit(EXIT_FAILURE);
//				}
//			}
//		}
//		if (!feof(fileFromLMS)) {
//			perror("В файле элементов больше нужного!");
//			errProc(fileFromLMS, arr2D, rows);
//			exit(EXIT_FAILURE);
//		}
//		execArr2D(arr2D, rows,cols);
//		fclose (fileFromLMS);
//		return arr2D;
//	}
//	else {
//		perror("Файл не удалось открыть!");
//		errProc(fileFromLMS, arr2D, rows);
//		exit(EXIT_FAILURE);
//	}
//}
//
//int maxOfCol(int** arr, int rows, int currentCol) {
//	int max = arr[0][currentCol];
//	for (int i = 0; i < rows;i++) {
//		if (arr[i][currentCol] > max) max = arr[i][currentCol];
//	}
//	return max;
//}
//
//int minOfRow(int** arr, int cols, int currentRow) {
//	int min = arr[currentRow][0];
//	for (int i = 0; i < cols; i++) {
//		if (arr[currentRow][i] < min) min = arr[currentRow][i];
//	}
//	return min;
//}
//
//int* maxOfCols(int** arr, int rows, int cols,int* &maxOfCols) {
//	for (int i = 0; i < cols; i++) {
//		maxOfCols[i] = maxOfCol(arr, rows, i);
//	}
//	return maxOfCols;
//}
//
//int* minOfRows(int** arr, int rows, int cols,int* &minOfRows) {
//	for (int i = 0; i < rows; i++) {
//		minOfRows[i] = minOfRow(arr, cols, i);
//	}
//	return minOfRows;
//}
//
//void srchSaddlePoints(int** arr,int rows,int cols) {
//	FILE* res; fopen_s(&res, "result.txt", "w");
//	if (res) {
//		int* maxOfColsMas = new int[cols]; int* minOfRowsMas = new int[rows];
//		maxOfCols(arr, rows, cols,maxOfColsMas); execArr(maxOfColsMas, cols);
//		minOfRows(arr, rows, cols,minOfRowsMas); execArr(minOfRowsMas, rows);
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < cols; j++) {
//				if (arr[i][j] == minOfRowsMas[i] && arr[i][j] == maxOfColsMas[j]) fprintf(res,"Элемент (%d,%d) со значением %d является седловой точкой\n",i+1,j+1,arr[i][j]);
//			}
//		}
//		printf("Результат записан в файл result.txt\n");
//		delete[] maxOfColsMas, minOfRowsMas; fclose(res);
//	}
//	else {
//		perror("Ошибка при создании файла результата!");
//		errProc(res, arr, rows);
//		exit(EXIT_FAILURE);
//	}
//}
//
//void delArr2D(int** &arr,int rows) {
//	for (int i = 0; i < rows; i++) delete[] arr[i];
//}
//
//int main() {
//	setlocale(LC_ALL,"russian");
//	char* fileName = new char[12]; fileName[11] = 0; int rows, cols;
//	strcpy_s(fileName, 12, "Array2D.txt");
//	int** Array2D;
//	arrFromFile(fileName, rows, cols,Array2D);
//	srchSaddlePoints(Array2D, rows, cols);
//	delArr2D(Array2D, rows);
//	delete[] fileName,Array2D;
//}

