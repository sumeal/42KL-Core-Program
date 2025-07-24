/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_builtin2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:51:54 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/24 10:21:12 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_cd(char *failed_cmd, int *g_exit_status)
{
	ft_putstr_fd("bash: cd: ", STDERR_FILENO);
	ft_putstr_fd(failed_cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror("");
	*g_exit_status = 1;
}

void	change_to_pwd(char ***mini_envp, int *g_exit_status)
{
	char	*home;

	home = ft_getenv("OLDPWD", *mini_envp);
	if (home)
	{
		printf("%s\n", home);
		if (chdir(home) != 0)
			print_error_cd(home, g_exit_status);
	}
	else
	{
		ft_putstr_fd("bash: cd: OLDPWD not set\n", STDERR_FILENO);
		*g_exit_status = 1;
	}
}

void	update_env(char *dir, char *name, char ***mini_envp)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(dir) + ft_strlen(name) + 2));
	if (!new)
		return ;
	ft_strcpy(new, name);
	ft_strcat(new, "=");
	ft_strcat(new, dir);
	while ((*mini_envp)[i])
	{
		if (ft_strncmp((*mini_envp)[i], name, ft_strlen(name)) == 0)
		{
			free((*mini_envp)[i]);
			(*mini_envp)[i] = new;
			return ;
		}
		i++;
	}
	add_new_variable(mini_envp, &new);
}

int	print_env(t_cmd **cmd_list, char **mini_envp, int *g_exit_status)
{
	int		i;
	char	*have;

	(void)cmd_list;
	i = 0;
	while (mini_envp[i])
	{
		have = ft_strchr(mini_envp[i], '=');
		if (have)
			printf("%s\n", mini_envp[i]);
		have = 0;
		i++;
	}
	*g_exit_status = 0;
	return (1);
}

int	print_pwd(char **mini_envp, int *g_exit_status)
{
	char	*pwd;

	pwd = ft_getenv("PWD", mini_envp);
	printf("%s\n", pwd);
	*g_exit_status = 0;
	return (1);
}
