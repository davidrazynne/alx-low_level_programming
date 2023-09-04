#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- a fxn that reads a text file & prints to POSIX stdout
 * @letters: count of letters to be read and print
 * @filename: text file being read
 * Return: w- actual count of letters (in bytes)
 * Return  0 when fxn fails, write fails, no expected bytes or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t dr;
	ssize_t z;
	ssize_t y;

	dr = open(filename, O_RDONLY);
	if (dr == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	y = read(dr, buf, letters);
	z = write(STDOUT_FILENO, buf, y);

	free(buf);
	close(dr);
	return (z);
}
