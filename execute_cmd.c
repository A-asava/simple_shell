#include "shell.h"

/**
 * execute_command_path -  a func to execute a given command
 *
 * Return: status of comman executed
 */

int execute_command_path(void)
{
	char *commandpath;
	pid_t child_pid;
	int exitstatus;

	if (command[0] && builtin_func())
	{
		commandpath = find_command_path();
		if (commandpath)
		{
			child_pid = fork();
			if (child_pid == -1)
				return (0);
			else if (child_pid == 0)
			{
				execve(commandpath, command, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(child_pid, &exitstatus, 0);
				if (WIFEXITED(exit_status))
					status = WEXITSTATUS(exitstatus);
			}
		}
		else
		{
			_fprintf(2, "%a: %b: %c: not found\n", shell, shell_count, command[0]);
			return (127);
		}
		free(commandpath);
	}
	return (status);
}
