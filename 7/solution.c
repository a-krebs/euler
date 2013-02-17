#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

#define TRUE 1
#define FALSE 0

#define NUM_PRIMES 10001

int main ( int argc, char *argv[])
{
	int num_found = 0;
	int candidate = 1;
	int upper_bound = 0;
	int i = 1;
	int* primes;

	primes = calloc(NUM_PRIMES, sizeof(int));
	upper_bound = candidate / 2 + 1;

	while(num_found < NUM_PRIMES)
	{
		while(i < upper_bound)
		{
			//printf("candidate: %d\ti: %d\tupper_bound: %d\n", candidate, i, upper_bound);
			i++;
			if(candidate % i == 0)
			{
				candidate += 2;
				upper_bound = candidate + 1;
				i = 1;
			}
			else
			{
				upper_bound = (candidate / i) + 1;
			}
		}
		// candidate is prime
		//printf("%d: %d\n", num_found + 1, candidate);
		primes[num_found] = candidate;
		num_found++;
		candidate += 2;
		upper_bound = candidate + 1;
		i = 1;
	}
	printf("%d\n", primes[NUM_PRIMES - 1]);
	free(primes);
}
