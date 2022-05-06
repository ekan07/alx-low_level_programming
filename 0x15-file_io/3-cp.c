#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    int src_fd, dest_fd, read_byte;
    char buff[BUFF_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
    
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
        exit(98);
    }

    dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (dest_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: can't write to file %s", argv[2]);
        exit(99);
    }

    while ((read_byte = read(src_fd, buff, BUFF_SIZE)) > 0)
    {
        if (write(dest_fd, buff, read_byte) != read_byte)
        {
            dprintf(STDERR_FILENO, "Error: can't write to file %s", argv[2]);
            exit(99);
        }
    }
    if (read_byte == -1)
    {
        dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
        exit(98);
    }
    
    if (close(src_fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}
	if (close(dest_fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}
    return (0);
}
