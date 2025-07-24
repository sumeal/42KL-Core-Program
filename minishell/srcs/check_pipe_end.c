/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:23:15 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/29 14:36:40 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_prev_pipe(char *input, int len)
{
	len--;
	while (len > 0)
	{
		if (input[len] == ' ' || input[len] == '\n' || input[len] == '\t'
			|| input[len] == '\v' || input[len] == '\r' || input[len] == '\f')
			len--;
		else if (input[len] == '|')
			return (1);
		else
			break ;
	}
	return (0);
}

static int	is_end_pipe(char *input)
{
	int	len;

	if (!input)
		return (1);
	len = 0;
	while (input[len])
		len++;
	if (len > 0)
		len--;
	while (len > 0)
	{
		if (input[len] == ' ' || input[len] == '\n' || input[len] == '\t'
			|| input[len] == '\v' || input[len] == '\r' || input[len] == '\f')
			len--;
		else if (input[len] == '|')
		{
			if (has_prev_pipe(input, len) == 1)
				return (0);
			return (1);
		}
		else
			break ;
	}
	return (0);
}

static int	is_start_pipe(char	*input)
{
	int	len;

	len = 0;
	while (input[len])
	{
		if (input[len] == ' ' || input[len] == '\n' || input[len] == '\t'
			|| input[len] == '\v' || input[len] == '\r' || input[len] == '\f')
			len++;
		else if (input[len] == '|')
			return (1);
		else
			break ;
	}
	return (0);
}

void	concat_str(char **line, char **input)
{
	char	*tmp;

	tmp = *input;
	*input = ft_strjoin(*input, " ");
	free(tmp);
	tmp = *input;
	*input = ft_strjoin(*input, *line);
	free(tmp);
}

int	check_pipe_end(char **input, int *status)
{
	char	*line;

	if (!*input)
		return (0);
	if (is_start_pipe(*input) == 1)
	{
		*status = 2;
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (0);
	}
	while (is_end_pipe(*input) == 1 && is_start_pipe(*input) == 0)
	{
		line = readline("> ");
		if (!line)
		{
			printf("minishell: syntax error: unexpected end of file\n");
			free(*input);
			exit(2);
		}
		if (g_signal == 130)
			break ;
		concat_str(&line, input);
		free(line);
	}
	return (1);
}
