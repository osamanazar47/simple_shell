#include "main.h"

/**
  * _getc - get the next char
  *
  * @stream: pointer to FILE
  *
  * Return: int char
  */
int _getc(FILE *stream)
{
	static char read_buf[BUFFER_SIZE];
	static size_t index = 0, byte_read = 0;
	int c;

	if (stream == NULL)
		return (-1);
	if (index == byte_read)
	{
		byte_read = read(fileno(stream), read_buf, BUFFER_SIZE);
		if (byte_read <= 0)
			return (-1);
		index = 0;
	}
	c = read_buf[index++];
	return (c);
}
/**
  * _getline - read from file descriptor
  *            and store what it read in lineptr
  *
  * @lineptr: pointer to the buffer
  * 
  * @n: size of buffer
  * 
  * @stream: file describtor
  * 
  * Return: number of byte read by function
  */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	/* pos point to the current position in the buffer */
	char *buf, *pos;
	ssize_t bytes;
	int c;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL; /* bad arguments */
		return (-1);
	}
	if (stream == NULL)
	{
		errno = EBADF; /* bad file descriptor */
		return (-1);
	}
	buf = *lineptr;
	if (buf == NULL || *n < MIN_BUFFER)
	{
		/* if buf is NULL or *n is small --> allocate new space */
		buf = _realloc(*lineptr, BUFFER_SIZE);
		if (buf == NULL)
		{
			errno = ENOMEM; /* fail to allocate space */
			return (-1);
		}
		*n = BUFFER_SIZE;
		*lineptr = buf;
	}
	bytes = 0;
	pos = buf;
	/* read char from stream and check char by char */
	while ((c = _getc(stream)) != EOF)
	{
		if (bytes + 1 >= SSIZE_MAX)
		{
			errno = EOVERFLOW;
			return (-1);
		}
		bytes++;
		/* check if *n is less than readed bytes */
		if (bytes >= (ssize_t)*n - 1)
		{
			buf = realloc(*lineptr, *n + BUFFER_SIZE);
			if (buf == NULL)
			{
				errno = ENOMEM;
				return (-1);
			}
			*n += BUFFER_SIZE;
			pos = buf + bytes - 1;
			*lineptr = buf;
		}
		/* store char in the buffer */
		*pos++ = (char) c;
		if (c == '\n')
			break;
	}
	/* if error in read && no bytes read */
	if (c == -1 && bytes == 0)
		return (-1);
	*pos = '\0';
	return (bytes);
}
