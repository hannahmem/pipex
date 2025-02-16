#include "pipex_lib.h"

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("Error splitting\n");
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

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		fd;
	int		out_fd;
	pid_t	pid[2];
	int		status;
	
	if (argc != 5)
	{
		ft_putstr_fd("Fail to open command\n", 2);
		return (EXIT_FAILURE);
	}
	if (pipe(pfd) == -1)
		return (perror("pipe\n"), EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		return (perror("fork"), EXIT_FAILURE);

	if (pid[0] == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror(argv[1]), EXIT_FAILURE);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[0]);
		close(pfd[1]);
		execute_command(argv[2], envp);
	}
	pid[1] = fork();
	if (pid[1] == -1)
		return(perror("fork"), EXIT_FAILURE);
	if (pid[1] == 0)
	{
		out_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd == -1)
			return (perror(argv[4]), EXIT_FAILURE);
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
		close(pfd[1]);
		execute_command(argv[3], envp);
	}
	close(pfd[1]);
	close(pfd[0]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
