#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- a fxn that reads a text file & prints to POSIX stdout
 * @letters: count of letters to be read and print
 * @filename: text file being read
 * Return: w- actual count of letters (in bytes)
 * Return 0 when fxn fails, write fails, no expected bytes or filename is NULL
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
