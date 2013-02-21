#include <stdio.h>
#include <math.h>

/*
 * Project Euler problem 9:
 * 
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * 
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

/*
 * This problem can be simplified by solving out one of the variables:
 * sqrt(a^2 + b^2) = c
 * a + b + sqrt(a^2 + b^2) = 1000
 * sqrt(a^2 + b^2) = 1000 - a - b
 * a^2 + b^2 = (1000 - a - b)^2
 * a^2 + b^2 = 1000(1000 - a - b) - a(1000 - a - b) - b(1000 - a - b)
 * a^2 + b^2 = 1000^2 - 2000b - 2000a + 2ab + a^2 + b^2
 * 0 = 1000^2 - 2000b - 2000a + 2ab
 * b(2a - 2000) = -(1000^2) + 2000a
 * b = (-(1000^2) + 2000a) / (2a - 2000)
 */ 

#define TRUE 1
#define FALSE 0

int main ( int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	while(TRUE)
	{
		a++;
		b = (-1000000 + 2000 * a) / (2 * a - 2000);
		c = sqrt(pow(a, 2) + pow(b, 2));
		if (a + b + c == 1000)
		{
			printf("%d\n", a * b * c);
			break;
		}
	}
}
