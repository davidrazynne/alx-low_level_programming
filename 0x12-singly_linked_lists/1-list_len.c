#include <stdlib.h>
#include "lists.h"

/**
 * list_len - function that returns the number of elements in a
 * linked list_t list
 * @h: this is pointer to the list_t list
 * Return: count of elements in h above
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
