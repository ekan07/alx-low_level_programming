#include "main.h"
#include <stdlib.h>

/**
 * *create_array - Create an array object of char
 * and initializes it with a specific char
 *
 * @size: size of the array to create
 * @c: char to initialize the array c
 *
 * Return: pointer to the array (Success), NULL (Error)
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *str;

	if (size == 0)
	{
		return (NULL);
	}

	str = (char *) malloc(size * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		*(str + i) = c;
		i++;
	}

	*(str + i) = '\0';
	return (str);
}
