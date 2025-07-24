/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:36:11 by jchen2            #+#    #+#             */
/*   Updated: 2025/03/24 14:58:18 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lexems(t_token *lexems)
{
	t_token	*tmp;

	while (lexems)
	{
		tmp = lexems->next;
		free(lexems->value);
		free(lexems);
		lexems = tmp;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*next;

	while (cmd)
	{
		next = cmd->next;
		if (cmd->argv)
			free_arr(cmd->argv);
		if (cmd->input_file)
			free(cmd->input_file);
		if (cmd->output_file)
			free(cmd->output_file);
		if (cmd->hd_delimeter)
			free(cmd->hd_delimeter);
		free(cmd);
		cmd = next;
	}
}
