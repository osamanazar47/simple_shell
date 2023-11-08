#include "main.h"
/**
 * exeme - executes the line of arguments
 * @lineptr: the line of arguments
 * Return: 0
 */
int exeme(char *lineptr)
{
	char **argv, *path;

	argv = parse(lineptr);
	if (argv != NULL)
	{
		path = _which(argv[0]);
		if (path != NULL)
		{
			_execte(path, argv);
			free(path);
		}
		else
		{
			_puts("./hsh: 1: ");
			_puts(argv[0]);
			_puts(": not found\n");
		}
		free(argv);
	}
	return (0);
}
