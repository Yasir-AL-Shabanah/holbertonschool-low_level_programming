#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Insert or update a key/value pair
 * @ht: Target hash table
 * @key: Key string (non-empty)
 * @value: Value string to store (duplicated)
 *
 * Return: 1 on success, 0 on failure.
 *
 * Description: On collision, insert new node at bucket head.
 * If key exists, replace its value with a duplicated copy.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *kdup, *vdup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			vdup = strdup(value);
			if (vdup == NULL)
				return (0);
			free(cur->value);
			cur->value = vdup;
			return (1);
		}
		cur = cur->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	kdup = strdup(key);
	if (kdup == NULL)
	{
		free(node);
		return (0);
	}

	vdup = strdup(value);
	if (vdup == NULL)
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
