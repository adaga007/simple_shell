#include "shell.h"

/**
 * _stringcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _stringcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _getEnvp - This funciton gets the desired environment variable
 * @envp: An array of environment variable
 * Return: The environment variable value
 */
char *_getEnvp(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		char *token = strtok(envp[i], "=");

		if (token != NULL && _stringcmp(token, "PATH") == 0)
		{
			char *value = strtok(NULL, "=");

			if (value != NULL)
			{
				return (_stringdup(value));
			}
			else
			{
				break;
			}
		}
	}
	return (NULL);
}
