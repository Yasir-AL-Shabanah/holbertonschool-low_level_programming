#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _calloc - allocates memory for an array and sets bytes to 0
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Overflow check: nmemb * size must fit in unsigned int */
	if (size != 0 && nmemb > UINT_MAX / size)
		return (NULL);

	total = nmemb * size;
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		mem[i] = 0;

	return (mem);
}
