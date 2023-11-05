#include "main.h"

/**
  * parse - tokenization the string
  *
  * @lineptr: string
  *
  * Return: array of token
  */
char **parse(char *lineptr)
{
	char *copy_lineptr = NULL, *tok, **argv = NULL;
	const char *delm = " \n\t\r";
	size_t len = 0;
	int i = 0;

	copy_lineptr = strdup(lineptr);
	/* count number of argumens */
	tok = strtok(lineptr, delm);
	while (tok != NULL)
	{
		len++;
		tok = strtok(NULL, delm);

	}
	len++;
	/* store each argument in the array of strings argv */
	argv = malloc(sizeof(char *) * len);
	if (!argv)
	{
		perror("Error: ");
		return (NULL);
	}
	tok = strtok(copy_lineptr, delm);
	while (tok != NULL)
	{
		argv[i] = strdup(tok);
		tok = strtok(NULL, delm);
		i++;
	}
	/* NULL temenation for the array */
	argv[i] = NULL;
	free(copy_lineptr);
	free(tok);
	return (argv);
}
