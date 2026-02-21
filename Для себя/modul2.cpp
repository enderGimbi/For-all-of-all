#include<iostream>
#include<clocale>

void execArr2D(int** arr2D, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr2D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void errProc(FILE* &f,int** &arr,int rows) {
	fclose(f);
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}

int** arrFromFile(char* fileName, int& rows, int& cols, int**& arr2D) {
	FILE* fileFromLMS;
	fopen_s(&fileFromLMS, fileName, "rb");
	if (fileFromLMS) {
		fread(&rows,sizeof(rows), 1, fileFromLMS);
		fread(&cols,sizeof(cols),1, fileFromLMS);
		if (rows < 1 || cols < 1) {
			perror("Неверные размеры для матрицы!");
			errProc(fileFromLMS,arr2D,rows);
			exit(EXIT_FAILURE);
		}
		arr2D = new int* [rows];
		for (int i = 0; i < rows; i++) arr2D[i] = new int[cols];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (!fread(&arr2D[i][j],sizeof(int), 1,fileFromLMS)) {
					perror("В файле неверный формат одного из элементов для матрицы!");
					errProc(fileFromLMS, arr2D, rows);
					exit(EXIT_FAILURE);
				}
				if (feof(fileFromLMS) && !(j == cols - 1)) {
					perror("В файле не хватает элементов для матрицы!");
					errProc(fileFromLMS, arr2D, rows);
					exit(EXIT_FAILURE);
				}
			}
		}
		int a = ftell(fileFromLMS); fseek(fileFromLMS, 0, SEEK_END); int b = ftell(fileFromLMS);;
		if (a!=b) {
			perror("Слишком много элементов для матрицы!");
			errProc(fileFromLMS, arr2D, rows);
			exit(EXIT_FAILURE);
		}
		execArr2D(arr2D, rows, cols);
		fclose(fileFromLMS);
		return arr2D;
	}
	else {
		perror("Файл не удалось открыть!");
		errProc(fileFromLMS, arr2D, rows);
		exit(EXIT_FAILURE);
	}
}

int sumOfNumsUpperMainDiag(int** arr, int rows, int cols) {
	FILE* res; fopen_s(&res,"result.txt","w");
	if (res) {
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i+j<=(rows/2)+1 && i < rows - 1) {
					sum += arr[i][j];
					fprintf(res, "%d ", arr[i][j]);
				}
			}
		}
		fprintf(res, "\n%d", sum);
		printf("Успешная запись результата в файл result.txt!\n");
		fclose(res);
		return sum;
	}
	else {
		printf("Ошибка создания файла результата!");
		return NULL;
	}
}

void delArr2D(int** &arr,int rows) {
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
}

int main() {
	setlocale(LC_ALL, "russian");
	char* fileName = new char[20]; int rows, cols;
	strcpy_s(fileName, 20, "array2D_1.bin");
	int** Array2D;
	arrFromFile(fileName, rows, cols, Array2D);
	printf("%d",sumOfNumsUpperMainDiag(Array2D,rows,cols));
	delArr2D(Array2D, rows); 
	delete[] fileName;
}