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
	int count, prime;

	primes = (struct list *) malloc(sizeof(struct list));
	primes->prime = 2;
	primes->next = NULL;

	tail = curr = primes;
	prime = 1;

	count = 1;

	for(i = 3; count < 100001; i+=2) {

		while(curr) {
			if(i%curr->prime == 0) {
				prime = 0;
				break;
			}
			tail = curr;
			curr = curr->next;
		}



		if(prime) {
			tail->next = (struct list *) malloc(sizeof(struct list));
			tail->next->prime = i;
			tail->next->next = NULL;
			count++;
			tail = tail->next;
		}

		prime = 1;
		curr = primes;
	}

	printf("%u",tail->prime);

	return 0;
}
