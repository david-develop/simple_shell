#include "header.h"
/**
 * exit_f - exit builtin
 * @av: array of pointers with arguments.
 * @line: string input by user
 */
int change_dir(char **av, char *line, char ***env)
{
	char *directory;
	(void) line;
	(void) env;

	if (!av[1])/*cd*/
	{
		directory = getenv("HOME");
		chdir(directory);
	}
	else if (strcmp(av[1], "-") == 0)/*cd - */
	{
		directory = getenv("OLDPWD");
		chdir(directory);
	}
	else
		chdir(av[1]);
	return (0);
}
