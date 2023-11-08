#include "main.h"
/**
 * print_env - prints the enviroment variables
 * Return: 0
 */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		env++;
	}
}
