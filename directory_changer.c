#include "main.h"

/**
 * cd_func - function working like cd.
 * @input: user input(argumnets).
 * @prog_nm: program name
 */
void cd_func(char **input, char *prog_nm)
{
	int val = -1;
	char func_cwd[PATH_MAX];

	if (input[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (str_cmp(input[1], "-") == 0)
		val = chdir(getenv("OLDPWD"));
	else
		val = chdir(input[1]);

	if (val == -1)
	{
		perror(prog_nm);
		return;
	}
	else if (val != -1)
	{
		getcwd(func_cwd, sizeof(func_cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", func_cwd, 1);
	}
}
