#include "main.h"
/**
 * _getenv - prints the enviroment variables
 * Return: 0
 */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return;
}
