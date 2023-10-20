#include "simple_shell.h"
#include <limits.h>
#include <unistd.h>

char *previous_directory = NULL;

/**
 * changeDirectory - Change the current working directory.
 * @path: The path to change the directory to.
 * Return: 0 on success, -1 on failure.
 */
int changeDirectory(char *path) {

    char cwd[PATH_MAX];

    if (!path || _strcmp(path, "~") == 0) {
        path = getenv("HOME");
    } else if (_strcmp(path, "-") == 0) {
        if (previous_directory) {
            path = previous_directory;
        } else {
            fprintf(stderr, "No previous directory\n");
            return -1;
        }
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return -1;
    }

    if (chdir(path) == -1) {
        perror("chdir");
        return -1;
    }

    if (setenv("PWD", getcwd(cwd, sizeof(cwd)), 1) == -1) {
        perror("setenv");
        return -1;
    }

    if (previous_directory) {
        free(previous_directory);
    }
    previous_directory = _strdup(cwd);

    return 0;
}
