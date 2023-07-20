#include "main.h"

/**
 * print_numbers - print integers 0-9 follow by new line
 * return: void
 */

void print_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}

