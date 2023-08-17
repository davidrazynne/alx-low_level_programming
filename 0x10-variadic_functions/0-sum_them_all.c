#include "variadic_functions.h"
#include <stdarg.h>


/**
* sum_them_all - a function that returns the sum of all its parameters.
* @n: will be the number of paramters passed to the function.
* @...: will be a variable number of parameters to calc the sum of.
*
* Return: If n == 0, ruturn 0.
* Otherwise - the addition of all parameters.
*/
int sum_them_all(const unsigned int n, ...)
	{
		va_list ap;
		unsigned int i, sum = 0;


		va_start(ap, n);


		for (i = 0; i < n; i++)
			sum += va_arg(ap, int);


		va_end(ap);


		return (sum);
	}

