#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t len = 0;

	temp = *h;
	if (h == NULL)
		return (len);
	while (temp)
	{
		if (temp <= temp->next)
		{
			free(temp);
			len++;
			break;
		}

		*h = temp->next;
		free(temp);
		temp = *h;
		len++;
	}

	*h = NULL;
	return (len);
}
