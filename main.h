#ifndef MAIN_H
#define MAIN_H

#define EXIT WIFEXITED
#define STATUS WEXITSTATUS

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* prototype functions */
char *get_input(void);
void exit_command(char **token, char *line, int done);
void env_check(char **env_var);

#endif
