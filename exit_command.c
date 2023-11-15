#include "main.h"

/**
 * exit_command - function prototype to exit
 * @token: tokenized command
 * @line: user's input
 * @done: the exit status
 */
void exit_command(char **token, char *line, int done)
{
	int status = 0;

	if (!token[1])
	{
		free(line);
		free(token);
		exit(done);
	}
	status = func_atoi(token[1]);
	free(line);
	free(token);
	exit(status);
}

/**
 * env_check - checks inbuilt enviroment variables
 * @env_var: enviroment variable
 */
void env_check(char **env_var)
{
	size_t objects = 0;

	while (env_var[objects])
	{
		write(STDOUT_FILENO, env_var[objects], str_len(env_var[objects]));
		write(STDOUT_FILENO, "\n", 1);
		objects++;
	}
}
