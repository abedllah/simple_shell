#include "simple_shell.h"

int execute(char **args, char **argv) 
{
    pid_t child;
    int action;

    char *path = getenv("PATH");

    if (access(args[0], X_OK) == 0)
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

    char *path_copy = strdup(path); 
    char *token = strtok(path_copy, ":");
    while (token != NULL)
    {
        char command_path[1024]; 
        snprintf(command_path, sizeof(command_path), "%s/%s", token, args[0]);
        
        if (access(command_path, X_OK) == 0)  
        {
            child = fork();
            if (child == 0)
            {
                if (execve(command_path, args, envir) == -1)
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
            free(path_copy);
            return WEXITSTATUS(action);
        }
        token = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: command not found\n", args[0]);
    free(path_copy);
    return -1; 
}