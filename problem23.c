#include <stdio.h>

int sumOfDivisors (int num);


int main ( ) {
	int i,j, temp;
	unsigned int result;
	int sum[20162] = {0};
	int abundantNumbers[20162] = {0};

	result = 0;
	temp = 0;

	for(i = 1; i< 20162; i++) {
		if(sumOfDivisors(i)) abundantNumbers[i] = 1;
	}

	for(i = 1; i< 20162; i++) {
		if(!abundantNumbers[i]) continue;

		for(j = 1; j< 20162; j++) {
			if(!abundantNumbers[j]) continue;

			temp = i+j;
			if(temp > 20161) continue;
			sum[temp] = 1;
		}
	}

	for(i = 1; i<20162; i++) {
		if(!sum[i]) result = result + i;
	}

	printf("%u\n", result);


	return 0;
}

int sumOfDivisors (int num) {
	int i, result;
	long long sum = 0;
	result = 0;

	for(i = 1; i*i <= num; i++) {
		if(num%i == 0) sum = sum + i + num/i;
		if(i*i == num) sum = sum - i;
	}

	if(sum > 2*num) result = 1;

	return result;
}
