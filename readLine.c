#include "simple_shell.h"

char *read_line(void) 
{
    char *line = NULL;
    size_t len = 0;  

<<<<<<< HEAD
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ",2);
    if (getline(&line, &len, stdin) == -1) 
    {
=======
    if (getline(&line, &len, stdin) == -1) {
        /* Handle end of file (Ctrl+D) */
>>>>>>> c86a95096c366423d6f85520815481d75e627e97
        free(line);
        return NULL;
    }

    return line;
}
