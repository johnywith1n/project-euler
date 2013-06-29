#include <stdio.h>
#include <stdlib.h>

float getIntercept(float x1, float y1, float x2, float y2);

int main ( ) {
	FILE * file;
	int count, temp1,temp2,temp3,temp4,temp5,temp6, i, sign1, sign2, sign3;
	float ax,ay,bx,by,cx,cy, intercept1, intercept2, intercept3;


	count = 0;

	file = fopen("triangles.txt", "r");

	if(file == NULL) {
		printf("Failed to open file\n");
		fclose(file);
		exit(0);
	}

	for(i= 0; i < 1000; i++) {
			fscanf(file, "%d,%d,%d,%d,%d,%d", &temp1,&temp2,&temp3,&temp4,&temp5,&temp6);
			ax = temp1;
			ay= temp2;
			bx= temp3;
			by= temp4;
			cx= temp5;
			cy = temp6;

			intercept1 = getIntercept(ax,ay,bx,by);
			intercept2 = getIntercept(ax,ay,cx,cy);
			intercept3 = getIntercept(bx,by,cx,cy);

			if(intercept1 <0) sign1 = 0;
			else sign1 = 1;

			if(intercept2 <0) sign2 = 0;
			else sign2 = 1;

			if(intercept3 <0) sign3 = 0;
			else sign3 = 1;

			if(sign1^sign2 ||sign1^sign3 || sign2^sign3)
				count++;

			//printf("%f %f %f %f %f %f\n", ax,ay,bx,by,cx,cy);
	}

	printf("%d", count);

	return 0;
}

float getIntercept(float x1, float y1, float x2, float y2) {
	float slope;
	slope = (y2-y1)/(x2-x1);

	return y1-slope*x1;
}
