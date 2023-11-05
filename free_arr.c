#include "main.h"

/**
  * free_arr - free allocated array of strings
  *
  * @str: array of string
  *
  * Return: nothings
  */
void free_arr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
