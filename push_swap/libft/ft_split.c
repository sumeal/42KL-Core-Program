/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:57:00 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 20:34:27 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (len);
}

void	ft_empty_balance(char **ret, int i)
{
	while (i--)
	{
		free(ret[i]);
	}
	free(ret);
}

char	**ft_copy(char **ret, char const *s, char c)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c) == NULL)
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			ret[i] = ft_substr(s, 0, word_len);
			if (!ret[i])
			{
				ft_empty_balance(ret, i);
				return (NULL);
			}
			i++;
			s = s + word_len;
		}
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	ret = malloc(sizeof(char *) * (word_count + 1));
	if (!ret)
		return (NULL);
	if (ft_copy (ret, s, c) == NULL)
		return (NULL);
	ret[word_count] = NULL;
	return (ret);
}

/*
#include <stdio.h>

int main(void)
{
	char **result;
	size_t	i;

	char *str = "Hello, world!, How are you?";
	char delimiter = ' ';
	result = ft_split(str, delimiter);
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}
*/