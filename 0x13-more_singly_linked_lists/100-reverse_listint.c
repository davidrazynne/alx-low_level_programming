#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: address for the the first node
 * pre is previous node and next is the next node
 * Return: address for the  first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pre = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = pre;
		pre = *head;
		*head = next;
	}

	*head = pre;

	return (*head);
}
