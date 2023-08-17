#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
* print_numbers - a function that prints numbers,followed by \n
* @separator: is the string to be printed between numbers
* @n: number of integers passed to the function
* @...: variable count of numbers to be printed.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
		va_list nums;
		unsigned int index;


		va_start(nums, n);


		for (index = 0; index < n; index++)
		{
			printf("%d", va_arg(nums, int));


			if (index != (n - 1) && separator != NULL)
				printf("%s", separator);
		}


		printf("\n");


		va_end(nums);
}
