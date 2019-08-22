#include "header.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - function that prints stings.
 * @s: pointer to string.
 * Return: lenght of string.
 */
int print_string(char *s)
{
	char nu[] = "(null)";
	int i, lenght;

	if (s == NULL)
	{
		for (i = 0; nu[i] != '\0'; i++)
			_putchar(nu[i]);
		return (6);
	}
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	lenght = _strlen(s);
	return (lenght);
}
