#include "header.h"

/**
 * _isdigit - Verify if variable is a digit from 0 to 9
 * @c: variable for value input.
 * Return: when input is a digit return 1.
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - function that convert to integrer.
 * @s: input string.
 *
 * Return: integrer.
 */
long long int _atoi(char *s)
{
	long long int res = 0, sing = 1, i, si;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			break;
		}
		if (s[i] == '-')
		{
			sing = -sing;
		}
	}
	for (si = i; s[si] != '\0'; ++si)
	{
		if (s[si] >= '0' && s[si] <= '9')
		{
			res = res * 10 + s[si] - '0';
		}
		else
		{
			break;
		}
	}
	return (sing * res);
}

/**
 * exit_f - exit builtin
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroment variables data struct.
 * @errval: error print values.
 * Return: 1 if executed.
 */
int exit_f(char **av, char *line, char ***env, err_t *errval)
{
	int i;
	long long int sta_n;
	(void) env;
	(void) errval;

	if (av[1])
	{
		for (i = 0; av[1][i]; i++)
		{
			if (!(_isdigit(av[1][i])))
			{
				write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
				write(STDERR_FILENO, ": ", 2);
				print_err_numb(errval->e_c);
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, av[0], _strlen(av[0]));
				write(STDERR_FILENO, ": Illegal number: ", 18);
				write(STDERR_FILENO, av[1], _strlen(av[1]));
				write(STDERR_FILENO, "\n", 1);
				return (1);
			}
		}
		sta_n = _atoi(av[1]);
		if (sta_n < 0 || sta_n >= 2147483647 || _strlen(av[1]) > 10)
		{
			write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
			write(STDERR_FILENO, ": ", 2);
			print_err_numb(errval->e_c);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1);
			return (1);
		}
		free(line), _freearrp(av), _freearrp(*env);
		exit(sta_n);
	}
	free(line), _freearrp(av), _freearrp(*env);
	exit(0);
}
