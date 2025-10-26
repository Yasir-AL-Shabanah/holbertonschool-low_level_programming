#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - Free an entire hash table
 * @ht: Hash table to destroy
 *
 * Description: Frees all nodes, their keys and values, then the array
 * and the table descriptor itself. Safe to call with NULL.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			tmp = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
