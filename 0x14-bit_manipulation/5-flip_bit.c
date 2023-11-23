#include "main.h"

/**
 * flip_bits - function that counts no of bits to change to get frm no to no
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, countbit = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		current = exclusive >> a;
		if (current & 1)
			countbit++;
	}

	return (countbit);
}
