#include "simple_shell.h"

char *read_line(void) 
{
    char *line = NULL;
    size_t len = 0;  
    ssize_t read_result;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ",2);

    char buffer[1024];
    
    if ((read_result = read(STDIN_FILENO, buffer, sizeof(buffer))) == -1) 
    {
        perror("read");
        return NULL;
    }

    if (read_result == 0) 
    {
        return NULL; 
    }

    if (buffer[read_result - 1] == '\n') 
    {
        buffer[read_result - 1] = '\0';
        len = read_result;
    } 
    else 
    {
        len = read_result + 1;
        buffer[read_result] = '\0';
    }

    line = malloc(len);
    if (line == NULL) 
    {
        perror("malloc");
        return NULL;
    }
    strcpy(line, buffer);

    return line;
}
