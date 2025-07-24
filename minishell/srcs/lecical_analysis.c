/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:49:29 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 13:31:40 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. split the input with space, but save quotes
2. create lexems and set the value of lexem using funcs of expand_lexem series
3. then set type using get_type function
*/

#include "minishell.h"

static t_token_type	get_type(char *str)
{
	if (ft_strcmp(str, ">>") == 0)
		return (APPEND);
	else if (ft_strcmp(str, "<<") == 0)
		return (HEREDOC);
	else if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0)
		return (REDIR_IN);
	else if (ft_strcmp(str, ">") == 0)
		return (REDIR_OUT);
	else
		return (CMD_ARGS);
}

static t_token	*create_lexem_node(char *str, char **mini_envp, int status)
{
	t_token	*lexem;

	lexem = (t_token *)malloc(sizeof(t_token));
	if (!lexem)
		return (NULL);
	lexem->value = expand_lexem(str, mini_envp, status);
	if (!lexem->value)
	{
		free(lexem);
		return (NULL);
	}
	lexem->type = get_type(str);
	lexem->next = NULL;
	return (lexem);
}

static int	create_lexems(t_token **lexems, char **arr, char **mini_envp, int s)
{
	t_token	*lexem;
	t_token	*lexem_tail;
	int		i;

	*lexems = NULL;
	i = 0;
	while (arr[i])
	{
		lexem = create_lexem_node(arr[i], mini_envp, s);
		if (!lexem)
		{
			free_lexems(*lexems);
			return (0);
		}
		if (i == 0)
			*lexems = lexem;
		else
			lexem_tail->next = lexem;
		lexem_tail = lexem;
		i++;
	}
	return (1);
}

t_token	*lexical_analysis(char *input, char **mini_envp, int status)
{
	char	**arr;
	t_token	*lexems;

	if (!input)
		return (NULL);
	arr = ft_split_quotes(input);
	if (!arr)
		return (NULL);
	if (!create_lexems(&lexems, arr, mini_envp, status))
	{
		free_arr(arr);
		return (NULL);
	}
	free_arr(arr);
	return (lexems);
}

/*
#include "minishell.h"
#include <stdio.h>

void print_lexems(t_token *lexems)
{
    while (lexems)
    {
        printf("Value: %s, Type: %d\n", lexems->value, lexems->type);
        lexems = lexems->next;
    }
}

void run_syntax_test(char *test_name, char *input, char **envp, int expected)
{
    t_token *lexems;
    int result;
    
    printf("\n==== Test Case: %s ====\n", test_name);
    printf("Input: \"%s\"\n", input);
    
    // Run lexical analysis
    lexems = lexical_analysis(input, envp, 0);
    if (!lexems)
    {
        printf("Error: Lexical analysis failed\n");
        return;
    }
    
    // Print tokens
    printf("Tokens:\n");
    print_lexems(lexems);
    
    // Test syntax validation
    result = is_valid_syntax(lexems);
    printf("\nSyntax validation result: %d (Expected: %d)\n", result, expected);
    if ((result == 0 && expected == 0) || (result != 0 && expected != 0))
        printf("\033[32mTest PASSED!\033[0m\n");
    else
        printf("\033[31mTest FAILED!\033[0m\n");
    
    free_lexems(lexems);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    
    // Valid syntax tests
    run_syntax_test("Simple command", "echo hi\"hello\"", envp, 0);
    
    return (0);
}
*/