#include "main.h"

/**
<<<<<<< HEAD
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Note The standard library provides a similar function: strcat.
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;
=======
 *_strcat - function that concatenates two strings.
 *@dest: pointer to destination string.
 *@src: pointer to source string.
 *
 *Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j; /* j will hold the length of the source */
>>>>>>> 048c39c8fa5bfbc5299b4de454a93a15def82ab3

	i = 0;
	while (dest[i] != '\0')
	{
<<<<<<< HEAD
		i++; /* length of dest */
=======
		i++;
>>>>>>> 048c39c8fa5bfbc5299b4de454a93a15def82ab3
	}

	j = 0;
	while (src[j] != '\0')
	{
<<<<<<< HEAD
		/* add jth of src to ith of dest */
=======
>>>>>>> 048c39c8fa5bfbc5299b4de454a93a15def82ab3
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
