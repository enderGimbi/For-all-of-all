//Тема 1
//
//#include<iostream>
//#define str_len 10
//
//int nearestAvg(int* mas,int len) {
//	int k=0,avg=0;
//	for (int i = 0; i < len; i++) {
//		k += mas[i];
//	}
//	avg = k / len;
//	k = *mas;
//	for (int i = 0; i < len;i++) {
//		if (abs(avg - k) > abs(avg - mas[i])) k = mas[i];
//	}
//	return k;
//}
//
//int betweenZeros(int* mas,int len) {
//	int check = 0,sum=0;
//	for (int i = 0; i < len;i++) {
//		if (mas[i] == 0) check++;
//		if (check == 1) sum += mas[i];
//	}
//	if (check == 1) return 0;
//	return sum;
//}
//
//int betweenNega(int* mas, int len) {
//	int check = 0, sum = 0;
//	for (int i = 0; i < len; i++) {
//		if (mas[i] < 0) check++;
//		if (check == 1) sum += mas[i];
//		if (mas[i] < 0&&check==1) sum -= mas[i];
//	}
//	if (check == 1) return 0;
//	return sum;
//}
//
//int sumBeforeLastPlus(int* mas,int len) {
//	int sum = 0, check = 0;
//	for (int i = 0; i < len; i++) {
//		if (mas[i] < 0) check++;
//		if (check == 0) sum += mas[i];
//	}
//	return sum;
//}
//
//void reverseArr(int* arr,int size) {
//	int cache;
//	for (int i = 0; i < size / 2; i++) {
//		cache = arr[i];
//		arr[i] = arr[size - 1 - i];
//		arr[size - 1 - i] = cache;
//	}
//}
//
//int firstChange(int* mas, int len) {
//	int check,k=0,flag=0;
//	if (*mas > 0)check = 1;
//	else check = 0;
//	for (int i = 1; i < len; i++) {
//		if (!flag) {
//			if (check == 1 && mas[i] < 0) {
//				k = i; flag = 1;
//			}
//			if (check == 0 && mas[i] > 0) {
//				k = i; flag = 1;
//			}
//		}
//	}
//	return k;
//}
//
//int* shiftMas(int* mas, int len,int step) {
//	int* arr = new int[len];
//	step = step % len;
//	if (step < 0)
//		step += len;
//	for (int i = 0; i < len; i++) {
//		if (i + step >= len) arr[abs(len - (i + step))] = mas[i];
//		else arr[i + step] = mas[i];
//	}
//	return arr;
//}
//
//void execArr(int* arr, int len) {
//	for (int i = 0; i < len; i++)
//		printf("%d ",arr[i]);
//	printf("\n");
//}
//
//
//
//
//int main() {
//	int str[str_len] = {1,2,-1,5,10,-6,7,12,9,10};
//	printf("%d\n",nearestAvg(str,str_len));
//	printf("%d\n",betweenZeros(str,str_len));
//	printf("%d\n", betweenNega(str, str_len));
//	printf("%d\n", sumBeforeLastPlus(str, str_len));
//	reverseArr(str, str_len);
//	execArr(str, str_len);
//	printf("%d\n", firstChange(str, str_len));
//	int* mas = new int[str_len];
//	mas = shiftMas(str, str_len, -1);
//	execArr(mas, str_len);
//
//}

// Тема 2

#include<iostream>
#define str_len 14
#define arr_len 10

int* fillArr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = i;
	}
	return arr;
}

void execArr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

int lenStr(char* str) {
	int k = 0;
	for (int i = 0; str[i] != 0;i++) k++;
	return k;
}

char* cutStr(char* str, char symb) {
	int len=0;
	for (int i = 0; str[i] != symb; i++) {
		len++;
	}
	char* str1 = new char[len + 1];
	str1[len] = 0;
	for (int i = 0;str1[i]!=0; i++) {
		str1[i] = str[i];
	}
	return str1;
}

char* changeStrByA(char* str,int len) {
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = 'A';
	}
	return str;
}

char* reverseStr(char* str) {
	char* str1 = new char[str_len];
	str1[strlen(str)] = 0;
	int len = strlen(str) - 1;
	for (int i = 0; str[i] != 0; i++) {
		str1[i] = str[len-i];
	}
	return str1;
}

char* delSymbInArr(char* str,int len,char symb) {
	int shift = 0;
	char* str1 = new char[len];
	for (int i = 0; str[i] != 0;i++) {
		if (str[i] == symb) shift++;
		else str1[i-shift] = str[i];
	}
	str1[strlen(str)-shift] = 0;
	return str1;
}

char* changeArrToStr(int* arr,int len) {
	char* str = new char[len+1];
	str[len] = 0;
	for (int i = 0; i < len; i++) {
		str[i] = '0' + arr[i];
	}
	return str;
}

char* changeArrToStrAndReverse(int* arr,int len) {
	char* str = new char[len + 1];
	str[len] = 0;
	for (int i = 0; i < len; i++) {
		str[len - i-1] = '0' + arr[i];
	}
	return str;
}

char* reverseByIndex(char* str,int len,int start,int end) {
	char* str1 = new char[len];
	str1[len - 1] = 0;
	for (int i = 0; str[i]!=0; i++) {
		str1[i] = str[i];
		if (i>=start && i<=end) {
			str1[i] = str[end-i];
		}
	}
	return str1;
}

int sravn(char* str1,char* str2) {
	int k = 0;
	if (strlen(str1) > strlen(str2))k = 1;
	else k = -1;
	return k;
}

int countOfSymbInStr(char* str,char symb) {
	int k = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == symb)k++;
	}
	return k;
}

char mostSeenCharInStr(char* str) {
	char res = *str; int max = 0;
	for (int i = 0; str[i] != 0; i++) {
		int count = 0;
		for (int j = 0;str[j]!=0; j++) {
			if (str[j] == str[i]) count++;
		}
		if (count > max) {
			max = count; res = str[i];
		}
	}
	return res;
}

char mostSeenDigInStr(char* str) {
	char res = *str; int max = 0;
	for (int i = 0; str[i] != 0; i++) {
		int count = 0;
		if (str[i] >= '0' && str[i] <= '9') {
			for (int j = 0; str[j] != 0; j++) {
				if (str[i] == str[j]) count++;
			}
			if (count > max) {
				max = count; res = str[i];
			}
		}
	}
	return res;
}

char* lowercaseToUppercase(char* str) {
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] + ('A'-'a');
		}
	}
	return str;
}


int main() {
	char* str = new char[str_len];
	str[str_len-1] = 0;
	strcpy_s(str, str_len, "Hello1 World!");
	//printf("%s", str);
	//printf("%d", lenStr(str));
	//printf("%s",cutStr(str,'1'));
	//printf("%s",changeStrByA(str,str_len));
	//printf("%s",reverseStr(str));
	//printf("%s",delSymbInArr(str,str_len,'l'));
	int* arr = new int[arr_len];
	arr = fillArr(arr,arr_len);
	//char* str1 = new char[arr_len + 1];
	//str1 = changeArrToStr(arr, arr_len);
	//printf("%s\n", changeArrToStr(arr, arr_len));
	//printf("%s\n",changeArrToStrAndReverse(arr,arr_len));
	//printf("%s",reverseByIndex(str,str_len,0,1));
	//printf("%d",countOfSymbInStr(str, 'l'));
	//printf("%c",mostSeenCharInStr(str));
	//printf("%c",mostSeenDigInStr(str));
	printf("%c",mostSeenDigInStr(str));
	//printf("%s",lowercaseToUppercase(str));

}

//Тема 3

//#include<iostream>
//#include<clocale>
//
//int maxOfNumFile(char* fileName) {
//	int num, max = 0;
//	FILE* myFile;
//	fopen_s(&myFile, fileName, "r");
//	if (!myFile){
//		printf("Файл не удалось открыть!\n");
//		return -1;
//	}
//	else {
//		while (fscanf_s(myFile, "%d", &num) == 1) {
//			if (num > max)max = num;
//		}
//		if (!feof(myFile)) printf("В файле присутствуют буквы\n");
//
//	}
//	fclose(myFile);
//	return max;
//}
//
//int maxOfDiag(char* fileName) {
//	FILE* myFile; int max = 0;
//	fopen_s(&myFile,fileName,"r");
//	if (!myFile) {
//		printf("Файл не удалось открыть!\n");
//		return -1;
//	}
//	else {
//		int height, width;
//		if (fscanf_s(myFile, "%d %d", &height, &width) == 2 || height==0 || width==0) {
//			if (height == width) {
//				int** arr = new int* [height];
//				for (int i = 0; i < height; i++) {
//					arr[i] = new int[width]();
//				}
//				for (int i = 0; i < height; i++) {
//					for (int j = 0; j < width; j++) {
//						if (fscanf_s(myFile, "%d", &arr[i][j]) == 0||(feof(myFile)&&j!=width-1)) {
//							printf("В файле не хватает элементов/Присутствуют буквы!\n");
//							for (int i = 0; i < height; i++) delete[] arr[i];
//							delete[] arr;
//							fclose(myFile);
//							return -4;
//						}
//					}
//				}
//				for (int i = 0; i < height; i++) {
//					if (max < arr[i][i]) max = arr[i][i];
//					if (max < arr[i][height - 1 - i]) max = arr[i][height - 1 - i]; // если необходимо найти максимум и для НЕ главной диагонали (уточнить у Веры Львовны)
//				}
//				for (int i = 0; i < height; i++) delete[] arr[i];
//				delete[] arr;
//			}
//			else {
//				printf("Матрица не квадратная!\n");
//				fclose(myFile);
//				return -3;
//			}
//		}
//		else {
//			printf("Неверные размеры матрицы!\n");
//			fclose(myFile);
//			return -2;
//		}
//	}
//	fclose(myFile);
//	return max;
//}
//
//int sumOfMainDiag(char* fileName) {
//	FILE* myFile; int sum = 0;
//	fopen_s(&myFile, fileName, "r");
//	if (!myFile) {
//		printf("Файл не удалось открыть/Указанного файла не существует!\n");
//		return -1;
//	}
//	else {
//		int height, width;
//		fscanf_s(myFile, "%d %d", &height,&width);
//		if (height==width) {
//			int** arr = new int* [height];
//			for (int i = 0; i < height; i++) {
//				arr[i] = new int[width]();
//			}
//			for (int i = 0; i < height; i++) {
//				for (int j = 0; j < width; j++) {
//					if (fscanf_s(myFile, "%d", &arr[i][j]) == 0 || (feof(myFile) && j != width - 1)) {
//						printf("В файле не хватает элементов/Присутствуют буквы!\n");
//						for (int i = 0; i < height; i++) delete[] arr[i];
//						delete[] arr;
//						fclose(myFile);
//						return -3;
//					}
//				}
//			}
//			for (int i = 0; i < height; i++) {
//					sum += arr[i][i];
//			}
//			for (int i = 0; i < height; i++) delete[] arr[i];
//			delete[] arr;
//		}
//		else {
//			printf("Матрица не квадратная!\n");
//			fclose(myFile);
//			return -2;
//		}
//	}
//	fclose(myFile);
//	return sum;
//}
//
//double resOfExp(char* fileName) {
//	FILE* myFile; double res = 0;
//	fopen_s(&myFile,fileName,"r");
//	if (!myFile) {
//		printf("Файл не удалось открыть/Указанного файла не существует!\n");
//		return -1;
//	}
//	else {
//		double num; char sign; 
//		if (fscanf_s(myFile, "%lf", &num) == 1) {
//			res += num;
//			while (fscanf_s(myFile, "%c%lf", &sign, (unsigned)sizeof(sign), &num) == 2) {
//				switch (sign) {
//				case '+':
//					res += num;
//					break;
//				case '-':
//					res -= num;
//					break;
//				case '/':
//					res /= num;
//					break;
//				case '*':
//					res *= num;
//					break;
//				default:
//					printf("Указан неверный знак!\n");
//					fclose(myFile);
//					return -3;
//				}
//			}
//			if (!feof(myFile)) {
//				printf("Ошибка чтения числа/знака!\n");
//				fclose(myFile);
//				return -2;
//			}
//		}
//		else {
//			printf("Ошибка чтения первого числа!\n");
//			fclose(myFile);
//			return -2;
//		}
//	}
//	fclose(myFile);
//	return res;
//}
//
//int resOfIntExp(char* fileName) {
//	FILE* myFile; int res = 0;
//	fopen_s(&myFile, fileName, "r");
//	if (!myFile) {
//		printf("Файл не удалось открыть/Указанного файла не существует!\n");
//		return -1;
//	}
//	else {
//		int num; char sign;
//		if (fscanf_s(myFile, "%d", &num) == 1) {
//			res += num;
//			while (fscanf_s(myFile, "%c%d", &sign, (unsigned)sizeof(sign), &num) == 2) {
//				switch (sign) {
//				case '+':
//					res += num;
//					break;
//				case '-':
//					res -= num;
//					break;
//				case '/':
//					res /= num;
//					break;
//				case '*':
//					res *= num;
//					break;
//				default:
//					printf("Указан неверный знак!\n");
//					fclose(myFile);
//					return -4;
//				}
//			}
//			if (!feof(myFile)) {
//				printf("Ошибка чтения числа/знака!\n");
//				fclose(myFile);
//				return -3;
//			}
//		}
//		else {
//			printf("Ошибка чтения первого числа!\n");
//			fclose(myFile);
//			return -2;
//		}
//	}
//	fclose(myFile);
//	return res;
//}
//
//char mostSeenSymbInFile(char* fileName) {
//	FILE* myFile; char res; int max = 0,count;
//	fopen_s(&myFile, fileName, "r");
//	if (!myFile) {
//		printf("Файл не удалось открыть!\n-");
//		return '1';
//	}
//	else {
//		char* str = new char[100]; 
//		str[99] = 0;
//		if (fgets(str, 100, myFile)) {
//			int len = strlen(str);
//			for (int i = 0; i < len; i++) {
//				count = 0;
//				for (int j = 0; j < len; j++) {
//					if (str[i] == str[j]) count++;
//				}
//				if (count > max) {
//					max = count;
//					res = str[i];
//				}
//			}
//		}
//		else {
//			printf("В файле нет данных!\n-");
//			fclose(myFile);
//			return '1';
//		}
//		delete[] str;
//	}
//	fclose(myFile);
//	return res;
//}
//
//int spacesAndDigsInFile(char* fileName) {
//	FILE* myFile;
//	fopen_s(&myFile, fileName, "r");
//	if (myFile) {
//		char* str = new char[10000];
//		if (fgets(str, 10000, myFile)) {
//			int len = strlen(str);
//			for (int i = 0; i < len; i++) {
//				if (!(str[i] >= '0' && str[i] <= '9')&&!(str[i]==' ')) {
//					return 0;
//				}
//			}
//			return 1;
//		}
//		else {
//			printf("В файле нет данных!\n");
//			return -2;
//		}
//	}
//	else {
//		printf("Файл не удалось открыть!\n");
//		return -1;
//	}
//}
//
//int main() {
//	setlocale(LC_ALL, "russian");
//	char* fileName = new char[100];
//	strcpy_s(fileName, 100, "text.txt");
//	//printf("%d", maxOfNumFile(fileName));
//	//printf("%d",maxOfDiag(fileName));
//	//printf("%d",sumOfMainDiag(fileName));
//	//printf("%.2lf", resOfExp(fileName));
//	//printf("%d", resOfIntExp(fileName));
//	//printf("%c", mostSeenSymbInFile(fileName));
//	//printf("%d",spacesAndDigsInFile(fileName));
//	delete[] fileName;
//}
//
