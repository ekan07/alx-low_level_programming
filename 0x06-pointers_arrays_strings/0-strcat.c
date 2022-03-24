#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Note The standard library provides a similar function: strcat.
 *
 * Compile with gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c
 * 0-strcat.c -o 0-strcat
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++; /* length of dest */
	}

	j = 0;
	while (src[j] != '\0')
	{
		/* add jth of src to ith of dest */
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
