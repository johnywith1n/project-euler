#include <stdio.h>
#include <stdlib.h>

void sieve(short primes[], int length);

int main () {

	short * primes = (short *) malloc(sizeof(short) * 1000000);

	sieve(primes, 1000000);

	int i,j,counter,sum;

	sum = 0;
	for(i = 2; i<1000000; i++){
		if(!primes[i]) continue;
		sum = i;
		counter = 1;
		for(j = i+1; j< 1000000; j++) {
			if(!primes[j]) continue;
			sum = sum + j;
			counter++;
			if(sum >= 1000000) break;
			if(primes[sum] && primes[sum] < counter) primes[sum] = counter;
		}
	}

	j = 1;
	for(i = 2; i<1000000; i++) {
		if(primes[i] > j) {
			j = primes[i];
			sum = i;
		}
	}

	printf("%d\n", sum);

	return 0;
}

//set all indices that are prime numbers of primes to 1
void sieve(short * primes, int length) {
	int i,j;

	primes[0] = primes[1] = 0;

	for(i = 2; i < length; i++) {
		primes[i] = 1;
	}

	for(i = 2; i*i <= length; i++) {
		if(primes[i]) {
			for(j = i*i; j <= length; j = j+i) {
				primes[j] = 0;
			}
		}
	}
}
