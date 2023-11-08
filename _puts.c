#include "main.h"
/**
 * _puts - prints a string
 * @str: the string to be printed
 * Return: the number of characters printed
 */
int _puts(char *str)
{
	int c = 0;

	while (str[c] != '\0')
		c += _putchar(str[c]);
	return (c);
}
