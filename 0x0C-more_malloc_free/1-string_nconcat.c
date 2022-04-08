#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, s1_len = 0, s2_len = 0;
	char *str;

	while (s1 != NULL && *(s1 + s1_len) != '\0')
		s1_len++;
	while (s2 != NULL && *(s2 + s2_len) != '\0')
		s2_len++;

	if (n >= s2_len)
		str = malloc((s1_len + s2_len + 1) * sizeof(char));
	else
		str = malloc((s1_len + n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	while (i < s1_len)
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (n >= s2_len && i < (s1_len + s2_len))
	{
		*(str + i) = *(s2 + j);
		i++, j++;
	}
	while (n < s2_len && i < (s1_len + n))
	{
		*(str + i) = *(s2 + j);
		i++, j++;
	}
	*(str + i) = '\0';
	return (str);
}
