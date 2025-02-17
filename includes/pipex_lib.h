/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:27:22 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/02/17 22:47:31 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LIB_H
# define PIPEX_LIB_H

# define EXIT_FAILURE -1

# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>

int		main(int argc, char **argv, char **envp);
void	free_split(char **split_array);
char	*find_path(char *cmd, char **envp);
char	*split_path(char *cmd, char **dirs);
void	execute_command(char *cmd, char **envp);
void	setup_pipe(int *pfd);
void	fork_first_child(int *pfd, char **argv, char **envp, pid_t *pid);
void	fork_second_child(int *pfd, char **argv, char **envp, pid_t *pid);

#endif