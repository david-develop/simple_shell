#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct built - Struct built
 *
 * @bui: builtin name.
 * @f: The function associated
 */
typedef struct built
{
	char *bui;
	void (*f)(char **av, char *line);
} built_t;

extern char **environ;

/*generic functions*/
int _strlen(char *s);
int print_string(char *s);
char *_strdup(char *str);
void _freearrp(char **av);
void *_calloc(unsigned int nmemb, unsigned int size);
char *str_concat(char *s1, char *s2);
<<<<<<< HEAD
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
=======
char *_strtok (char *s, char *delim);
>>>>>>> features_c

/*shell functions*/
char *read_line(void);
char **split_line(char *line);
int builtins(char **av, char *line);
char **path_exp(char **av, char **env);
int exec_func(char **av, char *line, const char *argv_0);

/*Builtins*/
void exit_f(char **av, char *line);
void env_f(char **av, char *line);
ssize_t _getline(char **line, size_t *buffsz, FILE *stream);

#endif
