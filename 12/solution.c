#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
	int sequence = 3;		// start after 3, so that we don't have to deal
							// with 1 and 3 as corner cases for '1 and itself'
							// as factors
	int next = 3;
	int n;					// initialized in loop
	int numFactors;			// initialized in loop
	int potentialFactor;	// initialized in loop
	int upperBound = 0;

	while (numFactors < 500)
	{
		n = sequence + next;
		sequence += next;
		next ++;
		potentialFactor = 2; 	// assume 1 and n are already factors
		numFactors = 2;			// 1 and n are included already
		upperBound = ceil(sqrt(n));
		while (potentialFactor < upperBound)
		{
			if (n % potentialFactor == 0) {
				numFactors += 2;
				potentialFactor++;
			} else {
				potentialFactor++;
			}
		}
	}
	printf("%d\n", n);
}
