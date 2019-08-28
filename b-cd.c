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
 * print_err - print errors of cd.
 * @errval: error print data.
 * @ca: case number.
 * @av_1: argument.
 */
void print_err(err_t *errval, int ca, char *av_1)
{
	if (ca == 0)
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": cd: can't cd to ", 18);
		write(STDERR_FILENO, av_1, _strlen(av_1));
		write(STDERR_FILENO, "\n", 1);
		errval->exit_status = 2;
	}
	else if (ca == 1)
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": cd: HOME variable doesn't exist ", 34);
		write(STDERR_FILENO, "or its path is empty\n", 21);
		errval->exit_status = 2;
	}
	else if (ca == 2)
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": cd: OLDPWD variable doesn't ", 30);
		write(STDERR_FILENO, "exist or its path is empty\n", 27);
		errval->exit_status = 2;
	}
	else if (ca == 3)
	{
		write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
		write(STDERR_FILENO, ": ", 2);
		print_err_numb(errval->e_c);
		write(STDERR_FILENO, ": cd: error malloc", 18);
		errval->exit_status = 2;
	}
}
/**
 * check_env_val - checks for variable existance and errors.
 * @av: array of pointers with arguments.
 * @env: enviromental variables
 * @errval: error print data.
 * @e_nam: enviroment name;
 * Return: variable index or -1 if error.
 */
int check_env_val(char **av, char **env, err_t *errval, char *e_nam)
{
	char *directory;
	int i, c = 0;

	if (_strcmp(e_nam, "HOME"))
		c = 2;
	if (_strcmp(e_nam, "OLDPWD"))
		c = 1;
	i = findenv(env, e_nam);
	if (i == -1)
	{
		print_err(errval, c, av[1]);
		return (-1);
	}
	directory = _strdup(_strchr(env[i], '/'));
	if (directory == NULL)
	{
		print_err(errval, c, av[1]);
		return (-1);
	}
	free(directory);
	return (i);
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
	char *directory, *old_pwd,  *buf;
	int i, verif;
	(void) line;

	buf = malloc(PATH_MAX * sizeof(char));
	if (buf == NULL)
		return (1);
	if (!av[1])/*cd or HOME*/
	{ i = check_env_val(av, *env, errval, "HOME");
		if (i != -1)
		{ directory = _strdup(_strchr((*env)[i], '/'));
			if (directory == NULL)
			{ print_err(errval, 1, av[1]);
				return (1); }
			old_pwd = getcwd(buf, PATH_MAX), chdir(directory);
			*env = setenv_cd("OLDPWD", old_pwd, *env);
			*env = setenv_cd("PWD", directory, *env);
			free(directory); } }
	else if (_strcmp(av[1], "-") == 0)/*cd - */
	{ i = check_env_val(av, *env, errval, "OLDPWD");
		if (i != -1)
		{ directory = _strdup(_strchr((*env)[i], '/'));
			if (directory == NULL)
			{
				print_err(errval, 2, av[1]);
				return (1); }
			old_pwd = getcwd(buf, PATH_MAX), chdir(directory);
			*env = setenv_cd("OLDPWD", old_pwd, *env);
			*env = setenv_cd("PWD", directory, *env);
			print_string(directory), print_string("\n");
			free(directory); } }
	else if (av[1])
	{ old_pwd = getcwd(buf, PATH_MAX), verif = chdir(av[1]);
		if (verif == -1)
			print_err(errval, 0, av[1]);
		*env = setenv_cd("OLDPWD", old_pwd, *env);
		*env = setenv_cd("PWD", getcwd(buf, PATH_MAX), *env); }
	free(buf);
	return (1);
}
