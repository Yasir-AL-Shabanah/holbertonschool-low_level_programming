#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * create_node - creates a new node for the hash table
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
    hash_node_t *n = malloc(sizeof(hash_node_t));

    if (n == NULL)
        return (NULL);

    n->key = strdup(key);
    n->value = strdup(value);
    n->next = NULL;

    if (n->key == NULL || n->value == NULL)
    {
        free(n->key);
        free(n->value);
        free(n);
        return (NULL);
    }
    return (n);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: hash table
 * @key: non-empty key
 * @value: value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int idx;
    hash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    idx = key_index((const unsigned char *)key, ht->size);

    for (node = ht->array[idx]; node; node = node->next)
    {
        if (strcmp(node->key, key) == 0)
        {
            char *vdup = strdup(value);

            if (vdup == NULL)
                return (0);
            free(node->value);
            node->value = vdup;
            return (1);
        }
    }

    node = create_node(key, value);
    if (node == NULL)
        return (0);

    node->next = ht->array[idx];
    ht->array[idx] = node;
    return (1);
}
