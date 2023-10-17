#include "shell.h"

/**
 * find_command_path - searches through directories to find given command
 *
 * Return: path to the command if found, else NULL
 */

char *find_command_path(void)
{
	int index = 0;
	char *path_var = _getenv("PATH");
	char **path_dir, *cmd_path;

	if (access(command[0], F_OK) == 0)
		return (_strdup(command[0]));
	if (!path_var)
		return (NULL);
	path_dir = _strtok(path_var, ':');
	for (index = 0; path_dir[index]; index++)
	{
		cmd_path = malloc(1024);
		_strcpy(cmd_path, path_dir[index]);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, command[0]);

		if (access(cmd_path, F_OK) == 0)
		{
			free_array(path_dir);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_array(path_dir);
	return (NULL);
}
