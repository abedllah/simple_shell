#include "simple_shell.h"

/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @argv: argument vector
*
* Return: 0
*/

int main(int ac, char **argv)
{
	char *ptr_line = NULL, **arguments = NULL;
	int action = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		ptr_line = read_line();
		if (ptr_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(action);
		}

		arguments = tokenize(ptr_line);
		if (!arguments)
		{
			continue;
		}

		action = execute(arguments);
	}

	return (0);
}
