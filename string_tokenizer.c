#include "shell.h"

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}


/**
 * string_tok - it helpls to split string into tokens
 * @str: the string ot tokenize
 * @del: The delimiter
 * @size: The number of tokens
 * Return: array of tokens
 */
char **string_tok(char *str, char *del, int *size)
{
	char **parts = NULL;
	int count = 0;

	char *token = strtok(str, del);

	while (token != NULL)
	{
	parts = _realloc(parts, sizeof(parts) * count, (count + 1) * sizeof(char *));
		parts[count] = token;
		count++;
		token = strtok(NULL, del);
	}
	*size = count;
	return (parts);
}
