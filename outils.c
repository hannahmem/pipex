/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:39:22 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/02/17 22:53:31 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	free_split(char **split_array)
{
	int	i;

	if (!split_array)
		return ;
	i = 0;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

char	*split_path(char *cmd, char **dirs)
{
	int		i;
	char	*full_path;

	i = 0;
	while (dirs[i])
	{
		full_path = malloc(ft_strlen(dirs[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		ft_strcpy(full_path, dirs[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path_env;
	char	**dirs;
	char	*result;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path_env = envp[i] + 5;
	dirs = ft_split(path_env, ':');
	if (!dirs)
		return (NULL);
	result = split_path(cmd, dirs);
	free_split(dirs);
	return (result);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("Error splitting");
		exit(EXIT_FAILURE);
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
		free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve failed");
	free_split(args);
	exit(EXIT_FAILURE);
}

void	setup_pipe(int *pfd)
{
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}
