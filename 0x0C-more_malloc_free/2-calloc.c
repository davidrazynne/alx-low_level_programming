#include <stdlib.h>
#include "main.h"

/**
 * *_memset - starts by allocates memory for an array
 * @s: represents the memory A to be filled
 * @b: The char to copy
 * @n: how many times should we copy to b?
 *
 * Return: the pointer -> memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * *_calloc - lastly, this allocates memory for an array
 * @nmemb: no of elements in the array
 * @size: the size of each individual element
 *
 * Return: a pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, nmemb * size);

	return (ptr);
}

