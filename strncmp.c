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
