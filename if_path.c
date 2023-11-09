#include "main.h"

/**
  * if_path - check if the user command is exectable path
  *
  * @command: string
  *
  * Return: 1 if success 0 if fail
  */

int if_path(char *command)
{
	struct stat st;
	int flag = 0;

	if (stat(command, &st) == 0)
	{
		if (_strncmp(command, "/", 1) == 0 || _strncmp(command, "./", 2) == 0 ||
				_strncmp(command, "../", 3) == 0)
			flag = 1;
	}
	return (flag);
}
