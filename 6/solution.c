#include <stdio.h>
#include <math.h>

/*
 * The sum of the squares of the first ten natural numbers is,
 * 
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * 
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#define TRUE 1
#define FALSE 0

int main ( int argc, char *argv[])
{
	double sum_of_squares = 0;
	double sum = 0;
	double squared_sum = 0;
	for (int i = 1; i < 101; i++)
	{
		sum_of_squares += pow(i, 2);
		sum += i;
	}
	squared_sum = pow(sum, 2);
	printf("%.0f\n", squared_sum - sum_of_squares);
}
