#include "shell.h"
/**
 * _stringcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
void _stringcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}
