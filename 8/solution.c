#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * Project Euler problem 8:
 * 
 * Find the greatest product of five consecutive digits in the 1000-digit number.
 * 
 * The number is stored in number.txt
 * Run solution with number.txt as the first argument.
 */

#define TRUE 1
#define FALSE 0

#define LENGTH 1000
#define CONSEC 5

int main ( int argc, char *argv[])
{
	FILE* file = fopen(argv[1], "r");
	int* number = calloc(LENGTH, sizeof(int));
	int c = 0;
	char cc = '\0';
	int n = 0;
	int product = 0;
	int max = 0;

	while((c = fgetc(file)) != EOF)
	{
		cc = (char) c;
		if(strncmp(&cc, "\n", 1) != 0)
		{
			number[n] = atoi(&cc);
			if(n > CONSEC - 1)
			{
				product = number[n];
				for(int i = 1; i < CONSEC; i++)
				{
					product *= number[n - i];
				}
				if(product > max)
				{
					max = product;
				}
			}
			n++;
		}
	}
	printf("%d\n", max);
	free(number);
}
