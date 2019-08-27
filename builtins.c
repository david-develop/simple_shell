#include "header.h"

/**
 * non_match - return 0
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroments address.
 * Return: 0 always.
 */
int non_match(char **av, char *line, char ***env, err_t *errval)
{
	(void) av;
	(void) line;
	(void) env;
	(void) errval;

	return (0);
}
/**
 * builtins - functions that verify if builtins and execute.
 * @av_0: argument.
 * Return: value of executed functions.
 */
int (*builtins(char *av_0))(char **, char *, char ***, err_t *)
{
	built_t builts[] = {
		{"exit", exit_f},
		{"env", env_f},
		{"setenv", setenv_f},
		{"unsetenv", unsetenv_f},
		{"cd", change_dir},
		{NULL, non_match}
	};

	int i;
	int num_builts = 5;

	for (i = 0; i < num_builts; i++)
	{
		if (strcmp(av_0, builts[i].bui) == 0)
		{
			return ((builts[i].f));
		}
	}
	return (builts[num_builts].f);
}
