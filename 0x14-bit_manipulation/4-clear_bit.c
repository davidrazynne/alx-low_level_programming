#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 *
 * @index:  starting from 0 of the bit you want to set
 *
 * @n: addtress for the number to change
 *
 * Return: 1 (success), -1 (failure)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
