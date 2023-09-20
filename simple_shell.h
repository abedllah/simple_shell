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
char **tokenize(char *ptr_line);
int execute(char **args);

void _freeArr(char **arr);

int _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *str);

#endif
