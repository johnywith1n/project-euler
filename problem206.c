#include <stdio.h>

long long power (long long base, int exp)
{
	long long result = 1;

	while (exp > 0) {
		result = result * base;
		exp--;
	}

	return result;
}

/* Returns the PLACE-th digit of NUM.
 */
 int getDigit(long long num, int place) {
	num = num%power(10, place);
	num = num - (num%power(10,place-1));
	num = num/power(10,place-1);

	return num;
}

int check (long long num) {
	long long square = num * num;

	if(square%10 == 9 && getDigit(square, 3) == 8 && getDigit(square, 5) == 7 &&
		getDigit(square, 7) == 6 && getDigit(square, 9) == 5 && getDigit(square, 11) == 4 &&
		getDigit(square, 13) == 3 && getDigit(square, 15) == 2 && getDigit(square, 17) == 1) {
			return 1;
		} else {
			return 0;
		}
}

int main ( ) {
	long long min = 101010103;
	long long max = 138902663;

	while(min <= max) {
		if(check(min)) break;
		if(min%10 == 3) {
			min = min + 4;
		} else {
			min = min + 6;
		}
	}

	min = min*10;

	printf("%lld", min);

	return 0;

}
