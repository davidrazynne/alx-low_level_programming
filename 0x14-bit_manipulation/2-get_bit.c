#include"main.h"

/**
 * get_bit - program return the value of a bit at gvn indx
 * @n: no to check bits in
 * @index: indx to check bit
 *
 * Return: bit value, or -1(error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divisor, check;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	divisor = 1 << index;
	check = n & divisor;
	if (check == divisor)
		return (1);
	return (0);
}
