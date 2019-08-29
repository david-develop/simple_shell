#include "header.h"

/**
 * new_envmod - create a copy of char data structure modified
 * @env: enviroments variables.
 * @idx: index of variable to delete.
 * Return: pointer to new created data struct.
 */
char **new_envmod(char **env, int idx)
{
	int i, j;
	char **new_env;

	/*count index*/
	for (i = 0; env[i] != NULL; i++)
		;

	new_env = malloc(i * sizeof(char *));
	if (new_env == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < idx; j++)
		new_env[j] = _strdup(env[j]);
	for (; j < (i - 1); j++)
		new_env[j] = _strdup(env[j + 1]);
	new_env[j] = NULL;
	_freearrp(env);
	return (new_env);
}

/**
 * unsetenv_f - remove existing variable.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variables.
 * @errval: error print data.
 * Return: 1 if executed.
 */
int unsetenv_f(char **av, char *line, char ***env, err_t *errval)
{
	int verif;
	(void) line;

	if (av[1] == NULL || av[2])
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": wrong sintax\n", 15);
		errval->exit_status = 2;
		return (1);
	}
	verif = findenv((*env), av[1]);
	if (verif == -1)
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, av[1], _strlen(av[1]));
		write(STDERR_FILENO, ": nonexistent variable\n", 23);
		errval->exit_status = 2;
		return (1);
	}
	else
	{
		*env = new_envmod((*env), verif);
		errval->exit_status = 0;
		return (1);
	}
}
