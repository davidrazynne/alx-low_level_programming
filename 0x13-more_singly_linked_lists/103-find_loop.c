
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 *
 * @head: the linked list in question
 * Return: adds of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *gentle = head;
	listint_t *swift = head;

	if (!head)
		return (NULL);

	while (gentle && swift && swift->next)
	{
		swift = swift->next->next;
		gentle = gentle->next;
		if (swift == gentle)
		{
			swift = head;
			while (gentle != swift)
			{
				gentle = gentle->next;
				swift = swift->next;
			}
			return (swift);
		}
	}

	return (NULL);
}

