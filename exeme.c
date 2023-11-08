#include "main.h"
/**
 * exeme - executes the line of arguments
 * @lineptr: the line of arguments
 * Return: 0
 */
int exeme(char *lineptr)
{
	char **argv, *path;
	int status = EXIT_SUCCESS;

	argv = parse(lineptr);
	if (argv != NULL)
	{
		path = _which(argv[0]);
		if (path != NULL)
		{
			status = _execte(path, argv);
			free(path);
		}
		else
		{
			_putserr("./hsh: 1: ");
			_putserr(argv[0]);
			_putserr(": not found\n");
			status = 127;
		}
		free_arr(argv);
	}
	return (status);
}
