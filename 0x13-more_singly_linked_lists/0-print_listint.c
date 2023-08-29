#include "list.h"

/**
 * print_listint - a function that prints all the elements of a listint_t list
 * @h: list singly linked to be printed
 * Return:  the number of nodes
 */

size_t print_listint(const listint_t *h);
{
	size_t n = 0;

		for (n = 0; h; n++)
		{
			printf("%d\n", h->n);
				h = h->next;
		}
	return (n);
}
