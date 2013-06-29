#include <stdio.h>


int main ( ) {

	int array[10000] = {0};

	int index, divisor, temp;
	unsigned int sum;

	index = 2;
	sum = temp = 0;
	divisor = 2;

	while(index < 10000) {
		while(divisor*divisor < index) {
			if(index%divisor == 0) {
				temp = temp + divisor + index/divisor;
			}
			divisor++;
		}
		array[index] = temp + 1;
		index++;
		temp = 0;
		divisor = 2;
	}

	index = 2;

	while(index < 10000) {
		temp = array[index];
		if(temp && temp < 10000 && index != temp && index == array[temp]) {
			//printf("%d\n", temp);
			sum = sum + temp + array[temp];
			array[temp] = 0;
			array[index] = 0;
		}
		index++;
	}

	printf("%u", sum);

	return 0;

}
