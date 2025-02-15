/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:46:15 by abin-moh          #+#    #+#             */
/*   Updated: 2025/02/08 13:28:52 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		fd[2];
	int		pid[2];
	int		status;
}	t_pipex;

void	handle_error(int exit_status);

void	exec_child(char **argv, char **envp, int *fd);
void	exec_parent(char **argv, char **envp, int *fd);
void	execute(char *argv, char **envp);
char	*get_path(char *cmd, char **envp);
void	free_path(char **paths);

#endif