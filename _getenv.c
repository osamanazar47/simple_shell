#include "main.h"
/**
 * _getenv - prints the enviroment variables
 * Return: 0
 */
int _getenv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
