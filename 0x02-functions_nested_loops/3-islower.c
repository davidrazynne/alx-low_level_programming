#include "main.h"

/**
* _islower - check if char is lowercase
* @c: is the char to be checked
* Return: 1 if a character is lowercase, otherwise, show 0.
*/

int _islower(int c)

{

		if (c >= 97 && c <= 122)
		{

		return (1);
		}
		return (0);
}

