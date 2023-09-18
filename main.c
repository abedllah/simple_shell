#include "simple_shell.h"

/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @argv: argument vector
*
* Return: 0
*/


char **envir;

int main(int ac, char **argv)
{
    char *line = NULL, **args = NULL;
    int action = 0;
    (void) ac;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(action);
        }

        args = tokenize(line);
        if (!args)
        {
            continue;
        }

        action = execute(args, argv);
    }

    return 0;
}
