#include "simple_shell.h"

int main(void) {
    char *line;
    char **args;

    while (1) {
        printf("$ ");
        line = read_line();
        if (line == NULL) {
            break; /* End of file (Ctrl+D) */
        }
        args = tokenize(line);
        if (args != NULL && args[0] != NULL) {
            execute(args);
        }

        /* Cleanup */
        free(line);
        free(args);
    }

    return EXIT_SUCCESS;
}
