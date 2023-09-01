#include "main.h"

/**
 * get_endianness - a function that checks the endianness
 *
 * Return: 0 (big endian), 1 (little endian)
 *
 */
int get_endianness(void)
{
	unsigned int e = 1;
	char *c = (char *) &e;

	return (*c);
}
