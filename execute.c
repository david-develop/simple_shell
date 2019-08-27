#include "header.h"

/**
 * exec_func - process the arguments and executes the proccesses
 * @av: array of pointers with arguments.
 * @line: string input by user
 * @env: enviroments.
 * @argv_0: first argument after tokenization
 * @e_c: error counter pointer.
 * Return: Always 0.
 */
int exec_func(char **av, char *line, char **env, err_t *errval)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(errval->argv_0);
	}
	if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			write(STDERR_FILENO, errval->argv_0, _strlen(errval->argv_0));
			write(STDERR_FILENO, ": ", 2);
			print_err_numb(errval->e_c);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": not found\n", 12);
			_freearrp(av);
			_freearrp(env);
			free(line);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
