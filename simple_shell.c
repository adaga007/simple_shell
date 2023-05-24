#include "shell.h"
#define UNUSED(x) (void)(x)
/**
 * main - This the main function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: 0
 */
int main(int argc, char *argv[], char  **env)
{
	int truth;
	char *cmdBuff;

	truth = 1;
	(void)argc;
	while (truth)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			truth = 0;
		}
		write(STDOUT_FILENO, "$ ", 2);
		cmdBuff = _getline();
		_execute(cmdBuff, argv[0], env);
	}
	free(cmdBuff);
	return (0);
}
