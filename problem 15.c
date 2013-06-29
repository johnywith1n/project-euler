#include <stdio.h>

int main ( ) {

	long long array[21][21];
	int i, j;
	long long temp;

	for(i = 0; i<20; i++) {
		for(j = 0; j<20; j++) {
			array[i][j] = 0;
		}
	}

	array[0][0] = 1;

	for(i = 0; i<21; i++) {
		for(j = 0; j<21; j++) {
			temp = 0;
			if(i-1 >= 0) temp = temp+array[i-1][j];
			if(j-1>=0) temp = temp +array[i][j-1];
			if(i!=0 || j!=0)	array[i][j] = temp;
			//printf("%d\t%d\t%lld\n",i,j,array[i][j]);
		}
	}

	printf("%lld\n",array[20][20]);

	return 0;
}
