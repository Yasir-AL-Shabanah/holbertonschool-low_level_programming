#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocate zero-initialized array memory using malloc
 * @nmemb: number of elements
 * @size: bytes per element
 * Return: pointer to zeroed memory, or NULL on fail/invalid
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* check overflow: total = nmemb * size */
	if (size != 0 && nmemb > (~(unsigned int)0) / size)
		return (NULL);

	total = nmemb * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;
	return ((void *)p);
}
