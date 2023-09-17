#include "simple_shell.h"

char *read_line(void) 
{
    char *line = NULL;
    size_t len = 0;  

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ",2);
    if (getline(&line, &len, stdin) == -1) 
    {
        free(line);
        return NULL;
    }

    return line;
}