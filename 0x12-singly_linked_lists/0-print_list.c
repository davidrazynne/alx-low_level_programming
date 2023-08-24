#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_list - a function that prints all the elements of a list_t list
 * @h: printable pointer to the list_t list
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
int count = 0;

while (h)
{
if (!h->str)
{
printf("[0] (nil)\n");
}
else
{
printf("[%d] %s\n", h->len, h->str);
}
count++;
h = h->next;
}
return (count);
}
