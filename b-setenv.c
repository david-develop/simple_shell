#include "header.h"

/**
 * new_env - create a new enviroment with the given parameters.
 * @av: input arguments.
 * @env: enviroments.
 * Return: pointer to created data struct.
 */
char **new_env(char **av, char **env)
{
	int i, j;
	char **new_env;
	char *new_evar, *aux;

	for (i = 0; env[i] != NULL; i++)
		;
	aux = str_concat("=", av[2]);
	new_evar = str_concat(av[1], aux);

	new_env = malloc((i + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		free(aux);
		free(new_evar);
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		new_env[j] = _strdup(env[j]);
	}
	new_env[j] = new_evar;
	new_env[j + 1] = NULL;
	free(aux);
	_freearrp(env);
	return (new_env);
}

/**
 * setenv_f - Initialize a new environment variable, or modify an existing one
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variables.
 * @errval: error print data.
 * Return: 1 if executed.
 */
int setenv_f(char **av, char *line, char ***env, err_t *errval)
{
	int verif;
	char delim[] = "=";
	char *token, *mod_env, *aux;
	(void) line;

	if (av[1] == NULL || av[2] == NULL || av[3])
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": wrong sintax\n", 15);
		return (1);
	}
	verif = findenv((*env), av[1]);
	if (verif == -1)
	{
		*env = new_env(av, (*env));
		return (1);
	}
	else
	{
		token = _strtok((*env)[verif], delim);
		aux = str_concat(delim, av[2]);
		mod_env = str_concat(token, aux);
		free((*env)[verif]);
		(*env)[verif] = mod_env;
		free(aux);
		return (1);
	}
}
