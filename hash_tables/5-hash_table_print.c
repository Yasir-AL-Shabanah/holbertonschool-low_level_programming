#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Print all key/value pairs
 * @ht: Hash table to print
 *
 * Description: Prints in array order; within each bucket,
 * nodes are printed from head to tail.
 * Format: {'key1': 'val1', 'key2': 'val2', ...}
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", cur->key, cur->value);
			first = 0;
			cur = cur->next;
		}
	}
	printf("}\n");
}
