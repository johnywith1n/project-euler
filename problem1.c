int main ( )
{
	int i, count;

	count = 0;

	for(i = 1; i < 1000; i++) {
		if(i%3 == 0 || i % 5 == 0) {
			count = count + i;
		}
	}

	printf("%d", count);

	return 0;
}
