#include <stdio.h>
#include <math.h>
#include "solution.h"

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
