#include "header.h"
#define BUFSIZE 1024

/**
 * get_line - custom delimited string input
 *
 * Return: On  success, return the number of characters read, including the
 * delimiter character. return -1 on failure to read a line (including
 * end-of-file condition).
 */

ssize_t _getline(char **line, size_t *buffsz, FILE *stream)
{
	int i = 0;
	char ch[1];
	ssize_t buf_sz, old_buf_sz;
	ssize_t bch_sz = 1;
	(void) stream;

	if (*buffsz != 0)
	{
		buf_sz = *buffsz;
	}
	else
		buf_sz = BUFSIZE;

	if (*line == NULL)
		*line = malloc(buf_sz * sizeof(char));

	while (1)
	{
		bch_sz = read(STDIN_FILENO, ch, bch_sz);
		if (bch_sz == -1)
			return (-1);
		if (ch[0] == EOF)
		{
			(*line)[i] = '\0';
			return (-1);
		}
		else
			(*line)[i] = ch[0];
		i++;

		if (i >= buf_sz)
		{
			old_buf_sz = buf_sz;
			buf_sz += BUFSIZE;
			*line = _realloc(*line, old_buf_sz, buf_sz);
			if (*line == NULL)
			{
				perror("error buffer read\n");
				return (-1);
			}
		}
	}
	return (buf_sz);
}
