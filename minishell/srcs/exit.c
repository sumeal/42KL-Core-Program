/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:30:47 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/02 16:02:28 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_program(t_cmd *commands, char **mini_envp, int *g_exit_status)
{
	printf("exit\n");
	free_cmds(commands);
	free_path(mini_envp);
	exit (*g_exit_status);
}

int	is_num(char *s)
{
	int	i;

	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_value(t_cmd *commands, char **mini_envp, int *g_exit_status)
{
	int	temp;

	if (commands->next != NULL)
		return (1);
	if (commands->argv[2])
	{
		error_too_many_arg(g_exit_status);
		return (1);
	}
	if (commands->argv[1] && is_num(commands->argv[1]))
	{
		temp = ft_atoi(commands->argv[1]);
		if (temp < 0)
			temp = temp + 256;
		*g_exit_status = (temp % 256);
	}
	exit_program(commands, mini_envp, g_exit_status);
	return (1);
}

void	error_too_many_arg(int *g_exit_status)
{
	printf("exit\n");
	ft_putstr_fd("bash: exit: too many arguments\n", STDERR_FILENO);
	*g_exit_status = 1;
}

void	error_numeric_arg(char *cmd, int *g_exit_status)
{
	ft_putstr_fd("bash: exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	*g_exit_status = 2;
}
