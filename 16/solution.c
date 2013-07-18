#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * What is the sum of the difits of the number 2^1000 ?
 */

#define TRUE 1
#define FALSE 0
#define LARGENUM 400
#define POWER 1000

int main(int argc, char *argv[])
{	
	// store the digits of 2^1000 in an array
	int* product = calloc(sizeof(int), LARGENUM);
	// initialize to 2
	product[0] = 2;
	int numDigits = 1;

	int tmp = 0;
	int sum = 0;
	int carry = FALSE;

	// multiple product by itselt POWER times to get product
	for (int iteration = 0; iteration < POWER-1; iteration ++)
	{
		// do multiplication by multiplying one digit at a time
		// and carrying where necessary
		for (int i = 0; i < numDigits; i++)
		{
			tmp = 2 * product[i];
			if (carry == TRUE)
			{
				tmp += 1;
				carry = FALSE;
			}
			if (tmp >= 10)
			{
				product[i] = tmp - 10;
				carry = TRUE;
				// if we're at the head of product,
				// carrying adds another digit
				if (i == numDigits - 1)
				{
					numDigits++;
				}
			}
			else
			{
				product[i] = tmp;
			}
		}
	}
	for (int j = 0; j < LARGENUM; j++)
	{
		sum += product[j];
	}
	printf("%d\n", sum);
	free(product);
	exit(EXIT_SUCCESS);
}
