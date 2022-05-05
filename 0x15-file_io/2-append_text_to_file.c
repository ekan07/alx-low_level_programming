#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text at the end of a file
 *
 * @filename: name of file to create
 * @text_content: NULL terminated string to add to the end of the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, append_f, str_len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (*(text_content + str_len))
			str_len++;
		append_f = write(fd, text_content, str_len);
		if (append_f == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
