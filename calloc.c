#include "shell.h"

/**
 * _calloc - allocates memory to given array
 * @nmemb: elements number of the array
 * @size: size of bytes alloctated to individual  elements
 * Return: pointer to the allocated memory.
*/

void *_calloc(unsigned int elementCount, unsigned int size)
{
	 void *arr_alloc;
	 unsigned int index;

	if (elementCount == 0 || size == 0)
		return (NULL);
	arr_alloc = malloc(elementCount * size);
	if (!arr_alloc)
		return (NULL);
	for (index = 0; index < (elementCount * size); index++)
		((char *) (arr_alloc))[index] = 0;

	return (arr_alloc);
}
