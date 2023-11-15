#include "main.h"
/**
 * _realloc - reallocte memry for a pointer
 * @ptr: the pointer
 * @size: the new size of the block of memory
 * Return: void
 */
void *_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(size));
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		newptr = malloc(size);
		if (newptr == NULL)
			return (ptr);
	}
	_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
