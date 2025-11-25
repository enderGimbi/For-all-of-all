

//Файл для заметок на C

#include <clocale>
#include <stdio.h>
#include <stdlib.h>


int factorial(int a) { 
    int f = 0;  
    int f1 = 1; 
    for (int i = 0; a != i; i++) { 
        f++;
        f1 *= f; 
    }
    return f1; 
}

int srchCountOfDivisors(int a) {
    int c = 0; 
    for (int i = 1; i < (a + 1);i++) { 
        if (a % i == 0) c++;
    }
    return c;
}

bool checkForFibonachchi(int a) {
    int a1 = 0; int a2 = 1; int a3 = 1;
    for ( ; (a2 < a) && (a1 < a) && (a3 < a); ) {
        a1 = a3 + a2; a2 = a3 + a1; a3 = a1 + a2;
        if (a1 == a || a2 == a || a3 == a) return true;
    }
    return false;
}

bool thePerfectionOfNumber(int a) {
    int sum = 0;
    for (int i = 1; a > i;i++) {
        if (a% i == 0) sum += i;
    }
    if (a == sum) return true;
    return false;
}

double theArithmeticMeanOfTheEvenDigitsOfANumber(int a){
    double sum = 0; double k = 0; int ost;
    for ( ; a > 0; ) {
        ost = a % 10;
        a /= 10;
        if (ost % 2 == 0) { sum += ost; k++; }
    }
    if (k == 0) return 0;
    return sum / k;
}

int srchTheSPD(int a) {
    int max = 0;
    for (int i = 1; a > i;i++) {
        if ((a % i == 0) && (i > max)) max = i;
    }
    return max;
}

int srchSimpleDivisors(int a) {
    int k = 0;
    for (int i = 1; a > i; i++) {
        if ((a % i == 0) && (srchCountOfDivisors(i) == 2)) k++;
    }
    return k;
}

int checkForSqrt(int a) {
    for (int i = 1; a > i;i++) {
        if (a % i == 0) {
            for (int j = 2; a > j; j++) {
                int sqrt = j * j;
                if (sqrt == i) return 0;
            }
        }
    }
    return 1;
}

int srchSimpleDivisorsLessThan100(int a) {
    int k = 0;
    for (int i = 1; a > i; i++) {
        if ((a % i == 0) && (srchCountOfDivisors(i) == 2) && (i > 100)) k++;
    }
    if (k == 0) return 1;
    return 0;
}

int multDigitsOfNum(int a) {
    int ost; int res = 1;
    for (;a>0;) {
        ost = a % 10;
        a /= 10;
        if (ost != 0) res *= ost;
    }
    return res;
}

long double multDigOfNumsLessThenX(int a) {
    int ost; long double res = 1;
    for (int i = 1; a > i; i++) {
        int j = i;
        for (; j > 0;) {
            ost = j % 10;
            j /= 10;
            if (ost != 0) res *= ost;
        }
    }
    return res;
}

int srchSumDivisors(int a) {
    int sum = 0;
    for (int i = 1; (a + 1) > i;i++) {
        if (a % i == 0) sum += i;
    }
    return sum;
}

int srchSumEvenDivisors(int a) {
    int sum = 0;
    for (int i = 1; (a + 1) > i; i++) {
        if (a % i == 0 && i % 2 == 0) sum += i;
    }
    return sum;
}

int checkForACompositeNum(int a) {
    int k = 0;
    for (int i = 1; (a + 1) > i;i++) {
        if (a % i == 0 && i>0 && i<10) k++;
    }
    if (k > 2) return 1;
    return 0;
}

int srchSumCompositeDivisors(int a) {
    int sum = 0;
    for (int i = 1; (a + 1) > i; i++) {
        if (a % i == 0 && checkForACompositeNum(i)==1) {
            sum += i;
        }
    }
    return sum;
}

int srchSumOddDivisors(int a) {
    int sum = 0;
    for (int i = 1; (a + 1) > i; i++) {
        if (a % i == 0 && i % 2 == 1) sum += i;
    }
    return sum;
}

int srchSumAllNumsWhoseDivisorsAreTheSPD(int a) {
    int sum = 0; int k = 0;
    for (int i = a; k!=1 ;i++) {
        if (srchCountOfDivisors(i) == a)  sum += i;
        if (srchCountOfDivisors(i) == (a+1)) k++;
    }
    return sum;
}

// Модулька Алг и Прогр, тема 2


long long sumNFractions(int a) {
	long long sum = 0;
	for (long long i = 1; (a + 1) > i;i++) {
		long long b = 1 / i;
		sum += b;
	}
	return sum;
}

int thirdDigOfNum(int a) {
	int q = a%1000;
	int w = q / 100;
	return w;
}

int lastDigOfNum(int a) {
	int q = a&0xf;
	if (q > 10) return q - 10;
}

int nearestSimpleNum(int a) {
	int k1 = 0; int k2 = 0;
	for (int i = a; ; i++) {
		if (i % 2 == 1 && srchCountOfDivisors(i) == 2) break;
		k1++;
	}
	for (int i = a; ; i--) {
		if (i % 2 == 1 && srchCountOfDivisors(i) == 2) break;
		k2++;
	}
	if (k1 > k2) return a + k1;
	return a - k2;
}

int srchSquaresInRectangle(int a, int b, int n) {
	return (a / n) * (b/n);
}

int checkDivisibility_11(int a) {
	int k1 = 0; int k2 = 0;
	for (; a > 0; ) {
		k1 += (a % 10); a /= 10;
		k2 += (a % 10); a /= 10;
	}
	return ((k1-k2%11==0)||(k2 - k1 % 11 == 0));
}

int checkDivisibility_5(int a) {
	return (a > 0 && (a % 10 == 0 || a % 5 == 0));
}

int checkDivisibility_3(int a) {
	int sum = 0;
	for (;a>0;) {
		sum += a % 10;
		a /= 10;
	}
	return sum % 3 == 0;
}

int checkDivisibility_9(int a) {
	int sum = 0;
	for (; a > 0;) {
		sum += a % 10;
		a /= 10;
	}
	return sum % 9 == 0;
}


// Модулька по Алг и Прогр, тема 3


int translationFromAnySStoDec(int digit, int SS) {
	int sum = 0;
	int sup = 1;
	for (int i = SS; digit > 0;) {
		sum += (digit%10)*sup;
		sup *= i;
		digit /= 10;
	}
	return sum;
}

int translationFromDecToAny(int Dec, int SS) {
	int sum = 0;
	for (int i=1;Dec>0;i*=10) {
		sum += (Dec % SS)*i; Dec /= SS;
	}
	return sum;
}


// Модулька по Алг и Прогр, тема 4

int detectMinus(int digit) {
	return (digit & 0x7fffffff) == digit;
}

int checkEven(int num) {
	return (num | 0xfffffffe) == num;
}

unsigned short int multiplicationBy64(unsigned short int num) {
	return(num<<6);
}

int intDiv(int num) {
	return num >> 3;
}

int changeSign(int num) {
	return ~num+1;
}

int checkBit(int num,int pos) {
	num >>= pos;
	return (num&0xfffffffe)!=num;
}

void stepOf2(int num) {
	for (int i = 1;num>i;i<<=1) {
		printf("%d\n", i);
	}
}

void NEstepOf2(int num) {
	for (int i = 1; num > i; i <<= 1) {
		printf("%d\n", i);
	}
}


// Модулька по Практикуму

unsigned long long reverseNumber(unsigned long long number) {
	unsigned long long result = 0ull;
	for (unsigned long long tmp = number; tmp != 0ull; tmp/=10ull) {
		result *= 10ull;
		result += tmp % 10ull;
	}
	return result;
}

int highestDigit(long long int num) {
	int res = 0;
	for (;num!=0;num/=10) {
		if (res<num%10) res = num%10;
	}
	return res;
}

int firstNegativeNum() {
	int cache,sum=0;
	for (;;) {
		scanf_s("%i",&cache);
		if (cache < 0) return sum;
		sum += cache;
	}
}


// Практикум на ЭВМ 28.10.25 Реккурсия


int factorialWithRecursion(int number) {
	if (number == 0) return 1;
	return number*=factorialWithRecursion(number-1);
}

int fewfactorialWithRecursions(int start,int end) {
	while (end>=start) {
		printf("\n%d", factorialWithRecursion(start));
		return fewfactorialWithRecursions(start + 1, end);
	}
	return 0;
}

int degreeOfTheNumber(int number,int degree) {
	if (degree==0) return 1;
	number *= degreeOfTheNumber(number,degree - 1);
}

int sumDigitsOfNum(int number, int sum) {
	if (number == 0) return sum;
	sum += number % 10;
	sumDigitsOfNum(number / 10, sum);
}

int sumAllSimpleNumbers(int start, int end, int sum) {
	if (start > end) return sum;
	if (end >= start && srchCountOfDivisors(start) == 2) sum += start;
	sumAllSimpleNumbers(start + 1, end, sum);
}

int randNum(int min, int max) {
    return rand() % (max - min - 1) + min;
}

