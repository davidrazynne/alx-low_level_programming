#include "lists.h"

/**
 * free_listint - avails the linked list
 * @head: listint_t list is availed
 */

void free_listint(listint_t *head)
{
	listint_t *temp;


	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
