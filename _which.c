#include "main.h"

/**
  * _which - find the path of the exectable file
  *
  * @command: command name
  *
  * Return: path of the exectable file in success NULL if fail
  */

char *_which(char *command)
{
	char *path, *copy_path, *tok = NULL, *command_path = NULL;
	struct stat st;
	const char *delm = " : ";
	size_t command_len = 0;

	/* if the command is a path */
	if (stat(command, &st) == 0)
	{
		command_path = strdup(command);
		return (command_path);
	}
	command_len = strlen(command);
	path = getenv("PATH");
	copy_path = malloc(strlen(path) + 1);
	strcpy(copy_path, path);
	tok = strtok(copy_path, delm);
	while (tok != NULL)
	{
		/*check if the command is in the path*/
		command_path = malloc(sizeof(char) * (strlen(tok) + command_len + 2));
		if (!command_path)
		{
			return (NULL);
		}
		strcpy(command_path, tok);
		strcat(command_path, "/");
		strcat(command_path, command);
		strcat(command_path, "\0");
		if (stat(command_path, &st) == 0)
		{
			free(copy_path);
			return (command_path);
		}
		tok = strtok(NULL, delm);
		free(command_path);
	}
	free(copy_path);
	return (NULL);
}
