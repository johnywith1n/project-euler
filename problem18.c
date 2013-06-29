#include <stdio.h>

int main ( ) {

	int array[15][15] = 	{	{75},
								{95,64},
								{17,47,82},
								{18,35,87,10},
								{20,04,82,47,65},
								{19,01,23,75,03,34},
								{88,02,77,73,07,63,67},
								{99,65,04,28,06,16,70,92},
								{41,41,26,56,83,40,80,70,33},
								{41,48,72,33,47,32,37,16,94,29},
								{53,71,44,65,25,43,91,52,97,51,14},
								{70,11,33,28,77,73,17,78,39,68,17,57},
								{91,71,52,38,17,14,91,43,58,50,27,29,48},
								{63,66,04,68,89,53,67,30,73,16,69,87,40,31},
								{04,62,98,27,23,9,70,98,73,93,38,53,60,04,23}};

	int count1, count2, curr, left, right, sum;

	count1 = 1;
	count2 = curr = left = right = sum = 0;


	while(count1 < 15) {

		while(count2 <= count1) {
			curr = array[count1][count2];
			left = array[count1-1][count2-1];
			right = array[count1-1][count2];

			if(count2 == 0) {
				// there is no left
				array[count1][count2] = curr + right;
			} else if(count2 == count1) {
				//there is no right
				array[count1][count2] = curr + left;
			} else if(curr+left > curr+right) {
				array[count1][count2] = curr + left;
			} else {
				array[count1][count2] = curr + right;
			}

			count2++;
		}

		count2 = 0;
		count1++;
	}


	while(count2 <= 14) {
		if(array[14][count2] > sum) {
			sum = array[14][count2];
		}

		count2++;
	}

	printf("%d", sum);

	return 0;

}

