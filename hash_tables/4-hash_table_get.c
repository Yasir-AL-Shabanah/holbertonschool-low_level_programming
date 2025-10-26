#include "hash_tables.h"

/**
 * hash_table_get - retrieve value by key
 * @ht: hash table
 * @key: key to search
 *
 * Return: value string, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int idx;
hash_node_t *node;

if (!ht || !key || !*key)
return (NULL);

idx = key_index((const unsigned char *)key, ht->size);

for (node = ht->array[idx]; node; node = node->next)
if (strcmp(node->key, key) == 0)
return (node->value);

return (NULL);
}
