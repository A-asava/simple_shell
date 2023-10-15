#include "shell.h"
#include <stdio.h>

/**
 *main - main function, stipulates entry into the shell
 *@argc: argument count
 *@argv: argument vector
 *Return: on success (0)
 */

int main(int argc, char *argv[])
{
	int shellStatus;

	shell_count = 0;
	shell = argv[0];
	shellStatus = 0;

	(void)argc;
	while (++shell_count)
	{
		display_prompt("#cisfun$ ");
		_getline(&line);
		command = _strtok(line, ' ');
		shellStatus = execute_command_path();
		free(line);
		free_array(command);
	}
	return (shellStatus);
}
