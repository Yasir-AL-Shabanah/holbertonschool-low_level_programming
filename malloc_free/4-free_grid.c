#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free a 2D grid created by alloc_grid
 * @grid: pointer to grid
 * @height: number of rows
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;
	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
