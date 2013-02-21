#include <stdio.h>
#include <stdlib.h>

/* 
 * Project Euler problem 10:
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below two million.
 */

#define TRUE 1
#define FALSE 0

#define ALLOC_INTERVAL 100
#define MAX 2000000

int main ( int argc, char *argv[])
{
	int num_found = 1;
	long long int candidate = 3;
	long long int sum = 2;
	long long int upper_bound = 0;
	long long int i = 1;
	long long int* primes;

	primes = malloc(ALLOC_INTERVAL * sizeof(long long int));
	// manually set 2 as first prime so we can check only odd candidates
	primes[0] = 2;
	upper_bound = candidate / 2 + 1;

	while(TRUE)
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
		if (num_found % ALLOC_INTERVAL == 0)
		{
			primes = realloc(primes, (num_found + ALLOC_INTERVAL) * sizeof(long long int));
		}
		if (candidate > MAX)
		{
			break;
		}
		primes[num_found] = candidate;
		num_found++;
		sum += candidate;
		candidate += 2;
		upper_bound = candidate + 1;
		i = 1;
	}
	printf("%lld\n", sum);
	free(primes);
}
