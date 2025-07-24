/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:16:27 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 14:18:31 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_error(t_token *next, int *status)
{
	char	*symbol;

	symbol = "";
	if (!next)
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token `newline'\n", 2);
		*status = 2;
		return (0);
	}
	if (next->type == REDIR_IN)
		symbol = "<";
	else if (next->type == REDIR_OUT)
		symbol = ">";
	else if (next->type == APPEND)
		symbol = ">>";
	else if (next->type == HEREDOC)
		symbol = "<<";
	else if (next->type == PIPE)
		symbol = "|";
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(symbol, 2);
	ft_putstr_fd("'\n", 2);
	*status = 2;
	return (0);
}

static int	pipe_error(t_token *next, int *status)
{
	char	*symbol;

	symbol = "";
	if (next->type == PIPE)
	{
		symbol = "|";
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(symbol, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
	{
		ft_putstr_fd("bash: syntax error ", 2);
		ft_putstr_fd("near unexpected token `newline'\n", 2);
	}
	*status = 2;
	return (0);
}

static int	syntax_error(t_token *lexems, int *status)
{
	t_token	*next;

	while (lexems)
	{
		next = lexems->next;
		if ((lexems->type == PIPE && next && next->type != CMD_ARGS))
			return (pipe_error(next, status));
		if ((lexems->type == REDIR_IN || lexems->type == REDIR_OUT
				|| lexems->type == APPEND || lexems->type == HEREDOC))
		{
			if (!next || next->type != CMD_ARGS)
				return (redir_error(next, status));
		}
		if (next == NULL && lexems->type == PIPE)
		{
			ft_putstr_fd("bash: syntax error ", 2);
			ft_putstr_fd("near unexpected token `|'\n", 2);
			*status = 2;
			return (0);
		}
		lexems = lexems->next;
	}
	return (1);
}

int	is_valid_syntax(t_token *lexems, int *status)
{
	if (lexems->value[0] == '\0' && lexems->next == NULL)
	{
		*status = 0;
		return (0);
	}
	if (lexems->type == PIPE)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		*status = 2;
		return (0);
	}
	return (syntax_error(lexems, status));
}
