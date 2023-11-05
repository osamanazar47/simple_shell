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

/* print the environement variables */
void print_env(void);
/* parse whatever the user entire */
char **parse(char *lineptr);
/* find the exectable file path */
char *_which(char *path);
/* execte the exectable file */
int _execte(char **argv);
/* free dynamic allocated space */
void free_arr(char **str);

#endif
