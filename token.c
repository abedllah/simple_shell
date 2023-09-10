#include "simple_shell.h"

char **tokenize(char *line) {
    char **tokens = malloc(sizeof(char *));
    char *token;
    int i = 0;

    if (!tokens) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \n");
    while (token != NULL) {
        tokens[i] = strdup(token);
        if (!tokens[i]) {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }
        i++;
        tokens = realloc(tokens, (i + 1) * sizeof(char *));
        if (!tokens) {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \n");
    }
    tokens[i] = NULL;

    return tokens;
}
