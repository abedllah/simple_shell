#include "simple_shell.h"

/**
 * executeEnv - Execute the env built-in command
 */
void executeEnv(void)
{
    char **env = envir;
    while (*env)
    {
        write(STDOUT_FILENO, *env, _strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
        env++;
    }
}
