#include "shell.h"

/**
 * _stringlen - returns the length of a string
 * @s: string
 * Return: value
 */
size_t _stringlen(char *s)
{
	size_t longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

/**
 * _stringcpy - copy a string
 * @dest: input val
 * @src: input
 * @n: input value
 *
 * Return: dest
 */
char *_stringcpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
/**
 * _stringdup - This function will duplicate a string
 * @str: The string to duplicate
 * Return: A pointer to the duplicate
 */
char *_stringdup(char *str)
{
	size_t len = _stringlen(str) + 1;
	char *duplicate = malloc(len);

	if (duplicate != NULL)
	{
		_stringcpy(duplicate, str, len);
	}

	return (duplicate);
}
