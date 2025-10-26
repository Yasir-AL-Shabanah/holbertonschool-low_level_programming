#include "hash_tables.h"

/**
 * key_index - compute array index for a key
 * @key: key (non-NULL)
 * @size: table array size
 *
 * Return: index in [0, size-1]
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
if (!key || size == 0)
return (0);
return (hash_djb2(key) % size);
}
