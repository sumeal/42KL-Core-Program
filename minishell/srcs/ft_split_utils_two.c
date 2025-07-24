/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:11:49 by jchen2            #+#    #+#             */
/*   Updated: 2025/04/29 19:14:11 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator(const char *str)
{
	if (str[0] == '>' && str[1] == '>')
		return (2);
	if (str[0] == '<' && str[1] == '<')
		return (2);
	if (str[0] == '|' || str[0] == '<' || str[0] == '>')
		return (1);
	return (0);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static int	skip_word(const char *str, t_bool *flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !flag->d_s)
			flag->s_s = !flag->s_s;
		else if (str[i] == '\"' && !flag->s_s)
			flag->d_s = !flag->d_s;
		else if (!flag->s_s && !flag->d_s)
		{
			if (is_operator(str + i) || is_whitespace(str[i]))
				break ;
		}
		i++;
	}
	return (i);
}

int	count_substr(char *str)
{
	int		num;
	t_bool	flag;
	int		skip;

	num = 0;
	flag = (t_bool){false, false, false};
	while (*str)
	{
		skip = is_operator(str);
		if (is_whitespace(*str))
			str++;
		else if (!flag.s_s && !flag.d_s && (skip))
		{
			num++;
			str += skip;
		}
		else
		{
			skip = skip_word(str, &flag);
			num++;
			str += skip;
		}
	}
	return (num);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// 引入你的函数声明（如果是单独测试文件的话）
int num_substr(char *str);

// 测试函数
int main(void)
{
	char *tests[] = {
		"ls -l|grep>txt",
		"echo \"hello'hi' | world\" > out.txt",
		"cat << EOF | grep 'data' >> log",
		"ls|ls",
		"echo 'a >> b' <<file",
		NULL
	};

	int i = 0;
	while (tests[i])
	{
		printf("Input: [%s]\n", tests[i]);
		printf("Substrings counted: %d\n", num_substr(tests[i]));
		printf("---------------------------\n");
		i++;
	}
	return 0;
}
*/
