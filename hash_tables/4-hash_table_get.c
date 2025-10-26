#include "hash_tables.h"
#include <string.h>
#include <stddef.h>

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *cur;

	if (!ht || !key || !*key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}
