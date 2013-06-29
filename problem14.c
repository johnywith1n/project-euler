#include <stdio.h>
#include <stdlib.h>

int iter(int * array, long long index, int count) {

	if(index < 1000000 && array[index]) return array[index];

	long long temp;
	int length;

	length = temp = 0;

	if(index%2 == 0) temp = index/2;
	else 	temp = 3*index + 1;

	length = count + iter(array, temp, count);

	if(index < 1000000) array[index] = length;

	return length;
}


int main ( ) {

	int * array = (int *) malloc(sizeof(int) * 1000001);

	long long index;
	int length;
	unsigned int result;

	index = -1;
	result = length = 0;

	while(index < 1000000) {
		index++;
		array[index] = 0;
	}

	index = 0;

	array[1] = 1;

	while(index < 1000000) {
		index++;
		iter(array, index, 1);
	}

	index = 0;

	while(index < 1000000) {
		if(array[index] > length) {
			length = array[index];
			result = index;
		}
		index++;
	}

	printf("%u", result);

	return 0;
}
