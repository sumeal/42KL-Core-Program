/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:35:41 by abin-moh          #+#    #+#             */
/*   Updated: 2025/02/08 13:29:02 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_child(char **argv, char **envp, int *fd)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		handle_error(1);
	dup2(fd_in, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	execute(argv[2], envp);
}

void	exec_parent(char **argv, char **envp, int *fd)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		handle_error(1);
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	execute(argv[3], envp);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		handle_error(127);
	}
	if (execve(path, cmd, envp) == -1)
		handle_error(1);
}

char	*get_path(char *cmd, char **envp)
{
	char	*part_path;
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!path)
			break ;
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_path(paths);
	return (NULL);
}

void	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}
