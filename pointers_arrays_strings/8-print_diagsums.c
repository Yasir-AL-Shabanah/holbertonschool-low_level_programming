#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - print sums of the two diagonals of a square matrix
 * @a: pointer to first element of matrix (size x size)
 * @size: matrix dimension
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i = 0;
	int s1 = 0, s2 = 0;

	while (i < size)
	{
		s1 += a[i * size + i];
		s2 += a[i * size + (size - 1 - i)];
		i++;
	}
	printf("%d, %d\n", s1, s2);
}
