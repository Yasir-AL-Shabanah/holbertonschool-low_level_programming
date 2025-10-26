#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *kdup, *vdup;

	if (!ht || !key || !*key || !value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			vdup = strdup(value);
			if (!vdup)
				return (0);
			free(cur->value);
			cur->value = vdup;
			return (1);
		}
		cur = cur->next;
	}
	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	kdup = strdup(key);
	if (!kdup)
	{
		free(node);
		return (0);
	}
	vdup = strdup(value);
	if (!vdup)
	{
		free(kdup);
		free(node);
		return (0);
	}
	node->key = kdup;
	node->value = vdup;
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
