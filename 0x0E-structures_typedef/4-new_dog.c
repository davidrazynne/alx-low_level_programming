#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - this code will return the length of a string given
 *
 * @s: the actual string to evaluate in the code
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
