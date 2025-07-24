/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:59:07 by abin-moh          #+#    #+#             */
/*   Updated: 2025/04/24 08:48:50 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal_child_exit(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
}

void	change_signal(int to_child)
{
	if (to_child)
	{
		signal(SIGINT, handle_signal_child);
		signal(SIGQUIT, handle_signal_child_exit);
	}
	else
	{
		signal(SIGINT, handle_signal_parent);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	handle_signal_parent(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal = 130;
	}
}

void	handle_signal_child(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
}
