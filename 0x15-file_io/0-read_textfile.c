#include "main.h"
#include <stdlib.h>

/*
 * read_texfile - reads a text file and prints it to the POSIX standard output
 * @filename: file that can be openned or read
 * @letters: actual number of letters read and printed
 * Return: bytes read and printed with 0 (cant be read/opened/ is NULL)
 */

ssize_t read_textfile(const char *filename, size_t letters);
{

	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, leters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);


}
