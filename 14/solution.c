#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Project Euler problem 14:
 *
 * Longest Collatz sequence starting under 1 million.
 *
 */

#define TRUE 1
#define FALSE 0

#define MAX_N 999999

int getLength(long n, int length)
{
	if (n == 1) {
		return length + 1;
	} else if (n % 2 == 0) {
		return getLength(n / 2, length + 1);
	} else {
		return getLength(3*n + 1, length + 1);
	}
}

int main(int argc, char *argv[])
{
	long n_longest_chain = 0;
	int longest_chain_length = 0;
	long tmp = 0;
	for (long n = MAX_N; n > 0; n--) {
		tmp = getLength(n, 0);
		if (longest_chain_length < tmp) {
			n_longest_chain = n;
			longest_chain_length = tmp;
		}
	}
	printf("%ld\n", n_longest_chain);
}
