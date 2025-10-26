#include "hash_tables.h"

/**
 * hash_table_print - print hash table like Python dict
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i;
hash_node_t *node;
int first = 1;

if (!ht)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
for (node = ht->array[i]; node; node = node->next)
{
if (!first)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
first = 0;
}
}
printf("}\n");
}
