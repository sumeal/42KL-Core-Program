/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:32:49 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/02 14:59:32 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "^C\n", 3);
		g_signal = 130;
	}
}

int	exit_function(t_cmd *commands, char **mini_envp, int *g_exit_status)
{
	if (!(commands->argv[1]) && !commands->next && !commands->prev)
	{
		exit_program(commands, mini_envp, g_exit_status);
	}
	else if (is_num(commands->argv[1]))
		return (check_exit_value(commands, mini_envp, g_exit_status));
	else if (!(is_num(commands->argv[1])))
		exit_program_err(commands, mini_envp, g_exit_status);
	return (1);
}

void	handle_input_redir(t_cmd *cmd, t_exec_cmd *vars, int *g_exit_status)
{
	if (vars->i == 0 || cmd->input_file)
	{
		if (setup_input(cmd, vars, g_exit_status) < 0)
			exit(*g_exit_status);
	}
	else if (vars->i > 0)
	{
		if (dup2(vars->pipefd[vars->i - 1][0], STDIN_FILENO) < 0)
		{
			perror("dup2 input");
			exit(EXIT_FAILURE);
		}
	}
}

void	handle_output_redir(t_cmd *cmd, int cmd_count, t_exec_cmd *vars)
{
	if (vars->i == cmd_count - 1 || cmd->output_file)
	{
		if (cmd->output_file)
		{
			if (handle_last_command_output(cmd, vars) < 0)
				exit(EXIT_FAILURE);
		}
		else
			vars->fdout = dup(vars->ori_out);
	}
	else if (vars->i < cmd_count - 1)
	{
		if (dup2(vars->pipefd[vars->i][1], STDOUT_FILENO) < 0)
		{
			perror("dup2 output");
			exit(EXIT_FAILURE);
		}
	}
}
