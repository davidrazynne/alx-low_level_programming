#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - function that prints a name
 *
 * @f: a pointer to function
 * @name: the added string
 * Return: void
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

