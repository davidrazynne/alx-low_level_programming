#include "main.h"
/**
 * _memset - a function that fills a block of memory with a specific value
 * @s: beginning of the address of memory to be filled
 * @b: desired value
 * @n: size of the memory to be changed
 *
 * Return: changed array with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
