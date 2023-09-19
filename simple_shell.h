#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **envir;

char *read_line(void);
char **tokenize(char *line);
int execute(char **args);

void freeArr(char **arr);

int my_strlen(const char *str);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);
char *strdup(const char *str);

#endif
