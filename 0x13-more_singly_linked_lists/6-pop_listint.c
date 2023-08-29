#include "lists.h"

/**
 * pop_listint - deletes the head node of listint_t
 * @head: address to the first element in the linked list
 *
 * Return: actual data in the deleted items
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int digit;

	if (!head || !*head)
		return (0);

	digit = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (digit);
}
