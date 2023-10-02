#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void exit_error(int code, const char *format, const char *arg)
{
    dprintf(STDERR_FILENO, format, arg);
    exit(code);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        exit_error(97, "Usage: %s file_from file_to\n", argv[0]);
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    /* Open the source file for reading */
    int fd_source = open(file_from, O_RDONLY);
    if (fd_source == -1)
    {
        exit_error(98, "Error: unable to read from file %s\n", file_from);
    }

    /* Open or create the destination file for writing */
    int fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (fd_dest == -1)
    {
        exit_error(99, "Error: unable to write to file %s\n", file_to);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    /* Copy the content from source to destination */
    while ((bytes_read = read(fd_source, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(fd_dest, buffer, bytes_read);
        if (bytes_written == -1)
        {
            exit_error(99, "Error: unable to write to file %s\n", file_to);
        }
    }

    if (bytes_read == -1)
    {
        exit_error(98, "Error: unable to read from file %s\n", file_from);
    }

    /* Close file descriptors */
    if (close(fd_source) == -1)
    {
        exit_error(100, "Error: unable to close fd %d\n", fd_source);
    }
    if (close(fd_dest) == -1)
    {
        exit_error(100, "Error: unable to close fd %d\n", fd_dest);
    }

    return 0;
}
