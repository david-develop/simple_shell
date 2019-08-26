#include "header.h"

/**
 * env_f - enviroment builtin prints enviroment variables.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variable.
 * @e_c: error counter pointer.
 * Return: 1 if executed.
 */
int env_f(char **av, char *line, char ***env, err_t *errval)
{
	unsigned int i;
	(void) line;
	(void) av;
	(void) errval;

	i = 0;
	while ((*env)[i] != NULL)
	{
		print_string((*env)[i]);
		print_string("\n");
		i++;
	}
	return (1);
}
