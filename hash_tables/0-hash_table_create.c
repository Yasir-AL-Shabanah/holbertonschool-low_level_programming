#include "hash_tables.h"

/**
 * hash_table_create - create a hash table of given size
 * @size: size of the array
 *
 * Return: pointer to new table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *ht;
unsigned long int i;

if (size == 0)
return (NULL);

ht = malloc(sizeof(*ht));
if (!ht)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(hash_node_t *) * size);
if (!ht->array)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

return (ht);
}
