#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: beginning of linked list which is a pointer to the first node.
 * @n: actual data to insert in the new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newn;

	newn = malloc(sizeof(listint_t));
	if (!newn)
		return (NULL);

	newn->n = n;
	newn->next = *head;
	*head = newn;

	return (newn);
}
