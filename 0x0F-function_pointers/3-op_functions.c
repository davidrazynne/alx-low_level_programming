#include "3-calc.h"

int op_sub(int a, int b);
int op_add(int a, int b);
int op_mul(int a, int b);
int op_mod(int a, int b);
int op_div(int a, int b);

/**
 * op_add - this will returns the summation of 2 numbers.
 * @a: 1st number.
 * @b: 2nd number.
 * Return: The (a + b)
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the subtraction of 2 numbers.
 * @a: 1st number.
 * @b: 2nd number.
 * Return: (a - b)
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the multiplication of 2 numbers.
 * @a: 1st number.
 * @b: 2nd number.
 * Return: (a * b)
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the division of 2 numbers.
 * @a: 1st number.
 * @b: 2nd number.
 *
 * Return: The result of a / b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Returns what remained after the division of 2 numbers.
 * @a: 1st number.
 * @b: 2nd number.
 * Return: The remainderr the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}

