#ifndef MAIN_H
#define MAIN_H

/*libraries*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* definations */
#define EXIT WIFEXITED
#define STATUS WEXITSTATUS

/* prototype functions */
char *get_input(void);
void exit_command(char **token, char *line, int done);
void env_check(char **env_var);
char *get_path(char **env);
int path_handler(char **token, char **env_var);
char **tokenizer(char *args);
unsigned int delimeter_check(char ch, const char *s);
char *str_tok(char *s, const char *mark);

/* string prototype functions */
int str_cmp(char *str1, char *str2);
int str_len(char *s);
size_t str_bytecmp(char *str1, char *str2, size_t nmbr);
char *str_cat(char *to, char *from);
char *str_cpy(char *to, char *from);
int func_atoi(char *str);
void func_itoa(int p, char *s, int station);
void str_rev(char *s);
char *str_dup(const char *s);

/* printing prototype function */
int puts_(char *s);
int putchar_(char ch);

#endif
