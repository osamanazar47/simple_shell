#include "main.h"

/**
  * _putchar_err - print error
  *
  * @c: char
  *
  * Return: length of error msg
  */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}
/**
  * _putserr - print error
  *
  * @str: string
  *
  * Return: length of error msg
  */
int _putserr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i += _putchar_err(str[i]);

	return (i);
}
