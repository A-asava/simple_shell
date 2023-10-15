#include "shell.h"

/**
 * exit_shell - exits the shell, displays status
 * @exit_status: status displayed
 *
 * Return: exits shell or else return (2)
 */
int exit_shell(char *exit_status)
{
	if (!exit_status)
	{
		free(line);
		free_array(command);
		exit(status);
	}
	status = _atoi(exit_status);
	if (status >= 0)
	{
		free(line);
		free_array(command);
		exit(status);
	}
	_fprintf(2, "%a: %b: exit: ", shell, shell_count, "nill");
	_fprintf(2, "Illegal number: %a\n", exit_status, 0, "nill");
	return (2);
}

