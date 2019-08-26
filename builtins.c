#include "header.h"

/**
 * non_match - return 0
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroments address.
 * Return: 0 always.
 */
int non_match(char **av, char *line, char ***env)
{
	(void) av;
	(void) line;
	(void) env;

	return (0);
}
/**
 * builtins - functions that verify if builtins and execute.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * Return: 1 if builtint executed, 0 if not.
 */
int (*builtins(char *av_0))(char **, char *, char ***)
{
	built_t builts[] = {
		{"exit", exit_f},
		{"env", env_f},
		{"setenv", setenv_f},
		{"unsetenv", unsetenv_f},
		{NULL, non_match}
	};

	int i;
	int num_builts = 4;

	for (i = 0; i < num_builts; i++)
	{
		if (strcmp(av_0, builts[i].bui) == 0)
		{
			return((builts[i].f));
		}
	}
	return (builts[num_builts].f);
}
