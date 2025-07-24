/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:13:08 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/30 09:32:25 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_variable(char ***envp, char **new_var)
{
	int		count;
	char	**new_envp;
	int		i;

	count = count_envp(*envp);
	new_envp = ft_calloc(count + 2, sizeof(char *));
	if (!new_envp)
	{
		free(*new_var);
		return ;
	}
	i = 0;
	while (i < count)
	{
		new_envp[i] = ft_strdup((*envp)[i]);
		i++;
	}
	new_envp[i] = *new_var;
	new_envp[i + 1] = NULL;
	free_path(*envp);
	*envp = new_envp;
}

char	*change_format(char *args)
{
	char	*ret;
	int		i;
	int		j;
	char	*have;

	have = ft_strchr(args, '=');
	if (!have)
		return (ft_strdup(args));
	ret = malloc(sizeof(char) * (ft_strlen(args) + 3));
	if (!ret)
		return (NULL);
	i = 0;
	while (args[i] != '=' && args[i] != '\0')
	{
		ret[i] = args[i];
		i++;
	}
	ret[i++] = '=';
	j = i;
	ret[i++] = '"';
	while (args[j] != '\0')
		ret[i++] = args[j++];
	ret[i] = '"';
	ret[i + 1] = '\0';
	return (ret);
}

int	skip(char *envp1, char *envp2)
{
	if (!envp1 || !envp2)
		return (1);
	if (ft_strncmp(envp1, "_=", 2) == 0 || ft_strncmp(envp2, "_=", 2) == 0)
		return (1);
	return (0);
}

int	print_export_error(char *s)
{
	ft_putstr_fd("bash: export: `", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (-1);
}
