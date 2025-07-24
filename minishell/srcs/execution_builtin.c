/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:48:06 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/02 15:07:05 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_echo(char **commands, int *g_exit_status)
{
	int	new_line;
	int	i;

	i = 1;
	new_line = 0;
	if (!commands[1])
		ft_putstr_fd("", STDOUT_FILENO);
	else if (ft_strcmp(commands[1], "-n") == 0)
	{
		new_line = 1;
		i = 2;
	}
	while (commands[i])
	{
		printf("%s", commands[i]);
		if (commands[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line == 0)
		printf("\n");
	*g_exit_status = 0;
	return (1);
}

void	handle_directory_change(char **cmd,
			char ***mini_envp, int *g_exit_status)
{
	char	*home;

	if (!cmd[1] || ft_strcmp(cmd[1], "~") == 0)
	{
		home = ft_getenv("HOME", *mini_envp);
		if (chdir(home) != 0)
			print_error_cd(home, g_exit_status);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		change_to_pwd(mini_envp, g_exit_status);
	else if (cmd[2])
	{
		ft_putstr_fd("bash: cd: too many arguments\n", STDERR_FILENO);
		*g_exit_status = 1;
	}
	else
		if (chdir(cmd[1]) != 0)
			print_error_cd(cmd[1], g_exit_status);
}

void	update_env_vars(char ***mini_envp, char *cur_dir)
{
	char	new_dir[4096];

	getcwd(new_dir, 4096);
	update_env(cur_dir, "OLDPWD", mini_envp);
	update_env(new_dir, "PWD", mini_envp);
}

void	change_directory(t_cmd **commands,
			char ***mini_envp, int *g_exit_status)
{
	char	**cmd;
	char	cur_dir[4096];

	*g_exit_status = 0;
	if ((*commands)->next != NULL)
	{
		*commands = (*commands)->next;
		return ;
	}
	getcwd(cur_dir, 4096);
	cmd = (*commands)->argv;
	handle_directory_change(cmd, mini_envp, g_exit_status);
	if (*g_exit_status == 0)
	{
		update_env_vars(mini_envp, cur_dir);
	}
}
