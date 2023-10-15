#include "shell.h"

/**
 * free_array - functon that frees the memory allocated to  array
 * @array: array freed
 *
 * Return: void ()
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}

