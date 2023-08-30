#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list
 * @h: address to the first node
 *
 * Return: count of items in the available list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t span = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			span++;
		}
		else
		{
			free(*h);
			*h = NULL;
			span++;
			break;
		}
	}

	*h = NULL;

	return (span);
}
