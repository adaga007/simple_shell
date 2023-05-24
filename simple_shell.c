#include "shell.h"
/**
 * main - This the main function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: 0
 */
int main(int argc, char *argv[], char  **env)
{
	char *prompt = "$ ";
	unsigned int  truth = 1;
	char *cmdBuff;

	while (truth)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			truth = 0;
		}
		printf("%s%d ", argv[0], argc);
		write(STDOUT_FILENO, prompt, 2);
		cmdBuff = _getline();
		printf("Env: %s\n", env[0]);
		_execute(cmdBuff, argv[0], env);
	}
	free(cmdBuff);
	return (0);
}
