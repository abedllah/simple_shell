#include "simple_shell.h"

int execute(char **args) {
    if (execve(args[0], args, NULL) == -1) {
        perror("Execution error");
        return -1; /* Handle execution error */
    }
    return 0; /* Successful execution */
}
