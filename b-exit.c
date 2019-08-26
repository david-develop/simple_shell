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
int _atoi(char *s)
{
	unsigned int res = 0, sing = 1, i, si;

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
 */
int exit_f(char **av, char *line, char ***env)
{
	int i;
	int sta_n;
	(void) env;

	if (av[1])
	{
		for (i = 0; av[1][i]; i++)
		{
			if (!(_isdigit(av[1][i])))
			{
				/*revisar errors*/
				perror("error: exit ilegal status");
				return (1);
			}
		}
		sta_n = _atoi(av[1]);
		free(line);
		_freearrp(av);
		_freearrp(*env);
		exit(sta_n);
	}
	free(line);
	_freearrp(av);
	_freearrp(*env);
	exit(0);
}
