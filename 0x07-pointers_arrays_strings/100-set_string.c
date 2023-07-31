#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - a function that sets the value of a pointer to a char
 * @a: the matrix of the integers
 * @size: size of matrix
 * Return: Always 0
 */
void print_diagsums(int *a, int size)
{
int index, sum1 = 0, sum2 = 0;
for (index = 0; index < size; index++)
{
sum1 += a[index];
a += size;
}
a += size;
for (index = 0; index < size; index++)
{
sum2 += a[index];
a -= size;
}
printf("%d, %d\n", sum1, sum2);
}
