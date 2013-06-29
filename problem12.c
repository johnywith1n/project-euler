#include <stdio.h>

int main ( ) {
	unsigned long sum, triangleNum, index, temp;

	sum = triangleNum = 0;

	index = temp = 1;

	while(sum < 500) {

		// reset the sum
		sum = 0;
		// get the next triangle number
		triangleNum = triangleNum + index;

		// check all divisors under the square root of
		// each triangle number
		while(temp*temp < triangleNum) {
			if(triangleNum%temp == 0)	{
				sum = sum + 1;
			}

			temp++;
		}

		// account for each divisor under the square root of
		// the triangle number having a complement
		sum = sum * 2;

		// check to see if the triangle number is a square
		if(triangleNum%temp == 0)	{
				sum = sum + 1;
			}

		// reset the temp variable
		temp = 1;
		// increase index
		index++;
	}

	printf("%lu", triangleNum);

	return 0;

}
