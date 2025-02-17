/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:46:41 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/02/17 22:51:05 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

static void	handle_first_child(int *pfd, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	execute_command(argv[2], envp);
}

static void	handle_second_child(int *pfd, char **argv, char **envp)
{
	int	out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	close(pfd[1]);
	execute_command(argv[3], envp);
}

void	fork_first_child(int *pfd, char **argv, char **envp, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
		handle_first_child(pfd, argv, envp);
}

void	fork_second_child(int *pfd, char **argv, char **envp, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
		handle_second_child(pfd, argv, envp);
}
