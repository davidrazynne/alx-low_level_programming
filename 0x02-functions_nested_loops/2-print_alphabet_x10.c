#include "main.h"

/**
* print_alphabet_x10 - prints 10 times the alphabet, all of them in lowercase,
*
*
*Return: void
*
*/
void print_alphabet_x10(void)
{
char cha;
int i;

i = 0;

while (i < 10)
{
cha = 'a';
for (cha = 'a'; cha <='z'; cha++)
{
_putchar(cha);

}
_putchar('\n');
i++;
}

}
