#include <stdlib.h>
#include "main.h"


/**
 * *malloc_checked - This one assigns memory by use of the malloc
 * @b: will be the no or bytes for allocation
 * Return: shows the allocate d memeory (pointer)
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
