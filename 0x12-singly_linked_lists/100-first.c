#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first – prints out a sentence to the standard output
*before the main function is executed
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
