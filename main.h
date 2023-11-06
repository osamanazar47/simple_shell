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

extern char **environ;

/* print the environement variables */
int _getenv(void);
/*void print_env(void);*/
/* parse whatever the user entire */
char **parse(char *lineptr);
/* find the exectable file path */
char *_which(char *command);
/* execte the exectable file */
int _execte(char *path, char **argv);
/* free dynamic allocated space */
void free_arr(char **str);
/* compare two string */
int _strncmp(char *first, char *second, int n);

#endif
