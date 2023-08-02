#include "main.h"
/**
 * _strlen_recursion - a function that returns how long a string is.
 * @s: specific string
 *
 * Return: how long a string is
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		longit += _strlen_recursion(s + 1);
	}

	return (longit);
}
