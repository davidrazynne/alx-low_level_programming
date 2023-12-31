#include "main.h"

/**
 * binary_to_uint - function converts a binary decimalber to an unsigned int.
 * @b: pntr to a strng with binary no
 * Return: uint with dcml value of binary no, 0 if there is error
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int decimal;

	decimal = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
	if (b[a] != '0' && b[a] != '1')
		return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
	decimal <<= 1;
	if (b[a] == '1')
		decimal += 1;
	}
	return (decimal);
}
