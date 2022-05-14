#include "shell.h"
#include <string.h>

/**
* excute - executes the parent and child process
* @tokens : tokenized array of commands
* @cmdPath : command with the complete path
* Return - nothing
*/
void excute(char **tokens, char *cmdPath)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking Error\n");
	}
	if (pid == 0)
	{
		if (execve(cmdPath, tokens, environ) == -1)
		{
			perror("No such file or directory\n");
		}
	}
	else
		waitpid(-1, &status, 0);
}
