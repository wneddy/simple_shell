#include "main.h"

/**
 * support_func - prototype functions handling commands not in path
 * @input: commands tokenised
 * @variable: input user
 * @check_exit: check exit status
 * @env_var: environment variable
 * @args: program name
 * Return: 1 true, 0 false
 */
int support_func(char **input, char *variable, int check_exit,
		 char **env_var, char *args)
{
	if (!str_cmp(input[0], "exit"))
		exit_command(input, variable, check_exit);
	if (!str_cmp(input[0], "setenv"))
	{
		set_env(input);
		return (0);
	}
	if (!str_cmp(input[0], "unsetenv"))
	{
		unset_env(input);
		return (0);
	}
	if (!str_cmp(input[0], "env"))
	{
		env_check(env_var);
		return (0);
	}
	if (!str_cmp(input[0], "$$") || !str_cmp(input[0], "$?"))
		replacement_check(&input[0], check_exit);
	if (!str_cmp(input[0], "echo"))
	{
		if (input[1] == NULL)
		{
			write(1, "\n", 1);
			return (0);
		}
		echo_check(input, check_exit, env_var);
		return (0);
	}
	if (!str_cmp(input[0], "cd"))
	{
		cd_func(input, args);
		return (0);
	}
	return (-1);
}

/**
 * echo_check - function to check echo command
 * @input: tokenise input
 * @check_exit: check exit status
 * @env_var: enviroment variables
 */
void echo_check(char **input, int check_exit, char **env_var)
{
	pid_t pid_set = getpid();
	char pid_s[32], exit_s[32];
	char *loc;
	int k;

	func_itoa(pid_set, pid_s, 10);
	func_itoa(check_exit, exit_s, 10);
	for (k = 1; input[k] != NULL; k++)
	{
		if (k > 1)
			puts_(" ");
		if (!str_cmp(input[k], "$?"))
		{
			write(1, exit_str, _strlen(exit_str));
			continue;
		}
		if (!str_cmp(input[k], "$$"))
		{
			write(1, pid_s, str_len(pid_s));
			continue;
		}
		if (!str_cmp(input[k], "$PATH"))
		{
			loc = path_finder(env_var);
			puts_(loc);
			free(loc);
			continue;
		}
		puts_(input[k]);
	}
	puts_("\n");
}

/**
 * replacement_check - function to check replacement of $? and $$
 * @input: command replacement adress
 * @check_exit: exit status checker
 */
void replacement_check(char **input, int check_exit)
{
	pid_t pid_set = getpid();

	if (!str_cmp(*input, "$$"))
		func_itoa(pid_set, *input, 10);

	if (!str_cmp(*input, "$?"))
		func_itoa(check_exit, *input, 10);
}

/**
 * set_env - function that sets environment variable
 * @tok_command: tokenizes user command
 * Return: null
 */
void set_env(char **tok_command)
{
	int ov_write = 1, tare;

	if (tok_command[1] == NULL || tok_command[2] == NULL)
	{
		puts_("setenv: Too few arguments \n");
		return;
	}
	if (tok_command[3] != NULL)
	{
		puts_("setenv: Too many arguments \n");
		return;
	}

	tare = setenv(tok_command[1], tok_command[2], ov_write);

	if (tare != 0)
		perror("setenv");
}

/**
 * unset_env - function to unset env
 * @toks_command: tokenize user comand
 * Return: null
 */
void unset_env(char **tok_command)
{
	int tare;

	if (tok_command[1] == NULL)
	{
		puts_("unsetenv: Too few arguments \n");
		return;
	}
	if (input_toks[2] != NULL)
	{
		puts_("unsetenv: Too many arguments \n");
		return;
	}

	tare = unsetenv(tok_commmand[1]);

	if (tare != 0)
		perror("unsetenv");
}
