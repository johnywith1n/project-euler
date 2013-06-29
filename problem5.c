int main ( )
{
	int i, check;
	unsigned int result;

	check = 0;

	for(result = 20; ; result+=20) {
		for(i = 2; i< 21; i++) {
			if(result%i != 0) break;
			if(i== 20) check = 1;
		}

		if(check) break;
	}

	printf("%u", result);

	return 0;
}
