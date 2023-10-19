#include "simple_shell.h"

/**
 * execute - Execute a command
 * @args: An array of command arguments
 *
 * Return: Exit status of the executed command
 */
int execute(char **args)
{
    if (args[0] == NULL) {
        return 0;
    }

    if (_strcmp(args[0], "exit") == 0)
    {
        exit(0);
    }
    else if (_strcmp(args[0], "env") == 0)
    {
        executeEnv();
        return 0;
    }

    if (strchr(args[0], '/') != NULL)
    {
        return executeCommand(args);
    }
    else
    {
        return executePathCommand(args);
    }
}

/**
 * executeCommand - Execute a command with a full path
 * @args: An array of command arguments
 *
 * Return: Exit status of the executed command
 */
int executeCommand(char **args)
{
    pid_t child;
    int action;

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
        _freeArr(args);
    }

    return WEXITSTATUS(action);
}



/**
 * executePathCommand - Execute a command using PATH
 * @args: An array of command arguments
 *
 * Return: Exit status of the executed command
 */
int executePathCommand(char **args)
{
    char command_path[1024];
    char *path = getenv("PATH");
    char *path_copy = _strdup(path);
    char *token = strtok(path_copy, ":");
    int found = 0;
    int action;

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
        pid_t child = fork();
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
            _freeArr(args);
        }
        free(path_copy);
        return WEXITSTATUS(action);
    }

    fprintf(stderr, "%s: command not found\n", args[0]);
    free(path_copy);
    return -1;
}
