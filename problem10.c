#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct list {
	unsigned int prime;
	struct list * next;
};

int main ( )
{
	struct list * primes, * curr, * tail;
	unsigned int i;
	int prime;
	unsigned long long sum;

	primes = (struct list *) malloc(sizeof(struct list));
	primes->prime = 2;
	primes->next = NULL;

	tail = curr = primes;
	prime = 1;

	sum = 0;

	for(i = 3; i < 2000000; i+=2) {
		// only check those under sqrt(2000000)
		while(curr && curr->prime < 1415) {
			if(i%curr->prime == 0) {
				prime = 0;
				break;
			}

			curr = curr->next;
		}


		if(prime) {
			tail->next = (struct list *) malloc(sizeof(struct list));
			tail = tail->next;
			tail->prime = i;
			tail->next = NULL;
		}

		prime = 1;
		curr = primes;
	}

	while(curr) {
		sum = sum + curr->prime;
		curr = curr->next;
	}

	printf("sum\t%llu", sum);

	return 0;
}

