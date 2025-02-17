/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:19:53 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/02/17 22:52:52 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

static void	create_pipe(int *pfd)
{
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

static int	wait_for_children(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid[2];
	int		pfd[2];
	int		status;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	create_pipe(pfd);
	fork_first_child(pfd, argv, envp, &pid[0]);
	fork_second_child(pfd, argv, envp, &pid[1]);
	close(pfd[0]);
	close(pfd[1]);
	wait_for_children(pid[0], pid[1]);
	return (WEXITSTATUS(status));
}
