#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and initializes it to zero
 * @nmemb: number of elements
 * @size: size in bytes of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	if (size != 0 && nmemb > (~(unsigned int)0) / size)
		return (NULL);

	total = nmemb * size;
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		mem[i] = 0;

	return ((void *)mem);
}
