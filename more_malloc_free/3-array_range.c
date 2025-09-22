#include "main.h"
#include <stdlib.h>

/**
 * array_range - create int array from min to max inclusive
 * @min: start value
 * @max: end value
 * Return: pointer to array [min..max], or NULL on fail/invalid
 */
int *array_range(int min, int max)
{
	int *a;
	int len, i;

	if (min > max)
		return (NULL);

	len = max - min + 1;
	a = malloc(sizeof(int) * len);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		a[i] = min + i;
	return (a);
}
