/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:42 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/24 10:31:10 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_heredoc(t_cmd *cmd, int input_fd,
			t_exec_cmd *vars, int *g_exit_status)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			exit(EXIT_SUCCESS);
		if (ft_strcmp(line, cmd->hd_delimeter) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		line = expand_lexem(line, vars->envp, *g_exit_status);
		ft_putendl_fd(line, input_fd);
		free(line);
	}
	exit(EXIT_FAILURE);
}

void	handle_heredoc(t_cmd *cmd, t_exec_cmd *vars, int *g_exit_status)
{
	pid_t	hd_pid;
	int		status;
	int		fd;

	fd = open("/tmp/temporary", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	hd_pid = fork();
	if (hd_pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		process_heredoc(cmd, fd, vars, g_exit_status);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		signal(SIGINT, handle_signal_heredoc);
		waitpid(hd_pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			*g_exit_status = 130;
			cmd->is_hd = 99;
		}
	}
	close(fd);
}

void	here_doc_process(t_cmd *cmd, t_exec_cmd *vars, int *g_exit_status)
{
	if (cmd->is_hd)
		handle_heredoc(cmd, vars, g_exit_status);
	else
		return ;
}

void	run_the_commands(t_cmd *cmd, int *g_exit_status,
			t_exec_cmd *vars, char ***envp)
{
	vars->envp = *envp;
	vars->pid = malloc(sizeof(pid_t) * vars->cmd_count);
	if (!vars->pid)
	{
		perror("pid");
		exit(1);
	}
	save_original_fd(vars);
	here_doc_process(cmd, vars, g_exit_status);
	if (cmd->is_hd == 99)
	{
		free(vars->pid);
		return ;
	}
	create_child_processes(cmd, vars, g_exit_status, envp);
	if (vars->cmd_count != 1)
		closing_pipes(&vars);
	wait_for_child(vars);
	change_signal(0);
	set_exit_status(vars, g_exit_status);
	restore_original_fd(vars);
	free(vars->pid);
	if (vars->cmd_count != 1)
		free_pipe(vars);
}
