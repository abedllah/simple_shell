#include "simple_shell.h"

int execute(char **args) 
{
    pid_t child;
    int action;
    char command_path[1024];
    char *path;
    char *path_copy;
    char *token;
    int found = 0;

    if (strchr(args[0], '/') != NULL)
    {
        child = fork();
        if (child == 0)
        {
            if (execvp(args[0], args) == -1)
            {
                perror(args[0]);
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

    path = getenv("PATH");
    path_copy = strdup(path);
    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        snprintf(command_path, sizeof(command_path), "%s/%s", token, args[0]);

        if (access(command_path, X_OK) == 0)
        {
            found = 1;
            break;
        }
        token = strtok(NULL, ":");
    }

    if (found)
    {
        child = fork();
        if (child == 0)
        {
            if (execvp(command_path, args) == -1)
            {
                perror(args[0]);
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

    fprintf(stderr, "%s: command not found\n", args[0]);
    free(path_copy);
    return -1;
}
