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
	int status;

	while (1)
	{
		printf("%s", prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(99);
		}
		if (_strncmp(lineptr, "exit", 4) == 0)
		{
			free(lineptr);
			exit(99);
		}
		else if (_strncmp(lineptr, "env", 3) == 0)
			_getenv();
		else
		{
			argv = parse(lineptr);
			path = _which(argv[0]);
			if (path != NULL)
			{
				status = _execte(path, argv);
				free(path);
			}
			else
				printf("Command '%s' not found\n", argv[0]);
			free_arr(argv);
		}
	}
	return (0);
}
