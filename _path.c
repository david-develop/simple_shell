#include "header.h"
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
	tokens = _calloc((count_words + 1), sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (token != NULL)/*Get other tokens*/
	{
		tokens[count_buff] = _strdup(token);
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
	unsigned int i;
	char delim[] = "=", **tokens;
	char *token, *cp_tok, *cp_env, *string_to_split, *mix_direx, *aux_ex;
	struct stat st;

	if (vect[0][0] == '/' || (vect[0][0] == '.' && vect[0][1] == '/'))
		return (vect);
	for (i = 0; env[i] != NULL; i++)
	{
		cp_env = _strdup(env[i]);
		token = _strtok(cp_env, delim);
		cp_tok = _strdup(token);
		if (_strcmp(cp_tok, "PATH") == 0)/*PILAS strcmp*/
		{
			free(cp_tok), free(cp_env);
			break; }
		free(cp_tok), free(cp_env);
	}
	if (_strchr(env[i], '/'))/*PILAS*/
	{
		if (env[i][5] == ':')
			return (vect);
		string_to_split = _strdup(_strchr(env[i], '/')); }
	else
		return (vect);
	tokens = tokenizer(string_to_split, ":");
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
	free(aux_ex), free(string_to_split), _freearrp(tokens);
	return (vect);
}
