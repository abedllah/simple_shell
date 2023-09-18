#include "simple_shell.h"

int main(int argc, char **argv) 
{
    char *line = NULL;
    char **args = NULL;
    int action = 0;

    while (1) 
    {
        write(STDOUT_FILENO, "$ ", 2);
        line = read_line();
        if (line == NULL) 
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(action);
        }

        args = tokenize(line);
        if (!args) {
            continue;
        }
        
        action = execute(args, argv);
    }

    return 0;
}




/* int main(int argc, char **argv) 
{
    char *line = NULL;
    char **args = NULL;
    int action = 0;

    while (1) 
    {
        write(STDOUT_FILENO, "$ ", 2);
        line = read_line();
        if (line == NULL) 
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return action; 
        }

        args = tokenize(line);
        if (!args) {
            continue;
        }
        
        action = execute(args, argv);
    }

    return 0;
} */
