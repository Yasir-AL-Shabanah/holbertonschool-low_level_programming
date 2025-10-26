#include "hash_tables.h"

static int update_node(hash_node_t *node, const char *value)
{
char *vdup = strdup(value);

if (!vdup)
return (0);
free(node->value);
node->value = vdup;
return (1);
}

static hash_node_t *node_new(const char *key, const char *value)
{
hash_node_t *n = malloc(sizeof(*n));
char *kdup, *vdup;

if (!n)
return (NULL);
kdup = strdup(key);
vdup = strdup(value);
if (!kdup || !vdup)
{
free(n);
free(kdup);
free(vdup);
return (NULL);
}
n->key = kdup;
n->value = vdup;
n->next = NULL;
return (n);
}

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
unsigned long int idx;
hash_node_t *node;

if (!ht || !key || !*key || !value)
return (0);

idx = key_index((const unsigned char *)key, ht->size);
for (node = ht->array[idx]; node; node = node->next)
if (strcmp(node->key, key) == 0)
return (update_node(node, value));

node = node_new(key, value);
if (!node)
return (0);
node->next = ht->array[idx];
ht->array[idx] = node;
return (1);
}
