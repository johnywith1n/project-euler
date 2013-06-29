#include <stdio.h>

int main ( ) {
	int count,numDigits,currDigit,k, tempCount, digitCount;

	count = 0;

	for(numDigits = 1; numDigits < 7; numDigits++) {
		for(currDigit = 1; currDigit < 10; currDigit++) {
				k = numDigits;
				digitCount = currDigit;
				tempCount = 1;
				k--;
				while(k > 0) {
						tempCount = tempCount * (10-digitCount);
						k--;

				}
				count = count + tempCount;
		}
	}

	printf("%d\n", count);

	return 0;
}
