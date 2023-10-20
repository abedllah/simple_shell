#include "simple_shell.h"

/**
 * _freeArr - a function that frees an array
 * @arr: the parameter
 */


void _freeArr(char **arr) {
    int i;
    if (arr == NULL) {
        return;
    }

    for (i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
}
