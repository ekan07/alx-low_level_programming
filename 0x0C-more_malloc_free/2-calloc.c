#include <stdlib.h>
#include "main.h"

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *m_allocate;

	if (nmemb == 0 || size == 0)
		return (NULL);

	m_allocate = malloc(nmemb * size);
	if (!m_allocate)
		return (NULL);

	/* The memory is set to zero */
	for (i = 0; i < nmemb * size; i++)
		*(m_allocate + i) = 0;

	return (m_allocate);
}
