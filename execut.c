#include "simple_shell.h"

int execute(char **args, char **argv) 
{
    pid_t child;
    int action;

    if (strchr(args[0], '/') != NULL)
    {
        child = fork();
        if (child == 0)
        {
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

    fprintf(stderr, "%s: command not found\n", args[0]);
    return -1;
}

