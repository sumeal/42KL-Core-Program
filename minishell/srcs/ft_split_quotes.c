/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:18:47 by jchen2            #+#    #+#             */
/*   Updated: 2025/04/30 11:03:22 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**free_rest(char **arr, int i)
{
	i = i - 1;
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free (arr);
	return (NULL);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static char	**set_substr(char *str, int num)
{
	char	**arr;
	int		i;
	t_bool	flag;

	arr = (char **)malloc((num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	flag = (t_bool){false, false, false};
	while (*str)
	{
		while (is_whitespace(*str))
			str++;
		if (*str)
		{
			arr[i] = count_copy_substr(&str, &flag);
			if (!arr[i])
				return (free_rest(arr, i));
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split_quotes(char *str)
{
	int		num;
	char	**arr;

	if (!str)
		return (NULL);
	num = count_substr(str);
	arr = set_substr(str, num);
	return (arr);
}

/*
#include <stdio.h>
#include <stdlib.h>

// Declare the split function
char **ft_split_quotes(char *str);

// Helper to free the resulting array
void free_split(char **arr)
{
	int i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

int main(void)
{
	char *input = "echo|he\"Hello '|' world\" \'and quotes\'<<test";
	char **result = ft_split_quotes(input);

	if (!result)
	{
		fprintf(stderr, "Split failed.\n");
		return (1);
	}

	printf("Split result:\n");
	for (int i = 0; result[i]; i++)
		printf("[%d]: %s\n", i, result[i]);

	free_split(result);
	return (0);
}
*/
