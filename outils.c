/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:39:22 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/02/16 23:12:48 by hmanes-e         ###   ########.fr       */
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

char    *find_path(char *cmd, char **envp)
{
	int     i;
	char    *path_env;
	char    **dirs;
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
		return(NULL);
	result = split_path(cmd, dirs);
	free_split(dirs);
	return (result);
}
char    *split_path(char *cmd, char **dirs)
{
	int     i;
	char    *full_path;
	
	i = 0;
	while (dirs[i])
	{
		full_path = malloc(ft_strlen(dirs[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		ft_printf(full_path, "%s/%s", dirs[i], cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}