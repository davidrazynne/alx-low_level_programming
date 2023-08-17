#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
* print_strings - Prints strings.
* @separator: is the string to be printed between strings.
* @n: is the number of strings passed to the function.
* @...: variable count of strings to be printed.
*
* Description: If separator is zero, don't print
*
* If one of the strings if NULL, print (nil) instead
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	char *str;
	unsigned int index;


	va_start(strings, n);


	for (index = 0; index < n; index++)
	{
		str = va_arg(strings, char *);


		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);


		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

		printf("\n");


		va_end(strings);
}
