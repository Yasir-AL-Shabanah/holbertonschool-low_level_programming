#include "hash_tables.h"

/**
 * hash_djb2 - djb2 string hash algorithm
 * @str: Null-terminated string to hash
 *
 * Return: Unsigned long hash value.
 *
 * Description: hash(i) = hash(i - 1) * 33 + str[i].
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
