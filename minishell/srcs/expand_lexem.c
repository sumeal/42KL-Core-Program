/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_lexem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:15:18 by jchen2            #+#    #+#             */
/*   Updated: 2025/04/30 10:38:59 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. duplicate the input and checking the expansion situation
2. delete quotes if the input has quotes
3. final_word to get the value of lexem
*/

#include "minishell.h"

static void	handle_quote_state(char c, bool *in_single, bool *in_double, int *i)
{
	if (c == '\'' && !*in_double)
		*in_single = !*in_single;
	else if (c == '\"' && !*in_single)
		*in_double = !*in_double;
	(*i)++;
}

static char	*handle_quotes(char *tmp)
{
	char	*clean;
	int		i;
	int		j;
	bool	in_single;
	bool	in_double;

	in_single = false;
	in_double = false;
	i = 0;
	j = 0;
	clean = malloc(ft_strlen(tmp) + 1);
	if (!clean)
		return (NULL);
	while (tmp[i])
	{
		if ((tmp[i] == '\'' && !in_double) || (tmp[i] == '\"' && !in_single))
			handle_quote_state(tmp[i], &in_single, &in_double, &i);
		else
			clean[j++] = tmp[i++];
	}
	clean[j] = '\0';
	free(tmp);
	return (clean);
}

static int	need_expand(const char *str)
{
	t_bool	flag;

	flag = (t_bool){false, false, false};
	while (*str)
	{
		if (*str == '\'' && !flag.d_s)
			flag.s_s = !flag.s_s;
		else if (*str == '\"' && !flag.s_s)
			flag.d_s = !flag.d_s;
		else if (*str == '$' && !flag.s_s)
			return (1);
		str++;
	}
	return (0);
}

char	*expand_lexem(char *s, char **mini_envp, int status)
{
	char	*tmp;
	char	*substr;
	char	*result;

	substr = ft_strdup(s);
	if (!substr)
		return (NULL);
	tmp = substr;
	if (ft_strchr(substr, '$') && need_expand(s))
	{
		tmp = expand_str(substr, mini_envp, status);
		free(substr);
		if (!tmp)
			return (NULL);
	}
	result = handle_quotes(tmp);
	if (!result)
		return (NULL);
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

void test_expand_lexem(char *input, char **mini_envp)
{
    char *expanded = expand_lexem(input, mini_envp);
    if (!expanded)
        printf("expand_lexem(%s) -> ERROR\n", input);
    else
    {
        printf("expand_lexem(%s) -> %s\n", input, expanded);
        free(expanded);
    }
}

int main(void)
{
    // 模拟环境变量数组
    char *mini_envp[] = {
        "USER=student",
        "HOME=/home/student",
        "SHELL=/bin/bash",
        "EMPTY=",
        NULL
    };

    printf("=== Testing expand_lexem ===\n");

    test_expand_lexem("hello", mini_envp);                 // 普通字符串
    test_expand_lexem("$USER", mini_envp);                 // 变量替换
    test_expand_lexem("$HOME", mini_envp);                 // 变量替换
    test_expand_lexem("$UNDEFINED_VAR", mini_envp);        // 未定义变量
    test_expand_lexem("Hello \"$USER!\"", mini_envp);          // 变量在字符串中
    test_expand_lexem("$EMPTY", mini_envp);                // 空变量
    test_expand_lexem("'$USER'", mini_envp);               // 单引号包裹，不展开
    test_expand_lexem("\"$USER\"", mini_envp);             // 双引号包裹，展开
    test_expand_lexem("This is $HOME and $SHELL", mini_envp); // 多个变量

    return 0;
}
*/