#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	long long int candidate = 3;
	// set 2 as first prime so only odd candidates must be considered
	long long int sum = 2;
	long long int upper_bound = 0;
	long long int i = 1;

	upper_bound = sqrt(candidate);

	while(TRUE)
	{
		while(i < upper_bound)
		{
			i++;
			if(candidate % i == 0)
			{
				candidate += 2;
				upper_bound = sqrt(candidate);
				i = 1;
			}
		}
		// candidate is prime
		if (candidate > MAX)
		{
			break;
		}
		sum += candidate;
		candidate += 2;
		upper_bound = sqrt(candidate);
		i = 1;
	}
	printf("%lld\n", sum);
}
