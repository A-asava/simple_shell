#include "shell.h"

/**
 * _strtok - converts a string to an aray based on a given delimiter
 * @str: the string converted to array
 * @delim: the delimiter used
 *
 * Return: array of tokenized string, else NULL
 */

char **_strtok(char *str, char delim)
{
	int t = 0, c = 0, b = 0;
	int len = _strlen(str);
	char **array = (char **)malloc(sizeof(char *) * (len + 1));
	char *buff = (char *)malloc(sizeof(char) * (len + 1));


	for (; c < len + 1; c++)
	{
		if (str[c] != delim && str[c] != '\0')
		{
			buff[b] = str[c];
			b++;
		}
		else
		{
			if (b > 0)
			{
				buff[b] = '\0';
				array[t] = malloc(sizeof(char) * (b + 1));
				_strcpy(array[t], buff);
				t++;
				b = 0;
			}
		}
	}
	array[t] = NULL;
	free(buff);
	return (array);
}
/**
 * _strncmp - compares two strings until the  n char
 * @str1: first string to be compared with
 * @str2: second string compared with first string
 * @n: number of string compared
 * Return: (0) if equal, positive if (s1 < s2), negative if (s1 > s2)
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);

		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

