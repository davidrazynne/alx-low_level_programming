#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints out putchar
 *return=0;
 *
 *
 *no erro retuned
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}
