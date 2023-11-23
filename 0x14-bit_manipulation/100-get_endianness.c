#include "main.h"

/**
 * get_endianness - a fxn that checks the endianness
 *
 * Return: 0 (big endian), 1 (little endian)
 */
int get_endianness(void)
{
	int a;
	char *b;

	a = 1;
	b = (char *)&a;
	return (*b);
}
