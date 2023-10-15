#include "shell.h"

/**
 * _getline - gets string from stdin and stores in given buffer
 * @line: buffer for the string to be stored
 *
 * Return: number of characters read, if errrors returns (-1)
 */

ssize_t _getline(char **line)
{
	char *buff = _calloc(8096, sizeof(char));
	ssize_t charCount = 0;

	if (!buff)
		exit(EXIT_FAILURE);
	while ((read(0, &buff[charCount], 1)) > 0 && (buff[charCount] != '\n'))
		charCount++;

	if (buff[charCount] == '\n')
	{
		*line = malloc(sizeof(char) * (charCount + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		buff[charCount] = '\0';
		_strcpy(*line, buff);
		free(buff);
		return (charCount);
	}
	else if (charCount != 0)
	{
		buff[charCount] = '\0';
		*line = malloc(sizeof(char) * (charCount + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		_strcpy(*line, buff);
		free(buff);
		return (-1);
	}
	else
	{
		if (isatty(0))
			_fprintf(1, "\n", "nill", 0, "nill");
		free(buff);
		exit(status);
	}
}

