#include "shell.h"

/**
 * _atoi -  the function converts a string to integers
 * @inputString: the string converte
 *
 * Return: the integer as a result
 */

int _atoi(const char *inputString)
{
	int result = 0;
	int sign = 1;
	int index = 0;

	if (inputString[0] == '-')
	{
		sign = -1;
		index++;
	}
	while (inputString[index] != '\0')
	{
		if (inputString[index] < '0' || inputString[index] > '9')
		return (-2);

		result = result * 10 + (inputString[index] - '0');
		index++;
	}
	return (sign * result);
}

