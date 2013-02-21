#include <stdio.h>
#include <stdlib.h>

/* 
 * Project Euler problem 7:
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * 
 * What is the 10 001st prime number?
 */

#define TRUE 1
#define FALSE 0

#define NUM_PRIMES 10001

int main ( int argc, char *argv[])
{
	int num_found = 1;
	int candidate = 3;
	int upper_bound = 0;
	int i = 1;
	int* primes;

	primes = calloc(NUM_PRIMES, sizeof(int));
	// set first prime manually
	primes[0] = 2;
	upper_bound = candidate / 2 + 1;

	while(num_found < NUM_PRIMES)
	{
		while(i < upper_bound)
		{
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
		primes[num_found] = candidate;
		num_found++;
		candidate += 2;
		upper_bound = candidate + 1;
		i = 1;
	}
	printf("%d\n", primes[NUM_PRIMES - 1]);
	free(primes);
}
