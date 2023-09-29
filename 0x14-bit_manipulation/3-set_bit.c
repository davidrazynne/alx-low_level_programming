#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: the digit that will be searched
 * for 64 bit OS, the bit range is 0(LSB) to 63(MSB)
 * unsigned long (UL) integer shifts the number 1
 * @index: Index of the bit starting from 0 of the bit you want to get
 *
 * Return: 1 (success), -1 (failure)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = ((1UL << index) | *n);
return (1);
}
