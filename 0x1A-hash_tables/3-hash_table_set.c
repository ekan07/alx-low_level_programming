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
	unsigned long int hash_index;
	hash_node_t *head;
	hash_node_t *curs;
	hash_node_t *new_hnode;

	if (ht == NULL || strlen(key) == 0)
		return (0);

	new_hnode = malloc(sizeof(hash_node_t));
	if (!new_hnode)
		return (0);
	new_hnode->key = strdup(key);
	new_hnode->value = strdup(value);
	new_hnode->next = NULL;

	hash_index = key_index((unsigned char *)key, ht->size);
	head = ht->array[hash_index]
	if (!head)
		ht->array[hash_index] = new_hnode;
	else
	{
		
		for (curs = head; curs; curs = curs->next)
		{
			if (strcasecmp(curs->key, key) == 0)
			{
				curs->value = strdup(value)
				return (1);
			}
			
		}

		new_hnode->next = ht->array[hash_index];
		ht->array[hash_index] = new_hnode;
	}

	return (1);
}
