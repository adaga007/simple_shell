#include "shell.h"
/**
 * _fork - this function will fork a programe
 * @pname: The name of the command
 * @env: The environment variable
 * @argc: The argument count
 * @argv: The argument vector
 * @fullPath: The full path to execute
 * Return: void
 */
void _fork(char *fullPath, char *pname, int argc, char **argv, char **env)
{
	pid_t wpid;
        int wstatus;

	wpid = fork();

        if (wpid == -1)
        {
                perror("There is error in fork");
                exit(EXIT_FAILURE);
        }
        if (wpid == 0)
        {
	  printf("\nThis is total arg: %d  argv[2]: %s\n", argc, argv[2]);
                
                        execve(fullPath, argv, env);
                perror(pname);
                exit(EXIT_FAILURE);
        }
	if (waitpid(wpid, &wstatus, 0) == -1)
        {
                perror("There is was error in waiting for child");
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
	char *fullPath = NULL;
	
	argv = string_tok(commands, " ", &argc);
	if (argv[0] != NULL && _stringlen(argv[0]) > 0 && argv[0][0] == '/' && access(argv[0], X_OK) == 0)
	{
		fullPath = argv[0];
	}
	else
	{
		fullPath = _getAbsPath(argv[0], env);
	}
	if (fullPath != NULL)
	{
	  printf("I fork the programm");
	  _fork(fullPath, pname, argc, argv, env);
	}
	else
	{
	  perror(pname);
	}
}
