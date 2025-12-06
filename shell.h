#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Art function
int art();

// Parser functions
char **split_line(char *line);

// Executor functions
int launch(char **args);
int execute(char **args);

// Built-in functions
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_chat(char **args);

#endif
