#include <stdio.h>

int main ( ) {
	unsigned long sum, count;
	//account for the case where n = 1
	sum = 1;
	//start at n = 3
	count = 3;

	while(count <= 1001) {
		sum = sum + (4*count*count) - (6*count) +6;
		count = count + 2;
	}

	printf("%lu", sum);

	return 0;
}
