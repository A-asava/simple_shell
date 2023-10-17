#include "shell.h"

/**
 * builtin_func - Handles builtin commands such as exit, env and cd
 *
 * Return: (0) for success, else (shellStatus)
 */

int builtin_func(void)
{
	if (!command[0])
		return (0);
	if (!_strcmp(command[0], "exit"))
	{
		status = exit_shell(command[1]);
		return (0);
	}
	if (!_strcmp(command[0], "env"))
	{
		printout_array(environ);
		return (0);
	}
	return (-1);
}
