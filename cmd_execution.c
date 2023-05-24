#include "shell.h"
/**
 * _fork - this function will fork a programe
 * @pname: The name of the command
 * @env: The environment variable
 * @argc: The argument count
 * @argv: The argument vector
 * Return: void
 */
void _fork(char *pname, int argc, char **argv, char **env)
{
	pid_t wpid;
	int wstatus;

	wpid = fork();

	if (wpid == -1)
	{
		perror(pname);
		exit(EXIT_FAILURE);
	}
	if (wpid == 0)
	{
		if (argc > 1)
		{
			execve("", argv, env);
		}
		else
		{
			execve(argv[0], argv, env);
		}
		perror(pname);
		exit(EXIT_FAILURE);
	}
	if (waitpid(wpid, &wstatus, 0) == -1)
	{
		perror(pname);
		exit(EXIT_FAILURE);
	}
}


/**
 * _execute - This function executes our commands
 * @commands: The arguments passed
 * @env: The environment variables
 * @pname: The name of the program
 * Return: void
 */
void _execute(char *commands, char *pname, char **env)
{
	int argc;
	char **argv;

	argv = string_tok(commands, " ", &argc);
	_fork(pname, argc, argv, env);
}
