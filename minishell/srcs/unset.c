/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:24:29 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/24 10:27:07 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(t_cmd *commands, char **mini_envp, int *g_exit_status)
{
	int	i;

	i = 1;
	while (commands->argv[i])
	{
		unset_variable(commands->argv[i], &mini_envp);
		i++;
	}
	*g_exit_status = 0;
	return (1);
}

void	unset_variable(char *var, char ***mini_envp)
{
	int		index;
	int		j;

	if (!var)
	{
		ft_putstr_fd("unset: missing argument\n", 2);
		return ;
	}
	index = find_index(var, *mini_envp);
	if (index >= 0)
	{
		free((*mini_envp)[index]);
		j = index;
		while ((*mini_envp)[j + 1])
		{
			(*mini_envp)[j] = (*mini_envp)[j + 1];
			j++;
		}
		(*mini_envp)[j] = NULL;
	}
}

int	find_index(char *var, char **envp)
{
	int		i;
	size_t	len;

	len = ft_strlen(var);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, len) == 0
			&& (envp[i][len] == '=' || envp[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}
