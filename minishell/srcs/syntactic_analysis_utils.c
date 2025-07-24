/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntactic_analysis_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:17:22 by jchen2            #+#    #+#             */
/*   Updated: 2025/03/26 14:04:08 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir(t_cmd *cmd, t_token **lexem)
{
	t_token_type	type;

	type = (*lexem)->type;
	(*lexem) = (*lexem)->next;
	if (type == REDIR_IN)
	{
		if (cmd->input_file)
			free(cmd->input_file);
		cmd->input_file = ft_strdup((*lexem)->value);
		if (!cmd->input_file)
			return (0);
	}
	else if (type == REDIR_OUT)
	{
		if (cmd->output_file)
			free(cmd->output_file);
		cmd->output_file = ft_strdup((*lexem)->value);
		if (!cmd->output_file)
			return (0);
	}
	return (1);
}

int	handle_hd_apd(t_cmd *cmd, t_token **lexem)
{
	t_token_type	type;

	type = (*lexem)->type;
	(*lexem) = (*lexem)->next;
	if (type == APPEND)
	{
		cmd->output_file = ft_strdup((*lexem)->value);
		if (!cmd->output_file)
			return (0);
		cmd->append = 1;
	}
	else if (type == HEREDOC)
	{
		cmd->hd_delimeter = ft_strdup((*lexem)->value);
		if (!cmd->hd_delimeter)
			return (0);
		cmd->is_hd = 1;
	}
	return (1);
}

static char	**create_new_argv(char **old_argv, char *new_value)
{
	char	**new_argv;
	int		i;
	int		size;

	size = 0;
	if (old_argv)
		while (old_argv[size])
			size++;
	new_argv = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_argv)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_argv[i] = old_argv[i];
		i++;
	}
	new_argv[i] = ft_strdup(new_value);
	if (!new_argv[i])
	{
		free(new_argv);
		return (NULL);
	}
	new_argv[i + 1] = NULL;
	return (new_argv);
}

int	add_arg_to_cmd(t_cmd *cmd, char *value)
{
	char	**new_argv;

	if (!cmd || !value)
		return (0);
	new_argv = create_new_argv(cmd->argv, value);
	if (!new_argv)
		return (0);
	if (cmd->argv)
		free(cmd->argv);
	cmd->argv = new_argv;
	return (1);
}
