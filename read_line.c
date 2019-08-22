#include "header.h"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"
/**
 * read_line - read the input line from the stream.
 * Return: pointer to the string.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffsz = 0;
	ssize_t verif = 1;
	char *prompt;

	prompt = GRN "mini-shell--" RESET RED "$ " RESET;

	while (verif != -1)
	{
		write(STDIN_FILENO, prompt, _strlen(prompt));
		verif = getline(&line, &buffsz, stdin);
		if (verif == -1)
		{
/*			print_string("\n");*/
			free(line);
			exit(0);
		}
		if (line[0] == '\n')
			continue;
		return (line);
	}
	print_string("\n");
	free(line);
	exit(98);
}
