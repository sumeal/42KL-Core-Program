/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:12:22 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/30 13:19:06 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_signal;

char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;

	i = count_envp(envp);
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (envp[++i])
		copy[i] = ft_strdup(envp[i]);
	copy[i] = NULL;
	return (copy);
}

void	free_all(char **mini_envp)
{
	free_path(mini_envp);
	rl_clear_history();
}

void	minishell_loop(char ***mini_envp, int *g_exit_status)
{
	char	*input;
	t_cmd	*commands;

	change_signal(0);
	while (1)
	{
		input = readline("🚀minishell🚀> ");
		if (g_signal == 130)
		{
			*g_exit_status = g_signal;
			g_signal = 0;
		}
		if (!input)
			break ;
		if (*input)
			add_history(input);
		commands = syntactic_analysis(&input, *mini_envp, g_exit_status);
		if (commands)
		{
			execution(commands, mini_envp, g_exit_status);
			free_cmds(commands);
			g_signal = 0;
		}
		free(input);
	}
}

char	**init_env(char **envp)
{
	char	**mini_envp;

	mini_envp = copy_envp(envp);
	increment_shlvl(&mini_envp);
	return (mini_envp);
}

int	main(int argc, char **argv, char **envp)
{
	char			**mini_envp;
	int				g_exit_status;

	(void)argc;
	(void)argv;
	g_signal = 0;
	g_exit_status = 0;
	mini_envp = init_env(envp);
	minishell_loop(&mini_envp, &g_exit_status);
	printf("exit\n");
	free_all(mini_envp);
	return (g_exit_status);
}

/*
mkdir -p /tmp/dir1 /tmp/dir2

#!/bin/bash

echo 'echo "From dir1"' > /tmp/dir1/hello
echo 'echo "From dir2"' > /tmp/dir2/hello
chmod +x /tmp/dir1/hello /tmp/dir2/hello

export PATH=/tmp/dir1:/tmp/dir2:$PATH
*/