#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a dog
 * @d: pointer to dog_t
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
