#include "header.h"
/**
 * split_line - separate the string to a vector of arguments av.
 * @line: pointer to the string.
 * Return: pointer to the new array of string pointers.
 */
char **split_line(char *line)
{
	char delim[] = " \n";
	char *token;
	char **av;
	/*Remember coun_words to 0 for the real case*/
	int count_words = 1, count_buff = 0, i, j;

	for (i = 0; line[i]; i++)/*Count num of words to define malloc*/
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				count_words++;
		}
	}
	/*Get the 1st token*/
	token = _strtok(line, delim);
	av = _calloc(count_words, sizeof(char *));
	if (av == NULL)
		return (NULL);
	/*Get other tokens*/
	while (token != NULL)
	{
		av[count_buff] = _strdup(token);
		if (av[count_buff] == NULL)
		{
			_freearrp(av);
			return (NULL);
		}
		count_buff++;
		token = _strtok(NULL, delim);
	}
	/*Finish the **array with NULL*/
	av[count_buff] = NULL;

	return (av);
}
