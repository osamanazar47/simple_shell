#include "main.h"
/**
 * main - implementation of shell
 * Return: 0
 */
int main(void)
{
	char *prompt = "$ ", *lineptr = NULL, **argv, *path;
	size_t n = 0;

	while (1)
	{
		_puts("%s", prompt);
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
				print_env();
			else
			{
				exeme(lineptr);
			}
		
		}
	}
	return (0);
}
