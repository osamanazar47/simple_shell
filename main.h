#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <limits.h>

#define BUFFER_SIZE 128
#define SSIZE_MAX LONG_MAX
#define MIN_BUFFER 4

extern char **environ;

/* print the environement variables */
void print_env(void);
/* parse whatever the user entire */
char **parse(char *lineptr);
/* find the exectable file path */
char *_which(char *path);
/* execte the exectable file */
int _execte(char *path, char **argv);
/* free dynamic allocated space */
void free_arr(char **str);
/* putchar */
int _putchar(char c);
/* put characters */
int _puts(char *str);
/* get char from stream file */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/* _error msg */
int _error(char *str);
/*exe command */
int exeme(char *lineptr);
/* str length */
size_t _strlen(char *str);
/* copy string */
char *_strcpy(char *dest, char *src);
/* concatenate strings */
char *_strcat(char *dest, char *src);
/* memory copy */
char *_memcpy(char *dest, const char *src, unsigned int n);
/* string dup */
char *_strdup(char *s);
/*compare tow string */
int _strncmp(char *first, char *second, int n);
int _strcmp(const char *str1, const char *str2);
/* putchar to stderr */
int _putchar_err(char c);
/* put characters to stderr */
int _putserr(char *str);
/* check if the command is a path or start with ./ */
int if_path(char *command);
/* reallocates memory for the pointer */
void *_realloc(void *ptr, size_t size);
#endif
