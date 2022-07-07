#include "hash_tables.h"

/**
 * hash_table_set - adds a new node at the beginning of a linked list
 * @ht: The hash table
 * @key: key of the new element
 * @value: value of the new element
 *
 * Return: 1 on success, or 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_index = 0;
	hash_node_t *curs = NULL;
	hash_node_t *new_hnode = NULL;

	if (!ht || !key || !(*key) || !value)
		return (0);

	hash_index = key_index((unsigned char *)key, ht->size);
	curs = ht->array[hash_index];
	/* check if key exists */
	while (curs && strcmp(curs->key, key) != 0)
		curs = curs->next;
	/* update value if key already exists */
	if (curs)
	{
		free(curs->value);
		curs->value = strdup(value);
		return (1);
	}

	/* create and add new node to hash table if key not found */
	new_hnode = malloc(sizeof(*new_hnode));
	if (!new_hnode)
		return (0);
	new_hnode->key = strdup(key);
	new_hnode->value = strdup(value);
	new_hnode->next = ht->array[hash_index];

	ht->array[hash_index] = new_hnode;

	return (1);
}
