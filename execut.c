#include "simple_shell.h"

int execute(char **args, char **argv) 
{
    pid_t child;
    int action;

    child = fork();
    if (child == 0)
    {
        argv[0] = args[0];

        if (execve(args[0], args, envir) == -1)
        {
            perror(argv[0]); 
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child, &action, 0);
        freeArr(args);
    }
    return WEXITSTATUS(action);
}
