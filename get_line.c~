#include "shell.h"
/**
 * _getline - This function gets commands from the terminal
 * @commands: string of commands from the terminal
 * Return: void
 */
char *_getline()
{
	char *commands = NULL;
	size_t commandSize = 0;
	ssize_t bytes;

	bytes = getline(&commands, &commandSize, stdin);
	if (bytes == -1)
	{
		perror("Error in getline function!");
		free(commands);
		exit(EXIT_FAILURE);
	}
	if (commands[bytes - 1] == '\n')
	{
		commands[bytes - 1] = '\0';
	}
	return (commands);
}
