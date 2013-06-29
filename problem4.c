/* Returns BASE^EXP.
 */
unsigned int power (unsigned int base, unsigned int exp)
{
	unsigned int result = 1;


	while (exp > 0) {
		result = result * base;
		exp--;
	}

	return result;
}

/* Returns the PLACE-th digit of NUM.
 */
 int getDigit(unsigned int num, int place) {
 	int result;
	num = num%power(10, place);
	num = num - (num%power(10,place-1));
	num = num/power(10,place-1);
	result = num;

	return result;
}

/* Checks to see if NUM is a palindrome
 * Returns 1if it is and 0 otherwise.
 */
int check(unsigned int num)
{
	int places, temp, mid, i, result;

	result = 1;
	places = 0;
	temp = num;

	while(temp > 0) {
		places++;
		temp /= 10;
	}

	mid = places/2;

	for(i = 1; i <= mid; i++) {
		if(getDigit(num, i) != getDigit(num, places-i+1)) {
			result = 0;
			break;
		}
	}

	return result;
}

int main ( )
{
	unsigned int i, j, k, l, result;

	result = 0;

	for(i = 1; i < 1000; i++) {
		// palindrome must be divisible by 11
		if(i%11 != 0) {
			l = 1;
		} else {
			l = 0;
		}

		for(j = i; j < 1000; j++) {
			if(l && j%11 != 0) continue;

			k = i * j;

			if(check(k) && k > result)
				result = k;
				//printf("%u\n",result);
		}
	}

	printf("%u", result);

	return 0;
}

