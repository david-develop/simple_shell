#include "header.h"

/**
 * _cpyarrp - create a copy of char data structure
 * @arrp: input data structure.
 * Return: pointer to created data struct.
 */
char **new_envmod(char **av, char **env)
{
	int i, j;
	char **new_env;
	char *new_evar, *aux;

	/*count index*/
	for (i = 0; env[i] != NULL; i++)
		;
	/*create new variable*/
	aux = str_concat("=", av[2]);
	new_evar = str_concat(av[1], aux);

	new_env = malloc((i + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		print_string("cpy env failed");/*check errors*/
		free(aux);
		free(new_evar);
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		new_env[j] = _strdup(env[j]);
	}
	print_string(new_evar);/*just for trial*/
	print_string("\n");/*just for trial*/
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
 */
int unsetenv_f(char **av, char *line, char ***env)
{
	int verif;
	char delim[] = "=";
	char *token, *mod_env, *aux;
	(void) line;

	if (av[1] == NULL || av[2] == NULL || av[3])
	{
		perror("setevn: illegal number of argument"); /* MODIFICAR PARA STDERR*/
		return (1);
	}
	verif = findenv((*env), av[1]);
	if (verif == -1)
	{
		print_string("variable not found\n");
		/* *env = new_env(av, (*env));*/
		return (1);
	}
	else
	{
		token = _strtok((*env)[verif], delim);
		aux = str_concat(delim, av[2]);
		mod_env = str_concat(token, aux);
		print_string(mod_env);
		print_string("\n");
		free((*env)[verif]);
		(*env)[verif] = mod_env;
		free(aux);
		return (1);
	}
}
