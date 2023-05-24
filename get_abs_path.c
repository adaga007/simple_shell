#include "shell.h"

/**
 * _envpCopy - copy the the environment variable
 * @envp: The environment variable
 * Return: the envp 
 */
char **_envpCopy(char **envp)
{
	int count = 0;
	int i;
	int length;
	char **envp_copy = NULL;
	while (envp[count] != NULL)
	{
		count++;
	}

	envp_copy = (char**)malloc((count + 1) * sizeof(char*));

	if (envp_copy != NULL)
	{
		for (i = 0; i < count; i++)
		{
			length = _stringlen(envp[i]) + 1;
			envp_copy[i] = (char*)malloc(length * sizeof(char));
			_stringcpy(envp_copy[i], envp[i], length);
		}

		envp_copy[count] = NULL;
	}

	return envp_copy;
}

/**
* _getAbsPath - Function to get absolute path
* @pname: This is the program name
* @pathValue: This is the path value
* Return: absolute path or null
*/
char *_getAbsPath (char *pname, char **envp)
{
	char *fullPath = NULL;
	char *paths = NULL;
	char *pathValue = NULL;
	size_t pathLength;
	char **envpDup;

	envpDup = _envpCopy(envp);
	pathValue = _getEnvp(envpDup);
	paths = strtok (pathValue, ":");
	while(paths != NULL)
	{
	        pathLength = _stringlen(paths) + _stringlen(pname) + 2;
                fullPath = malloc(pathLength);
                if (fullPath != NULL)
                {
                        _stringcpy(fullPath, paths, _stringlen(paths));
                        _stringcat(fullPath, "/");
                        _stringcat(fullPath, pname);
			if (access(fullPath, X_OK) == 0)
			  {
			    break;
			  }
                }
                
                free(fullPath);
		fullPath = NULL;
	  paths = strtok(NULL, ":");
	}
        
	printf("fullpath: %s plen%lu\n", fullPath, pathLength);
	free(envpDup);
	return (fullPath);
}
