
int main  ( )
{
	unsigned int fib1, fib2, fibCurr, sum;

	fib1 = 0;
	fib2 = 1;
	fibCurr = fib1 + fib2;
	sum = 0;

	while(fibCurr < 4000000) {
		if(fibCurr % 2 == 0){
			sum = sum + fibCurr;
		}

		fib1 = fibCurr;

		fibCurr = fibCurr + fib2;

		fib2= fib1;
	}

	printf("%d", sum);

	return 0;
}
