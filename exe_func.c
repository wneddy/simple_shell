#include "main.h"

/**
 * exe_func - function to execute command
 * @input: command line argument
 * @args: program name
 * @env_var: env variable
 * @command: user input
 * @loc_output: path finder
 * @pid: proccess identifier
 * Return: 0 when success
 */
int exe_func(char **input, char **args, char **env_var, char *command, int loc_output,
		int pid)
{
	pid_t begins;
	int current, check_exit;

	begins = fork();

	if (begins == 0)
	{
		if (execve(input[0], input, env_var) == -1)
		{
			output_err(args[0], pid, input[0]);
			if (!loc_output)
				free(input[0]);
			free(input);
			free(command);
			exit(errno);
		}
	}
	else if (begins == -1)
	{
		perror(args[0]);
		if (!loc_output)
			free(input[0]);
		free(input);
		free(command);
		exit(errno);
	}
	else
	{
		wait(&current);
		if (EXIT(current))
		{
			check_exit = STATUS(current);
			return (check_exit);
		}
	}
	return (0);
}

/**
 * output_err - displays error
 * @identifier: program name
 * @pid: process id
 * @input: the unavailable command
 */
void output_err(char *identifier, int pid, char *input)
{
	char process[32];

	func_itoa(pid, process, 10);

	puts_(identifier);
	puts_(": ");
	puts_(process);
	puts_(": ");
	puts_(input);
	puts_(": not found\n");
}
