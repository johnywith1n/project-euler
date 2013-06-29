#include <stdio.h>


 unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
	unsigned long long count, result;

	count = 0;
	result = 1;

	while(count < exp) {
		count++;
		result = (result*base)%mod;
	}

	return result;
}


int main ( ) {

	unsigned long long base, exp, mod;

	base = 2;
	exp = 7830457;
	mod = 10000000000;

	FILE * f1 = fopen ("out.txt", "wt");
	fprintf(f1, "%llu", (28433*modExp(base,exp,mod)+1)%mod);
	fclose (f1);
	return 0;

}
