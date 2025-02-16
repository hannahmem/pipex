#ifndef PIPEX_LIB_H
# define PIPEX_LIB_H

#define EXIT_FAILURE -1

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

int     main(int argc, char **argv, char **envp);
void	free_split(char **split_array);
char    *find_path(char *cmd, char **envp);
char    *split_path(char *cmd, char **dirs);

#endif