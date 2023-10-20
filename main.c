#include "simple_shell.h"

char **envir;

int main(int ac, char **argv) {
    char *ptr_line = NULL, **arguments = NULL;
    int action = 0;
    char *line; 
    (void)ac;
    (void)argv;
    envir = environ;

    while (1) {
        ptr_line = read_line();
        if (ptr_line == NULL) {
            if (isatty(STDIN_FILENO)) {
                write(STDOUT_FILENO, "\n", 1);
            }
            exit(action);
        }

        line = strtok(ptr_line, "\n");
        while (line != NULL) {
            arguments = tokenize(line);
            if (arguments) {
                action = execute(arguments);
            }
            free(line);
            line = strtok(NULL, "\n");
        }

        free(ptr_line);
    }

    return 0;
}
