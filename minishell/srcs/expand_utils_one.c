/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:19 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 13:44:52 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*concatenate(char **arr)
{
	int		i;
	char	*concat_str;
	char	*tmp;

	i = 1;
	concat_str = arr[0];
	while (arr[i])
	{
		tmp = concat_str;
		concat_str = ft_strjoin(concat_str, arr[i]);
		if (!concat_str)
		{
			free_arr(arr);
			if (tmp)
				free(tmp);
			return (NULL);
		}
		free(tmp);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (concat_str);
}

static char	*find_envp(char *key, char **mini_envp)
{
	int		i;
	char	*copy_env;

	i = 0;
	while (mini_envp[i])
	{
		if (ft_strncmp(key, mini_envp[i], ft_strlen(key)) == 0
			&& mini_envp[i][ft_strlen(key)] == '=')
		{
			copy_env = ft_strdup(&mini_envp[i][ft_strlen(key)] + 1);
			if (!copy_env)
				return (NULL);
			return (copy_env);
		}
		i++;
	}
	copy_env = ft_strdup("");
	if (!copy_env)
		return (NULL);
	return (copy_env);
}

static char	*dup_whole(char *str, char *key, char **mini_envp, int status)
{
	char	*env_sta;
	char	*dup;
	char	*tail;

	if (*key == '?')
	{
		env_sta = ft_itoa(status);
		tail = str + 2;
	}
	else
	{
		env_sta = find_envp(key, mini_envp);
		tail = str + ft_strlen(key) + 1;
	}
	if (!env_sta)
		return (NULL);
	if (*tail == '\0')
		return (env_sta);
	dup = ft_strjoin(env_sta, tail);
	free(env_sta);
	if (!dup)
		return (NULL);
	return (dup);
}

static char	*find_key(char *dollar)
{
	char	*key;
	int		count;
	int		i;

	count = 1;
	while (dollar[count] && (ft_isalnum(dollar[count])
			|| dollar[1] == '?' || dollar[count] == '_'))
		count++;
	key = (char *)malloc(count);
	if (!key)
		return (NULL);
	i = 0;
	while (i < count - 1)
	{
		key[i] = dollar[i + 1];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*expand_str(char *s, char **mini_envp, int status)
{
	char	**arr;
	char	*str;
	char	*key;
	int		i;

	arr = split_keep_delimiter(s, '$');
	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] == '$' && (ft_isalpha(arr[i][1]) || arr[i][1] == '?'))
		{
			key = find_key(arr[i]);
			if (!key)
				return (NULL);
			str = dup_whole(arr[i], key, mini_envp, status);
			free(key);
			if (!str)
				return (NULL);
			free(arr[i]);
			arr[i] = str;
		}
	}
	return (concatenate(arr));
}
