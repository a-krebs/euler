#include <stdio.h>

/*
 * Project Euler problem 5:
 * 
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible
 * by all of the numbers from 1 to 20?
*/

#define TRUE 1
#define FALSE 0
#define LOWER 1
#define UPPER 20

int main ( int argc, char *argv[])
{
	int is_divisible = TRUE;
	int i = 1;
	int candidate = 0;

	while (TRUE)
	{
		// candidates must be multiples of 20
		candidate = i * UPPER;

		for (int j = 1; j < UPPER + 1; j++)
		{
			if (candidate % j != 0)
			{
				is_divisible = FALSE;
			}
		}
		if (is_divisible == FALSE)
		{
			// try next candidate
			i++;
			is_divisible = TRUE;
		} 
		else 
		{
			// we've found the number
			break;
		}
	}
	printf("%d\n", candidate);
	return candidate;
}
