#include "header.h"
#define PATH_MAX 4096

/**
 * setenv_cd - Initialize a new environment variable, or modify an existing one
 * @name_var: variable name.
 * @cont_var: variable value.
 * @env: enviroment variables.
 * Return: pointer to the new enviroment data struct.
 */

char **setenv_cd(char *name_var, char *cont_var, char **env)
{
	int verif, i, j;
	char delim[] = "=";
	char *mod_env, *aux, *new_evar;
	char **new_env;

	verif = findenv(env, name_var);
	if (verif == -1)
	{

		for (i = 0; env[i] != NULL; i++) /*count index*/
			;
		aux = str_concat("=", cont_var);
		new_evar = str_concat(name_var, aux);
		new_env = malloc((i + 2) * sizeof(char *));/*Re-allocate for new variable*/
		if (new_env == NULL)
		{
			print_string("cpy env failed");/*check errors*/
			free(aux);
			free(new_evar);
			return (NULL);
		}
		for (j = 0; j < i; j++)/*Filling the new_env*/
			new_env[j] = _strdup(env[j]);
		new_env[j] = new_evar;
		new_env[j + 1] = NULL;
		free(aux);
		_freearrp(env);
		return (new_env);
	}
	else
	{
		aux = str_concat(delim, cont_var);
		mod_env = str_concat(name_var, aux);
		free(env[verif]);
		env[verif] = mod_env;
		free(aux);
		return (env);
	}
}
/**
 * change_dir - change directory
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviromental variables
 * @errval: error print data.
 * Return: 1 if function executed.
 */
int change_dir(char **av, char *line, char ***env, err_t *errval)
{
	char *directory, *old_pwd, *dir_ptr, *buf;
	int i, verif;
	(void) line;

	if (!av[1])/*cd or HOME*/
	{
		i = findenv(*env, "HOME");
		if (i == -1)
		{
			print_string("coudn't find variable");
			return (1);
		}
		directory = _strchr((*env)[i], '/');/*The new PWD*/
		if (directory == NULL)
		{
			print_string("coudn't find dir");
			return (1);
		}
		buf = malloc(PATH_MAX * sizeof(char));/*Change env var manually*/
		if (buf != NULL)
			dir_ptr = getcwd(buf, PATH_MAX);
		old_pwd = dir_ptr;
		chdir(directory);
		*env = setenv_cd("OLDPWD", old_pwd, *env);
		*env = setenv_cd("PWD", directory, *env);
		free(buf);
	}
	else if (strcmp(av[1], "-") == 0)/*cd - */
	{
		i = findenv(*env, "OLDPWD");
		if (i == -1)
		{
			print_string("coudn't find variable");
			return (1);
		}
		directory = _strdup(_strchr((*env)[i], '/'));
		if (directory == NULL)
		{
			print_string("coudn't find dir");
			return (1);
		}
		buf = malloc(PATH_MAX * sizeof(char));/*Change env var manually*/
		if (buf != NULL)
			dir_ptr = getcwd(buf, PATH_MAX);
		old_pwd = dir_ptr;
		chdir(directory);
		*env = setenv_cd("OLDPWD", old_pwd, *env);
		*env = setenv_cd("PWD", directory, *env);
		print_string(directory), print_string("\n");
		free(buf);
		free(directory);
	}
	else
	{
		verif = chdir(av[1]);
		if (verif == -1)
		{
			write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
			write(STDERR_FILENO, ": ", 2);
			print_err_numb(errval->e_c);
			write(STDERR_FILENO, ": cd: can't cd to ", 18);
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1);
		}
		buf = malloc(PATH_MAX * sizeof(char));/*Change env var manually*/
		if (buf != NULL)
			dir_ptr = getcwd(buf, PATH_MAX);
		old_pwd = dir_ptr;
		chdir(av[1]);
		*env = setenv_cd("OLDPWD", old_pwd, *env);
		*env = setenv_cd("PWD", getcwd(buf, PATH_MAX), *env);
		free(buf);
	}
	return (1);
}
