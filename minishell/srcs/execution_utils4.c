/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:35:48 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/17 09:39:22 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipe(t_exec_cmd *vars)
{
	int	i;

	if (!vars || !vars->pipefd)
		return ;
	i = 0;
	while (i < vars->cmd_count - 1)
	{
		if (vars->pipefd[i] != NULL)
		{
			free(vars->pipefd[i]);
			vars->pipefd[i] = NULL;
		}
		i++;
	}
	free(vars->pipefd);
	vars->pipefd = NULL;
}

char	*get_shlvl_value(char **envp, int index)
{
	int		number1;
	int		position;
	char	*number2;
	char	*ret;

	position = 0;
	while (envp[index][position] && envp[index][position] != '=')
		position++;
	position++;
	number1 = ft_atoi((envp[index]) + position);
	number1++;
	number2 = ft_itoa(number1);
	ret = ft_strdup(number2);
	free(number2);
	return (ret);
}

void	increment_shlvl(char ***envp)
{
	int		index;
	char	*new;
	char	*temp;
	char	*value_int;

	index = find_variable("SHLVL", *envp);
	if (index >= 0)
		value_int = get_shlvl_value(*envp, index);
	else
		return ;
	temp = ft_strdup("SHLVL=");
	new = ft_strjoin(temp, value_int);
	free(temp);
	free(value_int);
	if (!new)
		return ;
	if (index >= 0)
	{
		free((*envp)[index]);
		(*envp)[index] = new;
	}
}

char	*check_xcess(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (cmd);
	else
		return (NULL);
}
