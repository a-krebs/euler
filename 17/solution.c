#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * If the numbers 1 to 5 are written out in words: 
 * one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19
 * letters used in total.
 * 
 * If all the numbers from 1 to 1000 (one thousand) inclusive were
 * written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 
 * (three hundred and forty-two) contains 23 letters and 115 (one
 * hundred and fifteen) contains 20 letters. The use of "and" when
 * writing out numbers is in compliance with British usage.
 */

#define TRUE 1
#define FALSE 0

// define number of letters in each word
#define L_ZERO 4
#define L_ONE 3
#define L_TWO 3
#define L_THREE 5
#define L_FOUR 4
#define L_FIVE 4
#define L_SIX 3
#define L_SEVEN 5
#define L_EIGHT 5
#define L_NINE 4
#define L_TEN 3
#define L_ELEVEN 6
#define L_TWELVE 6
#define L_THIRTEEN 8
#define L_FOURTEEN 8
#define L_FIFTEEN 7
#define L_SIXTEEN 7
#define L_SEVENTEEN 9
#define L_EIGHTEEN 8
#define L_NINETEEN 8
#define L_TWENTY 6
#define L_THIRTY 6
#define L_FORTY 5
#define L_FIFTY 5
#define L_EIGHTY 6
#define L_HUNDRED 7
#define L_THOUSAND 8
#define L_AND 3
#define L_TY_SUFFIX 2

#define FROM 1
#define TO 1000

int numLetters(int n, int* lookup);

int main(int argc, char *argv[])
{	
	long sum = 0;
	int from = FROM;
	int to = TO;
	if (argc == 3)
	{
		from = atoi(argv[1]);
		to = atoi(argv[2]);
	}
	int lookup[20] = {
		L_ZERO,
		L_ONE,
		L_TWO,
		L_THREE,
		L_FOUR,
		L_FIVE,
		L_SIX,
		L_SEVEN,
		L_EIGHT,
		L_NINE,
		L_TEN,
		L_ELEVEN,
		L_TWELVE,
		L_THIRTEEN,
		L_FOURTEEN,
		L_FIFTEEN,
		L_SIXTEEN,
		L_SEVENTEEN,
		L_EIGHTEEN,
		L_NINETEEN,
	};
	for (int i = from; i < to + 1; i++)
	{
		sum += numLetters(i, lookup);
	}
	printf("%ld\n", sum);
	exit(EXIT_SUCCESS);
}

int numLetters(int n, int* lookup)
{	
	int letters = 0;
	int thousands = (int)floor(n / 1000);
	n = n % 1000;
	int hundreds = (int)floor(n / 100);
	n = n % 100;
	int tens = n;
	int tmp = 0;
	int and = FALSE;
	
	if (thousands != 0)
	{	
		letters += lookup[thousands];
		letters += L_THOUSAND;
		and = TRUE;
	}
	if (hundreds != 0)
	{
		letters += lookup[hundreds];
		letters += L_HUNDRED;
		and = TRUE;
	}
	if (tens > 19)
	{
		letters += (and == TRUE) ? L_AND : 0;
		// get number of letters in last digit
		letters += (n % 10 == 0) ? 0 : lookup[n % 10];
		// a few special cases to handle 20, 30, 50
		tmp = (int)floor(n/10);
		switch (tmp)
		{
			case 2:
				letters += L_TWENTY;
				break;
			case 3:
				letters += L_THIRTY;
				break;
			case 4:
				letters += L_FORTY;
				break;
			case 5:
				letters += L_FIFTY;
				break;
			case 8:
				letters += L_EIGHTY;
				break;
			default:
				letters += lookup[tmp] + L_TY_SUFFIX;
				break;
		}
	}
	else if (tens != 0)
	{
		letters += (and == TRUE) ? L_AND : 0;
		letters += lookup[tens];
	}
	return letters;
}
