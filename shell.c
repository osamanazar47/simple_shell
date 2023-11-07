#include "main.h"
/**
 * main - implementation of shell
 * Return: 0
 */
int main(void)
{
	char *prompt = "$ ", *lineptr = NULL;
	char **argv, *path;
	size_t n = 0;

	while (1)
	{
		printf("%s", prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			_puts("\n");
			free(lineptr);
			return (0);
		}
		if (_strncmp(lineptr, "\n", 1) != 0)
		{
			if (_strncmp(lineptr, "exit", 4) == 0)
			{
				free(lineptr);
				return (0);
			}
			else if (_strncmp(lineptr, "env", 3) == 0)
				_getenv();
			else
			{
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
					free_arr(argv);
				}
			}
		}
	}
	return (0);
}
