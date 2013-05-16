#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Project Euler problem 15: Lattice Paths
 *
 * Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20x20 grid?
 *
 * 
 * This solution uses a grid where the number of paths to the current
 * cell is updated using the number of paths to the previous cell.
 * However, it is also possible to calculate the solution using an
 * adjacency matrix A of a graph of nodes and edges representing the
 * 20x20 grid. We know the longest path is of length 20*20, so the
 * value of A^(20*20)[20, 20] is the number of routes to the bottom
 * corner.
 */

#define TRUE 1
#define FALSE 0

#define COLS 20
#define ROWS 20

int main(int argc, char *argv[])
{	
	int cols = COLS + 1;
	int rows = ROWS + 1;
	long grid[cols][rows];
	memset(grid, 0, sizeof(long)*cols*rows);
	for (int i = 0; i < cols; i++)
	{	
		for (int j = 0; j < rows; j++)
		{
			if ((j == 0 && i != 0) || (i == 0 && j != 0))
			{
				grid[i][j] = 1;	
			} else if (i != 0 && j!= 0)
			{
				grid[i][j] += grid[i-1][j] + grid[i][j-1];
			}
		}
	}
	printf("%ld\n", grid[COLS][ROWS]);
	exit(EXIT_SUCCESS);
}
