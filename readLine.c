#include "simple_shell.h"

char *read_line(void) 
{
    char *line = NULL;
    size_t len = 0;  
    ssize_t read_result;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);

    /* Move the declaration of read_result to the top */
    ssize_t read_result;
    read_result = getline(&line, &len, stdin);

    if (read_result == -1) 
    {
        free(line);
        return NULL;
    }

    /* Remove the newline character at the end, if present */
    if (line[read_result - 1] == '\n') 
    {
        line[read_result - 1] = '\0';
    }

    return line;
}
