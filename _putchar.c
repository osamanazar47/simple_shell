#include "main.h"
/**
 * _putchar - prints a character
 * @c: the character to printed
 * Return: the character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}	
