#include "simple_shell.h"

/**
 * read_line - a function that reads a line
 *
 * Return: a string
 */

char *read_line(void)
{
	char *ptr_line = NULL;
	size_t buf_size = 0;
	ssize_t read_num;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read_num = getline(&ptr_line, &buf_size, stdin);

	if (read_num == -1)
	{
		free(ptr_line);
		return (NULL);
	}

	if (ptr_line[read_num - 1] == '\n')
	{
		ptr_line[read_num - 1] = '\0';
	}

	return (ptr_line);
}
