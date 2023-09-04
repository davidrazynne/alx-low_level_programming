#include "main.h"

/**
 * create_file – a fxn that creates a file.
 * @filename: A address to the name of the file that will be created
 * @text_content: NULL terminated string to write to the file
 *
 * Return:  1 if successful or -1 if it fails
 *
 */
int create_file(const char *filename, char *text_content)
{
	int dr, z, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	dr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(dr, text_content, len);

	if (dr == -1 || z == -1)
		return (-1);

	close(dr);

	return (1);
}
