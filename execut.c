#include "simple_shell.h"

<<<<<<< HEAD
int execute(char **args, char **argv) 
{
    pid_t child;
    int action;

    child = fork();
    if (child == 0)
    {
        if (execve(args[0], args, envir) == -1)
        {
            perror(argv[0]);
            freeArr(args);
        }
    }
    else
    {
        waitpid(chdir, &action, 0);
        freeArr(args);
    }
    return (WEXITSTATUS(action));
=======
int execute(char **args) {
    if (execve(args[0], args, NULL) == -1) {
        perror("Execution error");
        return -1; /* Handle execution error */
    }
    return 0; /* Successful execution */
>>>>>>> c86a95096c366423d6f85520815481d75e627e97
}
