#include "header.h"

/**
 * env_f - enviroment builtin prints enviroment variables.
 * @av: array of pointers with arguments.
 * @line: string input by user
 */
void env_f(char **av, char *line)
{
	unsigned int i;
	(void) line;
	(void) av;

	i = 0;
	while (environ[i] != NULL)
	{
		print_string(environ[i]);
		print_string("\n");
		i++;
	}
}
