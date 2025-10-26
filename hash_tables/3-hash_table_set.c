#include "hash_tables.h"

/**
 * hash_table_set - add or update a key/value
 * @ht: hash table
 * @key: key (must be non-empty)
 * @value: value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
char *kdup, *vdup;
unsigned long int idx;
hash_node_t *node, *head;

if (!ht || !key || !*key || !value)
return (0);

idx = key_index((const unsigned char *)key, ht->size);
head = ht->array[idx];

for (node = head; node; node = node->next)
{
if (strcmp(node->key, key) == 0)
{
vdup = strdup(value);
if (!vdup)
return (0);
free(node->value);
node->value = vdup;
return (1);
}
}

node = malloc(sizeof(*node));
if (!node)
return (0);

kdup = strdup(key);
vdup = strdup(value);
if (!kdup || !vdup)
{
free(node);
free(kdup);
free(vdup);
return (0);
}

node->key = kdup;
node->value = vdup;
node->next = head;
ht->array[idx] = node;

return (1);
}
