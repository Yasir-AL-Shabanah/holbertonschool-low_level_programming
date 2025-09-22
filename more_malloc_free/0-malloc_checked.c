#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocate b bytes or exit(98) on failure
 * @b: bytes to allocate
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);
	return (p);
}
