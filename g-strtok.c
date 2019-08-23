#include <header.h>
/**
 * _strspn - Write a function that gets the length of a prefix substring
 * @s: input string.
 * @accept: character to be compared.
 * Return: number of bytes.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0, count = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				count++;
		}
		if (count == 0)
			return (i);
	}
	return (i);
}
/**
 * _strcspn - Write a function that gets the number the characters until the ocurrence
 * @s: input string.
 * @reject: character to be compared.
 * Return: number of char.
 */
unsigned int _strcspn(char *s, char *reject)
{
	unsigned int i, j = 0;

	for (i = 0; s[i] != '\0'; i++)
		for (j = 0; reject[j] != '\0'; j++)
			if(s[i] == reject[j])
				return (i);
	return (i);
}
/**
 * _strtok_r - gets the token from a given pointer
 * @s: input string.
 * @delim: the delimiter
 * @save_ptr: previous saved pointer.
 * Return: pointer to extracted token.
 */
char *_strtok_r (char *s, char *delim, char **save_ptr)
{
	char *end;
	unsigned int n;
	/*2nd or more call case*/
	if (s == NULL)
		s = *save_ptr;
	/*General case to finish the function*/
	if (*s == '\0')
	{
		*save_ptr = s;
		return NULL;
	}

	/*Locate the pointer s at the beginning of token*/
	n = _strspn(s, delim);
	if (n > 0)
		s = s + n;
	if (*s == '\0')
	{
		*save_ptr = s;
		return NULL;
	}

	/*Locate the last character of token*/
	n = _strcspn(s, delim);
	if (n > 0)
		end = s + n;
	if (*end == '\0')
	{
		*save_ptr = end;
		return s;
	}

	/*Once get the token, change the delim character by null and save the*/
	/*beggining of the new token*/
	*end = '\0';
	*save_ptr = end + 1;
	return s;
}
/**
 * _strtok - gets the token of a given string
 * @s: input string.
 * @delim: the delimiter
 * Return: pointer to extracted token.
 */
char *_strtok (char *s, char *delim)
{
	static char *saved_ptr;
	return _strtok_r (s, delim, &saved_ptr);
}
