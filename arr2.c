#include "simple_shell.h"

/**
 * _freeArr - a function that frees an array
 * @arr: the parameter
 */


void _freeArr(char **arr)
{
	int index;

	if (!arr)
		return;

	for (index = 0; arr[index]; index++)
	{
		free(arr[index]);
		arr[index] = NULL;
	}

	free(arr);
	arr = NULL;
}
