#include "simple_shell.h"

char *read_line(void) {
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        // Handle end of file (Ctrl+D)
        free(line);
        return NULL;
    }

    return line;
}