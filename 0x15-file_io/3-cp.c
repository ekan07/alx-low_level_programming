#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * _error - Read file.
 * @e: Error number
 * @filename: File name
 */
void _error(int e, char *filename)
{
	if (e == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	if (e == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

void _error_int(int e, int fd)
{
	if (e == 100)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
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
		_error(98, argv[1]);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((read_byte = read(src_fd, buff, BUFF_SIZE)) > 0)
	{
		if (dest_fd == -1 || write(dest_fd, buff, read_byte) != read_byte)
		{
			close(src_fd);
			_error(99, argv[2]);
		}
	}
	if (read_byte == -1)
		_error(98, argv[1]);

	if (close(src_fd) < 0)
	{
		close(dest_fd);
		_error_int(100, src_fd);
	}
	if (close(dest_fd) < 0)
		_error_int(100, dest_fd);

	return (0);
}
