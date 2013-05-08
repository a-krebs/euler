#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/*
 * Project Euler problem 14:
 *
 * Longest Collatz sequence starting under 1 million.
 *
 */

#define TRUE 1
#define FALSE 0

#define MAX_N 999999

int getLength(long n, int* cache)
{	
	int cached = 0;
	if (n == 1) {
		return 1;
	}
	if (n <= MAX_N) {
		cached = cache[n];
	}
	if (cached != 0) {
		return cached;
	} else if (n % 2 == 0) {
		cached = getLength(n / 2, cache) + 1;
	} else {
		cached = getLength(3*n + 1, cache) + 1;
	}
	if (n <= MAX_N) {
		cache[n] = cached;
	}
	return cached;
}

int main(int argc, char *argv[])
{
	long n_longest_chain = 0;
	int longest_chain_length = 0;
	long tmp = 0;
	int* cache = calloc(MAX_N + 1, sizeof(int));
	for (long n = MAX_N; n > 0; n--) {
		tmp = getLength(n, cache);
		if (longest_chain_length < tmp) {
			n_longest_chain = n;
			longest_chain_length = tmp;
		}
	}
	printf("%ld\n", n_longest_chain);
	free(cache);
	exit(EXIT_SUCCESS);
}
