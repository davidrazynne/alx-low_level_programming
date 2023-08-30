#include "lists.h"

/**
 *  * insert_nodeint_at_index - inserts a new node at a given position
 *
 * @head: address to the 1st node
 * newn is the new node
 * @n: actual data of new node
 * @idx: position where the new node is added
 * Return: address for the new node, or NULL if it’s at the end
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int e;
	listint_t *newn;
	listint_t *temp = *head;

	newn = malloc(sizeof(listint_t));
	if (!newn || !head)
		return (NULL);

	newn->n = n;
	newn->next = NULL;

	if (idx == 0)
	{
		newn->next = *head;
		*head = newn;
		return (newn);
	}

	for (e = 0; temp && e < idx; e++)
	{
		if (e == idx - 1)
		{
			newn->next = temp->next;
			temp->next = newn;
			return (newn);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
