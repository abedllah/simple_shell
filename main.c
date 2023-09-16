#include "simple_shell.h"

/**
 * main file
 * argv
 * return 0
*/

int main(char **argv) 
{
    char *line=NULL;
    char **args=NULL;
    int action = 0;

    while (1) 
    {
        write(STDOUT_FILENO, "$ ", 2);
        line = read_line();
<<<<<<< HEAD
        if (line == NULL) 
        {
            if (isatty(STDIN_FILENO,))
                write(STDOUT_FILENO, "\n", 1);
            return(action); 
        }


        args = tokenize(line);
        if (!args) {
            continue;
        }
        
        action = execut(args, argv)
=======
        if (line == NULL) {
            break; /* End of file (Ctrl+D) */
        }
        args = tokenize(line);
        if (args != NULL && args[0] != NULL) {
            execute(args);
        }

        /* Cleanup */
        free(line);
        free(args);
>>>>>>> c86a95096c366423d6f85520815481d75e627e97
    }

    //return EXIT_SUCCESS;
}
