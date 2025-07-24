/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:06:11 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/02 14:41:36 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_envp(char **envp)
{
	int	count;

	count = 0;
	while (envp[count])
		count++;
	return (count);
}

char	*get_var_name(char *envp)
{
	char	*pos;

	pos = ft_strchr(envp, '=');
	if (!pos)
		return (ft_strdup(envp));
	return (ft_substr(envp, 0, pos - envp));
}

int	add_variable_to_env(char ***mini_envp, char **args)
{
	int		i;
	int		index;
	char	*new;

	i = 1;
	while (args[i])
	{
		if (check_valid_value(args[i]) < 0)
			return (2);
		index = find_variable(args[i], *mini_envp);
		new = ft_strdup(args[i]);
		if (!new)
			return (0);
		if (index >= 0)
		{
			free((*mini_envp)[index]);
			(*mini_envp)[index] = new;
		}
		else
			add_new_variable(mini_envp, &new);
		i++;
	}
	return (1);
}

int	find_variable(char *args, char **mini_envp)
{
	int		i;
	char	*name1;
	char	*name2;

	name1 = get_var_name(args);
	i = 0;
	while (mini_envp[i])
	{
		name2 = get_var_name(mini_envp[i]);
		if (name1 && name2 && ft_strcmp(name1, name2) == 0)
		{
			free(name1);
			free(name2);
			return (i);
		}
		free(name2);
		i++;
	}
	free(name1);
	return (-1);
}

int	check_valid_value(char *s)
{
	int	i;

	if (!s || !s[0])
		return (print_export_error(s));
	if (!(ft_isalpha(s[0]) || s[0] == '_'))
		return (print_export_error(s));
	i = 1;
	while (s[i] && s[i] != '=')
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_' ))
			return (print_export_error(s));
		i++;
	}
	return (0);
}
