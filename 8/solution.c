#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "solution.h"

#define TRUE 1
#define FALSE 0

#define LENGTH 1000
#define CONSEC 5

int main ( int argc, char *argv[])
{
	FILE* file = fopen(argv[1], "r");
	int* number = calloc(LENGTH, sizeof(int));
	char consec[CONSEC];
	int filled = 0;
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
			if((n > 0) && (number[n] == (number[n-1] + 1)))
			{
				if(filled == 0)
				{
					consec[filled] = number[n-1];
					consec[filled + 1] = number[n];
					filled += 2;
				}
				else
				{
					consec[filled] = number[n];
					filled++;
				}
				if(filled == CONSEC)
				{
					product = consec[0];
					for(int i = 1; i < CONSEC; i++)
					{
						product *= consec[i];
					}
					if(product > max)
					{
						max = product;
					}
					for(int j = 1; j < CONSEC; j++)
					{
						consec[j-1] = consec[j];
					}
					filled--;
				}
			}
			else
			{
				filled = 0;
			}


			n++;
		}
	}
	printf("%d\n", max);
	//for(int i = 0; i < LENGTH; i++)
	//{
	//	printf("%d", number[i]);
	//	if((i + 1) % 50 == 0)
	//	{
	//		printf("\n");
	//	}
	//}
	free(number);
}
