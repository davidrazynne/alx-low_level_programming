#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid -  function that frees a 2d grid ->
 * previously created by your alloc_grid function
 * @grid: 2d grid
 * @height: height dimension of grid
 * Description: frees memory of grid
 * Return: nothing
 *
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

