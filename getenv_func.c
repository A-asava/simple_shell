#include "shell.h"

/**
 * _getenv - sources an environment variable name then returns it's value
 * @variableName: The variable name sourced
 *
 * Return: pointer to variable's value
 */

char *_getenv(char *variableName)
{
	int i;
	char *path = NULL;
	size_t var_len = _strlen(variableName);

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(environ[i], variableName, var_len))
			if (environ[i][var_len] == '=')
		{
			path = environ[i] + var_len + 1;
			return (path);
		}
	}
	return (path);
}
