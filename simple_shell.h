#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototypes
char *read_line(void);
char **tokenize(char *line);
int execute(char **args);

#endif /* SIMPLE_SHELL_H */