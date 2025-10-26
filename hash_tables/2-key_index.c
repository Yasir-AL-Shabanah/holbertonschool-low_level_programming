#include "hash_tables.h"

/**
 * key_index - Map a key to a bucket index
 * @key: Key string (must not be NULL)
 * @size: Number of buckets in the table
 *
 * Return: Index in range [0, size - 1].
 * Description: Uses hash_djb2() then modulo @size.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
