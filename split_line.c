#include "header.h"
/**
 * change_to_space - change delims to spaces.
 * @line: given string.
 */
void change_to_space(char *line)
{
	int del, li;
	char delim[] = "\n\t\r\a";

	for (del = 0; delim[del] != '\0'; del++)
	{
		for (li = 0; line[li] != '\0'; li++)
			if (delim[del] == line[li])
				line[li] = ' ';
	}
}
/**
 * cwords - count number of words in a given string.
 * @str: given string.
 * @l: lenght of string.
 * Return: number of words.
 */
int cwords(char *str, int l)
{
	int i, count_w = 0;

	for (i = 0; i < l; i++)
	{
		if (str[i] != ' ')
		{
			for (; str[i] != ' '; i++)
				;
			count_w++;
		}
	}
	return (count_w);
}

/**
 * split_line - separate the string to a vector of arguments av.
 * @line: pointer to the string.
 * Return: pointer to the new array of string pointers.
 */
char **split_line(char *line)
{
	char **p;
	int count_w = 0, count_c = 0, i, leng, x = 0, fr, j = 0, z = 0;

	if (line == NULL || *line == '\0')
		return (NULL);
	change_to_space(line);
	leng = _strlen(line);
	count_w = cwords(line, leng);
	p = malloc((count_w + 1) * sizeof(char *));
	if (p == NULL || count_w == 0)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < leng; i++)
	{
		if (line[i] != ' ')
		{
			z = 1;
			for (count_c = 0; line[i] != ' ' && line[i] != '\0'; i++)
				count_c++;
			p[x] = malloc((count_c + 1) * sizeof(char));
			if (p[x] == NULL)
			{
				for (fr = 0; fr <= x; fr++)
					free(p[fr]);
				free(p);
				return (NULL);
			}
			for (j = 0; j < count_c; j++)
				p[x][j] = line[(i - count_c) + j];
			p[x][j] = '\0';
			x++;
		}
	}
	if (z != 1)
		return (NULL);
	p[x] = NULL;
	return (p);
}
