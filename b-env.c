#include "header.h"

/**
 * env_f - enviroment builtin prints enviroment variables.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variable.
 * Return: 1 if executed.
 */
int env_f(char **av, char *line, char ***env)
{
	unsigned int i;
	(void) line;
	(void) av;

	i = 0;
	while ((*env)[i] != NULL)
	{
		print_string((*env)[i]);
		print_string("\n");
		i++;
	}
	return (1);
}
