/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:16:32 by jchen2            #+#    #+#             */
/*   Updated: 2025/04/29 18:49:34 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static int	is_operator_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static int	process_quote_char(char **str, t_bool *flag, char *buf, int *len)
{
	if ((**str == '\'' && !flag->d_s) || (**str == '\"' && !flag->s_s))
	{
		buf[(*len)++] = **str;
		if (**str == '\'')
			flag->s_s = !flag->s_s;
		else
			flag->d_s = !flag->d_s;
		(*str)++;
		return (1);
	}
	return (0);
}

static int	process_operator(char **str, char *buf, int *len)
{
	char	curr;
	char	next;

	if (!is_operator_char(**str))
		return (0);
	curr = **str;
	buf[(*len)++] = curr;
	next = *(*str + 1);
	if ((curr == '>' || curr == '<') && next == curr)
	{
		buf[(*len)++] = next;
		(*str)++;
	}
	(*str)++;
	buf[*len] = '\0';
	return (1);
}

char	*count_copy_substr(char **str, t_bool *flag)
{
	char	*buf;
	int		len;

	while (**str && is_whitespace(**str))
		(*str)++;
	buf = malloc(ft_strlen(*str) + 1);
	if (!buf)
		return (NULL);
	len = 0;
	if (!flag->s_s && !flag->d_s && is_operator_char(**str))
	{
		process_operator(str, buf, &len);
		return (buf);
	}
	while (**str)
	{
		if (process_quote_char(str, flag, buf, &len))
			continue ;
		if (!flag->s_s && !flag->d_s
			&& (is_whitespace(**str) || is_operator_char(**str)))
			break ;
		buf[len++] = *(*str)++;
	}
	buf[len] = '\0';
	return (buf);
}

/*
int main(void)
{
	char *input = "echo|hi\"hello '|' world\"he>>file";
	char *ptr = input;
	t_bool flag = {false, false};
	char *token;

	printf("Input: [%s]\n", input);
	while (*ptr)
	{
		while (is_whitespace(*ptr))
			ptr++;
		if (!*ptr)
			break;
		token = count_copy_substr(&ptr, &flag);
		if (token)
		{
			printf("Token: [%s]\n", token);
			free(token);
		}
	}
	return 0;
}
*/
