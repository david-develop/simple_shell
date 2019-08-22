#include "header.h"

/**
 * _calloc - allocates memory for an array of n elements of certain size.
 * @nmemb: number of elements to be allocated.
 * @size: size of elements.
 * Return: Pointer to allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem_as = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem_as = malloc(nmemb * size);
	if (mem_as == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
	{
		mem_as[i] = 0;
	}
	return (mem_as);
}
