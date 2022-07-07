#include "hash_tables.h"

/**
 * hash_table_set - adds a new node at the beginning of a linked list
 * @ht: double pointer to the hash_node_t list
 * @key: new key to add in the node
 * @value: value to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_index = 0;
	hash_node_t *head = NULL;
	hash_node_t *new_hnode = NULL;

	if (!ht || !key || !(*key) || !value)
		return (0);

	hash_index = key_index((unsigned char *)key, ht->size);
	head = ht->array[hash_index]
	/* check if key exists */
	while (head && strcmp(head->key, key) != 0)
		head = head->next;
	/* update value if key already exists */
	if (head)
	{
		free(head->value);
		head->value = strdup(value)
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
