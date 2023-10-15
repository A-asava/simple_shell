#include "shell.h"

/**
 * _fputchar - prints character c to stdout
 * @fd: file descriptor
 * @c: The character to print
 *
 * Return: On success (1)
 * On error, (-1) is returned, and errno is set.
 */

int _fputchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

/**
 * _fputstr - Prints string to standard output
 * @fd: file descriptor
 * @str: string printed
 *
 * Return: Length of string printed (- 1)
 */

int _fputstr(int fd, char *str)
{
	int i;

	if (!str)
		return (_fputstr(fd, "(null)"));
	for (i = 0; str[i]; i++)
		_fputchar(fd, str[i]);

	return (i);
}

/**
 * _fputint - Prints an integer to standard output
 * @fd: file desriptor
 * @num: The number to print
 *
 * Return: Length of string printed (- 1)
 */

int _fputint(int fd, int num)
{
	int val, len = 0;

	if (!num)
	{
		len += _fputchar(fd, '0');
		return (len);
	}
	if (num == _INT_MIN)
	{
		len += _fputstr(fd, "-2147483648");
		return (len);
	}
	if (num < 0)
	{
		len += _fputchar(fd, '-');
		num = -num;
	}

	val = num % 10;
	num = num / 10;
	if (num)
		len += _fputint(fd, num);
	len += _fputchar(fd, val + '0');

	return (len);
}

/**
 * _fprintf - Prints to the standar output like regular printf
 * @fd: file descriptor
 * @formattedString: The string to be printed plus its format specifiers
 * @s1: string 1
 * @s2: string 2
 * @n1: num 1
 *
 * Return: Length of printed string
 */

int _fprintf(int fd, const char *formattedString, char *s1, int n1, char *s2)
{

	int i = 0, len = 0;

	while (formattedString[i])
	{
		if (formattedString[i] != '%')
			len += _fputchar(fd, formattedString[i]);
		else
		{
			i++;
			if (formattedString[i] == 'a')
				len += _fputstr(fd, s1);
			else if (formattedString[i] == 'b')
				len += _fputint(fd, n1);
			else if (formattedString[i] == 'c')
				len += _fputstr(fd, s2);
		}
		i++;
	}
	return (len);
}

/**
 * print_array - prints array to standard output
 * @arr: The array printed
 *
 * Return: elements number that were printed
 */

int print_array(char *arr[])
{
	int i = 0;

	while (arr[i])
	{
		_fprintf(1, "%a\n", arr[i], 0, "nill");
		i++;
	}
	return (0);
}
