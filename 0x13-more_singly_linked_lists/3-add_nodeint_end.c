#include "lists.h"

/**
 * add_nodeint_end – fxn that adds a new node at the end of a listint_t
 * @head: address to the 1st item in the linked list
 * @n: actual data (or new element)
 *newn means new node in this code.
 *
 * Return: address to the new node, or NULL if it fails or ends
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newn;
	listint_t *temp = *head;

	newn = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	newn->n = n;
	newn->next = NULL;

	if (*head == NULL)
	{
		*head = newn;
		return (newn);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = newn;

	return (newn);
}
