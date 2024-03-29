#include "header.h"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"
/**
 * read_line - read the input line from the stream.
 * @env: enviroments.
 * @errval: error data.
 * Return: pointer to the string.
 */
char *read_line(char **env, err_t *errval)
{
	char *line = NULL;
	size_t buffsz = 0;
	ssize_t verif = 1;
	char *prompt;
	char nl = '\n';

	prompt = GRN "#cisfun" RESET RED "$ " RESET;

	while (1)
	{
		write(STDIN_FILENO, prompt, _strlen(prompt));
		verif = getline(&line, &buffsz, stdin);
		if (verif == EOF || verif == -1)
		{
			write(STDIN_FILENO, &nl, 1);
			_freearrp(env);
			free(line);
			exit(errval->exit_status);
		}
		if (line == NULL || line[0] == '\n')
			continue;
		return (line);
	}
	return (NULL);
}
