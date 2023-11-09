#include "main.h"

/**
  * _strlen - count num of char
  *
  * @str: string
  *
  * Return: number of characters
  */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
/**
  * _strcat - concatenate src to the dest
  *
  * @dest: destenation
  *
  * @src: source
  *
  * Return: pointer to string
  */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Move to the end of dest*/
	for (i = 0; dest[i] != '\0'; i++)
		;
	/* concatenates src to dest */
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';

	return (dest);
}
/**
  * _strcpy - copy string
  *
  * @dest: destenation character
  *
  * @src: source character
  *
  * Return: Always 0.
  */
char *_strcpy(char *dest, char *src)
{
	size_t j, len;

	len = _strlen(src);
	for (j = 0; j < len; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}
/**
  * _memcpy - copy src to dest
  *
  * @dest: destenation string
  *
  * @src: source string
  *
  * @n: number of char
  *
  * Return: pointer string
  */
char *_memcpy(char *dest, const char *src, unsigned int n)
{
	size_t j;

	for (j = 0; j < n; j++)
	{
		dest[j] = src[j];
	}

	return (dest);
}
/**
  * _strdup - duplicate the string
  *
  * @s : string
  *
  * Return: pointer to string
  */
char *_strdup(char *s)
{
	size_t len;
	char *dest = NULL;

	len = _strlen(s) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest)
		_memcpy(dest, s, len);
	return (dest);
}
