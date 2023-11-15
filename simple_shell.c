#include "main.h"

/**
 * main - simple shell function
 * @ac: argument count
 * @av: array of argument
 * @env_var: env variable
 *
 * Return: result
 */
int main(int __attribute__((unused)) ac, char **av, char **env_var)
{
	char *user_command = NULL, **args = NULL;
	int check_exit = 0, output_res = 0;
	int proc_nth = 0;

	while (1)
	{
		user_command = get_input();
		if (!user_command)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(check_exit);
		}
		else
		{
			proc_nth++;
			args = tokenizer(user_command);
			if (!args)
			{
				free(args);
				continue;
			}
			check_exit = support_func(args, user_command, check_exit,
						   env_var, av[0]);
			if (check_exit == -1)
			{
				output_res = path_handler(&args[0], env_var);
				check_exit = exe_func(args, av, env_var,
						      user_command, output_res,
						      proc_nth);
				if (output_res == 0)
					free(args[0]);
			}
			free(args);
		}
		free(user_command);
	}
	return (check_exit);
}
