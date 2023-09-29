#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index
 * for 64 bit OS, the bit range is 0(LSB) to 63(MSB)
 *
 * @index: index of the bit tarting from 0 of the bit you want to get
 *
 * @n: the digit that will be searched
 *
 * Return: value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
int _bitvalue;

if (index > 63)
return (-1);

_bitvalue = (n >> index) & 1;

return (_bitvalue);
}
