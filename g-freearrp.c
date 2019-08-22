#include "header.h"
/**
 * _freearrp - frees completely and array of pointers.
 * @av: array of pointers
 * Return: Always 0.
 */
void _freearrp(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		free(av[i]);
	}
	free(av[i]);
	free(av);
}
