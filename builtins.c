#include "header.h"

/**
 * builtins - functions that verify if builtins and execute.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * Return: 1 if builtint executed, 0 if not.
 */
int builtins(char **av, char *line, char **env)
{
	built_t builts[] = {
		{"exit", exit_f},
		{"env", env_f},
		/*{"setenv", setenv_f},
		{"unsetenv", unsetenv_f},*/
		{NULL, NULL}
	};

	int i;

	for (i = 0; builts[i].bui != NULL; i++)
	{
		if (strcmp(av[0], builts[i].bui) == 0)
		{
			builts[i].f(av, line, &env);
			return (1);
		}
	}
	return (0);
}
