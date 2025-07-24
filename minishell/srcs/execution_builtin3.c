/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_builtin3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:57:16 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/02 14:58:05 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *name, char **envp)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

int	ignore_export(int *g_exit_status)
{
	*g_exit_status = 0;
	return (1);
}

int	count_command(t_cmd *cmd)
{
	t_cmd	*temp;
	int		count;

	count = 0;
	temp = cmd;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	closing_pipes(t_exec_cmd **vars)
{
	int	i;

	i = 0;
	while (i < (*vars)->cmd_count - 1)
	{
		close((*vars)->pipefd[i][0]);
		close((*vars)->pipefd[i][1]);
		i++;
	}
}

void	exit_program_err(t_cmd *commands, char **mini_envp, int *g_exit_status)
{
	printf("exit\n");
	error_numeric_arg(commands->argv[1], g_exit_status);
	free_cmds(commands);
	free_path(mini_envp);
	exit (*g_exit_status);
}
