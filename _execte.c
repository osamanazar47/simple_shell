#include "main.h"

/**
  * _execte - execte the exectable file
  *
  * @argv: array of strings
  *
  * Return: 0 if success -1 if fail
  */

int _execte(char *path, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fail to fork\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(path, argv, NULL) == -1)
		{
			perror("Error: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
