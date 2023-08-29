#include "lists.h"

/**
 * sum_listint - computes the sum of all the data in a listint_t linked list
 * @head: 1st node pointer/address in the linked list
 *
 * Return: summation of the data (sumtn)
 */

int sum_listint(listint_t *head)
{
	int sumtn = 0;
	listint_t *temp = head;

	while (temp)
	{
		sumtn += temp->n;
		temp = temp->next;
	}

	return (sumtn);
}
