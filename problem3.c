#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct sieve
{
	unsigned int num;
	int mark;
	struct sieve * prev;
	struct sieve * next;
};

struct sieve * init ( )
{
	struct sieve * head, * curr, * prev;


	unsigned int i;

	head = (struct sieve *) malloc(sizeof(struct sieve));
	head->num = 2;
	head->mark = 0;
	curr = head;

	for (i = 3; i < 775147; i++) {
		prev = curr;
		curr = (struct sieve *) malloc(sizeof(struct sieve));
		curr->num = i;
		curr->mark = 0;
		curr->prev = prev;
		prev->next = curr;
	}

	curr->next = head;
	head->prev = curr;

	return head;
}

int main ( )
{
	struct sieve * primes = init( );
	struct sieve * curr, * temp;
	curr = primes;

	unsigned int i, j, k,l;

	for (i = 2; i < 775147; i++) {
		if(curr->mark) {
			curr = curr->next;
			continue;
		}

		printf("%u\n",curr->num);

		temp = curr->next;

		for(j = i+1; j < 775147; j++) {
			l = temp->mark;
			if(temp->mark) {
				temp = temp->next;
				continue;
			}

			k = temp->num;

			if(k%i == 0) {
				temp->mark = 1;
			}

			//printf("%u\n",temp->mark);

			temp = temp->next;
		}

		curr = curr->next;
	}


	curr = primes->prev;


	while(curr->mark) {
		curr = curr->prev;
	}

	printf("%u\t%d",curr->num,curr->mark);


	return 0;
}
