#include "main.h"

/**
 * _pow - fxn calc base power
 * @base: base of the expnnt
 * @power: power of the expnnt
 *
 * Return: value of base power
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int decimal;
	unsigned int a;

	decimal = 1;
	for (a = 1; a <= power; a++)
		decimal *= base;
	return (decimal);
}

/**
 * print_binary - disp a no in bnry notation
 * @n: no to disp
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor, check;
	char flag;

	flag = 0;
	divisor = _pow(2, sizeof(unsigned long int) * 8 - 1);
	while (divisor != 0)
	{
		check = n & divisor;
		if (check == divisor)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag == 1 || divisor == 1)
		{
			_putchar('0');
		}
		divisor >>= 1;
	}
}

