#include "shell.h"

/**
 * display_prompt - prints the prompt sign to standard output
 * @prompt_sign: prompt sign that is printed
 *
 * Return: (0) in interactive mode and (1) in non interactive mode
 */


int display_prompt(char *prompt_sign)
{
	if (isatty(0))
		_fputstr(1, prompt_sign);

	return (0);
}
