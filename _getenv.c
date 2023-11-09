#include "main.h"
/**
 * print_env - prints the enviroment variables
 * Return: 0
 */
void print_env(void)
{
	char **env = environ, *key;
	size_t count = 0, j, i , n;

	while (env[count] != NULL)
		count++;
	for (i = 1; i < count; i++)
	{
		key = env[i];
		j = i;
		while (j > 0 && _strcmp(key, env[j - 1]) < 0)
		{
			env[j] = env[j - 1];
			j--;
		}
		env[j] = key;
	}
	for (n = 0; n < count; n++)
	{
		_puts(env[n]);
		_putchar('\n');
	}
}
