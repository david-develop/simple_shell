#include "header.h"

/**
 * exec_func - process the arguments and executes the proccesses
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroments.
 * @argv_0: first argument after tokenization
 * Return: Always 0.
 */
int exec_func(char **av, char *line, char **env, const char *argv_0)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv_0);
	}
	if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			perror(argv_0);
			_freearrp(av);
			_freearrp(env);
			free(line);
			exit(98);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
