#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - returns a pointer to a newly allocated space with copy of arg
 * @str: string to copy
 *
 * Return: pointer to array or null
 **/
char *_strdup(char *str)
{
	int i, j;
	char *str_dup;

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}

	str_dup = (char *) malloc((i++) * sizeof(char)); /* increment i for '\0'*/
	if (str_dup == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (j < i)
	{
		*(str_dup + j) = *(str + j);
		j++;
	}

	return (str_dup);
}
