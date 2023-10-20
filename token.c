#include "simple_shell.h"


/**
 * tokenize - Tokenize a line into arguments
 * @ptr_line: The line to tokenize
 *
 * Return: An array of tokenized arguments
 */

char **tokenize(char *ptr_line) {
    char *token = NULL;
    char **arguments = NULL;
    int i = 0;

    if (!ptr_line)
        return NULL;

    arguments = malloc(sizeof(char *) * 1024);
    if (!arguments) {
        perror("Malloc failed");
        return NULL;
    }

    token = strtok(ptr_line, " \t\n");

    while (token) {
        if (*token)
        {
            arguments[i] = _strdup(token);
            i++;
        }
        token = strtok(NULL, " \t\n");
    }
    arguments[i] = NULL;

    free(ptr_line);

    if (i == 0)
    {
        free(arguments);
        return NULL;
    }

    return arguments;
}