#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hash table to look into
 * @key: key of the value to retrieve
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int hash_index;
	hash_node_t *head;
	hash_node_t *curs;

	hash_index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[hash_index];
	for (curs = head; curs; curs = curs->next)
	{
		if (strcasecmp(curs->key, (char *)key) == 0)
			return (curs->value);
	}

	return (NULL);
}
