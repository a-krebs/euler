#include <stdio.h>
#include "solution.h"

#define TRUE 1
#define FALSE 0

int main ( int argc, char *argv[])
{
	int is_divisible = TRUE;
	int i = 1;
	int candidate = 0;

	while (TRUE)
	{
		candidate = i * 20;
		for (int j = 1; j < 21; j++)
		{
			if (candidate % j != 0)
			{
				is_divisible = FALSE;
			}
		}
		if (is_divisible == FALSE)
		{
			i++;
			is_divisible = TRUE;
		} 
		else 
		{
			break;
		}
	}
	printf("%d\n", candidate);
	return candidate;
}
