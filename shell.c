#include "main.h"
/**
 * main - implementation of shell
 * Return: 0
 */
int main(void)
{
	char *prompt = "$", *lineptr;
	char **argv;
	int *n = 0, status;

	while (1)
	{
		(void)status;
		printf("\n%s", prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			perror("getline");
			exit(99);
		}
		if (_strncmp(lineptr, "exit", 4) == 0)
			exit(99);
		else if (_strncmp(lineptr, "env", 3) == 0)
			_getenv();
		else
		{
			argv = parse(lineptr);
			*argv = _which(*argv);
			status = _execte(argv);
		}
		free(argv);
	}
	return (0);
}
