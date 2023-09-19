#include "simple_shell.h"

char **tokenize(char *line)
{
    char *token = NULL;
    char **argv = NULL;
    int cpt = 0, i = 0;

    if (!line)
        return NULL;

    token = strtok(line, " \t\n"); /* delim */

    if (token == NULL)
    {
        free(line), line = NULL;
        return NULL;
    }

    while (token)
    {
        cpt++;
        token = strtok(NULL, "\t\n");
    }

    argv = malloc(sizeof(char *) * (cpt + 1));

    token = strtok(line, "\t\n");
    while (token)
    {
        argv[i] = strdup(token);
        token = strtok(NULL, "\t\n");
        i++;
    }
    free(line);
    argv[i] = NULL;
    return (argv);
}