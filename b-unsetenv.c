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
		print_string("cpy env failed");/*check errors*/
		return (NULL);
	}
	for (j = 0; j < idx; j++)
		new_env[j] = _strdup(env[j]);
	for (; j < (i - 1); j++)
		new_env[j] = _strdup(env[j + 1]);
	new_env[j] = NULL;
	print_string(env[idx]);/*just for trial*/
	print_string(" -> deleted\n");/*just for trial*/
	_freearrp(env);
	return (new_env);
}

/**
 * unsetenv_f - remove existing variable.
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variables.
 * Return: 1 if executed.
 */
int unsetenv_f(char **av, char *line, char ***env)
{
	int verif;
	(void) line;

	if (av[1] == NULL || av[2])
	{
		perror("setevn: illegal number of argument"); /* MODIFICAR PARA STDERR*/
		return (1);
	}
	verif = findenv((*env), av[1]);
	if (verif == -1)
	{
		print_string("variable not found\n");
		/**env = new_env(av, (*env));*/
		return (1);
	}
	else
	{
		*env = new_envmod((*env), verif);
		return (1);
	}
}
