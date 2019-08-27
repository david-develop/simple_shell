#include "header.h"

char *check_path_mod(char *path_val, char *vect_0)
{
	int i, j, len;
	char *mod_path = NULL;
	struct stat st;

	if (path_val[0] == ':' && (stat(vect_0, &st) == 0))
	{
		free(path_val);
		return (NULL);
	}
	for (i = 0; path_val[i] != '\0'; i++)
	{
		if (path_val[i] == ':' && path_val[i + 1] == ':')
			break;
	}
	len = _strlen(path_val);
	if (i == len)
		return (path_val);
	mod_path = malloc((len + 2) * sizeof(char));
	for (j = 0; j <= i; j++)
	{
		mod_path[j] = path_val[j];
	}
	mod_path[j] = '.';
	for (j++; j <= len; j++)
	{
		mod_path[j] = path_val[j - 1];
	}
	mod_path[j] = '\0';
	free(path_val);
	return (mod_path);
}

/**
 * tokenizer - split a string.
 * @string_to_split: string to be splited.
 * @delim: delimiter to separate the string.
 * Return: Always 0.
 */
char **tokenizer(char *string_to_split, char *delim)
{
	int i, j;
	int count_words = 1, count_buff = 0;
	char **tokens;
	char *token;


	for (i = 0; string_to_split[i]; i++)/*Count num of words to define malloc*/
		for (j = 0; delim[j]; j++)
			if (string_to_split[i] == delim[j])
				count_words++;
	token = _strtok(string_to_split, delim);	/*Get the 1st token*/
	tokens = calloc((count_words + 1), sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (token != NULL)/*Get other tokens*/
	{
		tokens[count_buff] = strdup(token);
		if (tokens[count_buff] == NULL)
		{
			_freearrp(tokens);
			return (NULL);
		}
		count_buff++;
		token = _strtok(NULL, delim);
	}
	tokens[count_buff] = NULL;/*Finish the **array with NULL*/
	return (tokens);
}

/**
 * path_exp - prints the environment
 * @vect: array of arguments
 * @env: enviromental variables in an array of pointers
 * Return: Always 0.
 */
char **path_exp(char **vect, char **env)
{
	int i;
	char *path_values, *aux_ex, *mix_direx;
	char **tokens;
	struct stat st;

	i = findenv(env, "PATH");
	if (i == -1)
		return (vect);
	if (vect[0][0] == '/' || (vect[0][0] == '.' && vect[0][1] == '/'))
		return (vect);
	path_values = _strdup(_strchr(env[i], '=') + 1);
	path_values = check_path_mod(path_values, vect[0]);
	if (path_values == NULL)
	{
		return (vect);
	}
	tokens = tokenizer(path_values, ":");
	aux_ex = str_concat("/", vect[0]);/*PILAS*/
	for (i = 0; tokens[i]; i++)
	{
		mix_direx = str_concat(tokens[i], aux_ex);
		if (stat(mix_direx, &st) == 0)
		{
			free(vect[0]);
			vect[0] = mix_direx;
			break;
		}
		free(mix_direx);
	}
	free(aux_ex), free(path_values), _freearrp(tokens);
	return (vect);
}
