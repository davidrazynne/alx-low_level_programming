#include "lists.h"

/**
 * get_nodeint_at_index - returns the node of a listint_t linked list.
 * @head: pointer + data (node) in the linked list
 * @index: index of the node, starting at 0
 *
 * Return: address to the node in question, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int e = 0;
	listint_t *temp = head;

	while (temp && e < index)
	{
		temp = temp->next;
		e++;
	}

	return (temp ? temp : NULL);
}
