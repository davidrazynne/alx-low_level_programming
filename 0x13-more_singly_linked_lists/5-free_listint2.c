#include "lists.h"

/**
 * free_listint2 - avails a linked list
 * @head: address to the listint_t list that is availed
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
