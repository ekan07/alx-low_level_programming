#include "hash_tables.h"

/**
 * hash_table_delete - delete hash table
 * @ht: hash table
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i;
	hash_node_t *curs;
	hash_node_t *tmp;

	i = 0;
	while (i < ht->size)
	{
		curs = ht->array[i];
		while (curs)
		{
			tmp = curs->next;
			free(curs->key);
			free(curs->value);
			free(curs);
			curs = tmp;
		}
		i++;
	}
	free(ht->array);
	free(ht);

}
