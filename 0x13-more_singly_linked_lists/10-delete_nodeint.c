#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at index of a listint_t linked list
 * @head: address for  the first item
 *
 *@index: node to be deleted
 *
 * Return: 1 or -1 (1 if success)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int e = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (e < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		e++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
