#include <stdio.h>
#include "main.h"

/**
 * main - displays the name of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0if successfull
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
