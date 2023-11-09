#include "main.h"
/**
 * main - implementation of shell
 * Return: 0
 */
int main(void)
{
	char *prompt = "$ ", *lineptr = NULL;
	size_t n = 0;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts(prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				_puts("\n");
			free(lineptr);
			return (EXIT_SUCCESS);
		}
		if (_strncmp(lineptr, "\n", 1) != 0)
		{
			if (_strncmp(lineptr, "exit", 4) == 0)
			{
				free(lineptr);
				return (EXIT_SUCCESS);
			}
			else if (_strncmp(lineptr, "env", 3) == 0)
				print_env();
			else
			{
				status = exeme(lineptr);
				if (status != EXIT_SUCCESS)
				{
					free(lineptr);
					exit(status);
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}
