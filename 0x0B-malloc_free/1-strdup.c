#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup -  returns a pointer to a newly allocated space in memory
 * contains a copy of the string given as a parameter
 * On success, the _strdup function returns a pointer to the duplicated string
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *aaa;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		aaa[r] = str[r];

	return (aaa);
}

