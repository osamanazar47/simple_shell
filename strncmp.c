#include "main.h"
/**
 * _strncmp - compares between two strings
 * @first: the first string
 * @second: the second string
 * @n: number of characters to be compared
 * Return: 0 on success -1 on fai
 */
int _strncmp(char *first, char *second, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (first[i] != second[i])
			return (-1);
	}
	return (0);
}
/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 on success
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
