#include "main.h"

/**
 * get_endianness - a function that checks the endianness
 *
 * Return: 0 (big endian), 1 (little endian)
 *
 */


int get_endianness(void)
{
	unsigned int f = 1;
	char *c = (char *) &f;

	return (*c);
}
