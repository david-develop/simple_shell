#include "header.h"
/**
 * main - super simple shell.
 * @argc: arguments counter.
 * @argv: arguments vector.
 * @env: enviromental variables vector.
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char **av;
	int status = 1;
	int chk_build = 0;
	(void)argc;

	while (status)
	{
		line = read_line();
		av = split_line(line);
		if (av == NULL)
		{
			free(line);
			exit(98);
		}
		chk_build = builtins(av, line);
		if (chk_build == 1)
		{
			chk_build = 0;
			free(line);
			_freearrp(av);
			continue;
		}
		av = path_exp(av, env);
		status = exec_func(av, line, argv[0]);

		free(line);
		_freearrp(av);
	}
	return (0);
}
