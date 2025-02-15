/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:31:34 by abin-moh          #+#    #+#             */
/*   Updated: 2025/02/08 13:28:32 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_error(int exit_status)
{
	perror("Error");
	exit(exit_status);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(pipex.fd) == -1)
		handle_error(1);
	pipex.pid[0] = fork();
	if (pipex.pid[0] == -1)
		handle_error(1);
	if (pipex.pid[0] == 0)
		exec_child(argv, envp, pipex.fd);
	pipex.pid[1] = fork();
	if (pipex.pid[1] == -1)
		handle_error(1);
	if (pipex.pid[1] == 0)
		exec_parent(argv, envp, pipex.fd);
	close_pipe(&pipex);
	waitpid(pipex.pid[0], NULL, 0);
	waitpid(pipex.pid[1], &(pipex.status), 0);
	if (WIFEXITED(pipex.status))
		return (WEXITSTATUS(pipex.status));
	return (0);
}
