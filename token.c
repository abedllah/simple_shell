#include "simple_shell.h"

/**
 * tokenize - a function that split a string
 * @ptr_line: the parameter
 *
 * Return: a string
 */

char **tokenize(char *ptr_line)
{
    char *token = NULL;
    char **arguments = NULL;
    int pt = 0, i = 0;

    if (!ptr_line)
        return (NULL);

    token = strtok(ptr_line, " \t\n"); /* delim */

    if (token == NULL)
    {
        free(ptr_line), ptr_line = NULL;
        return (NULL);
    }

    while (token)
    {
        while (*token == ' ')
            token++;

        int len = strlen(token);
        while (len > 0 && token[len - 1] == ' ')
            token[--len] = '\0';

        pt++;
        token = strtok(NULL, "\t\n");
    }

    arguments = malloc(sizeof(char *) * (pt + 1));

    token = strtok(ptr_line, "\t\n");
    while (token)
    {
        arguments[i] = _strdup(token);
        token = strtok(NULL, "\t\n");
        i++;
    }
    free(ptr_line);
    arguments[i] = NULL;
    return (arguments);
}
