#include "hash_tables.h"

/**
 * hash_djb2 - djb2 string hash function
 * @str: input string
 *
 * Return: 64-bit hash
 */
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash = 5381;
int c;

while ((c = *str++))
hash = ((hash << 5) + hash) + (unsigned char)c;

return (hash);
}
