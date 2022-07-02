#include "hash_tables.h"

/**
 * key_index - hash function that hashes string
 * to key hash_index.
 * @key: string to be hashed
 * @size: size of the array of the hash table
 * Return: hash_index for key/value in hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_index;

	if (size == 0)
		return (0);

	hash_index = hash_djb2(key) % size;

	return (hash_index);
}
