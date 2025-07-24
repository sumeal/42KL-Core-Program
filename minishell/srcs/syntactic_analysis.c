/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntactic_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:21:31 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 14:27:30 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*create_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->append = 0;
	cmd->is_hd = 0;
	cmd->hd_delimeter = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

static int	build_cmds(t_cmd **cmd, t_token **lexems)
{
	if ((*lexems)->type == PIPE)
	{
		(*cmd)->next = create_cmd();
		if (!(*cmd)->next)
			return (0);
		((*cmd)->next)->prev = *cmd;
		*cmd = (*cmd)->next;
		return (1);
	}
	if ((*lexems)->type == REDIR_IN || (*lexems)->type == REDIR_OUT)
	{
		if (handle_redir(*cmd, lexems) == 0)
			return (0);
	}
	else if ((*lexems)->type == APPEND || (*lexems)->type == HEREDOC)
	{
		if (handle_hd_apd(*cmd, lexems) == 0)
			return (0);
	}
	else if ((*lexems)->type == CMD_ARGS && (*lexems)->value[0] != '\0')
	{
		if (add_arg_to_cmd(*cmd, (*lexems)->value) == 0)
			return (0);
	}
	return (1);
}

static int	process_tokens(t_token *lexems, t_cmd **head)
{
	t_cmd	*cmd;
	int		flag;

	cmd = *head;
	while (lexems)
	{
		flag = build_cmds(&cmd, &lexems);
		if (flag == 0)
		{
			free_cmds(*head);
			free_lexems(lexems);
			return (0);
		}
		if (flag == 1)
			lexems = lexems->next;
	}
	return (1);
}

t_cmd	*syntactic_analysis(char **input, char **mini_envp, int *status)
{
	t_token	*lexems;
	t_cmd	*head;

	if (!check_pipe_end(input, status))
		return (NULL);
	lexems = lexical_analysis(*input, mini_envp, *status);
	if (!lexems)
		return (NULL);
	if (!is_valid_syntax(lexems, status))
	{
		free_lexems(lexems);
		return (NULL);
	}
	head = create_cmd();
	if (!head)
	{
		free_lexems(lexems);
		return (NULL);
	}
	if (!process_tokens(lexems, &head))
		return (NULL);
	if (lexems)
		free_lexems(lexems);
	return (head);
}

/*
#include "minishell.h"
#include <stdio.h>

// Helper function to print command structure
void print_cmd(t_cmd *cmd)
{
	int i;
	
	printf("Command:\n");
	
	// Print args
	if (cmd->argv)
	{
		i = 0;
		printf("  Arguments: ");
		while (cmd->argv[i])
		{
			printf("\"%s\" ", cmd->argv[i]);
			i++;
		}
		printf("\n");
	}
	else
		printf("  Arguments: None\n");
	
	// Print redirections
	if (cmd->input_file)
		printf("  Input file: %s\n", cmd->input_file);
	if (cmd->output_file)
	{
		if (cmd->append)
			printf("  Output file (append): %s\n", cmd->output_file);
		else
			printf("  Output file: %s\n", cmd->output_file);
	}
	if (cmd->is_hd)
		printf("  Heredoc delimiter: %s\n", cmd->hd_delimeter);
}

// Helper function to print entire command list
void print_cmd_list(t_cmd *cmd_head)
{
	int cmd_count = 1;
	t_cmd *current = cmd_head;
	
	while (current)
	{
		printf("\n--- Command %d ---\n", cmd_count++);
		print_cmd(current);
		current = current->next;
	}
	printf("\n");
}

void run_test(char *test_name, char *input, char **envp)
{
	t_cmd *result;
	int status;
	
	printf("\n==== Test Case: %s ====\n", test_name);
	printf("Input: \"%s\"\n", input);
	
	status = 0;
	result = syntactic_analysis(input, envp, &status);
	
	if (status == 2)
	{
		printf("Syntax error detected\n");
	}
	else if (result == NULL)
	{
		printf("Failed to parse command\n");
	}
	else
	{
		print_cmd_list(result);
		free_cmds(result);
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	
	// Simple command tests
	run_test("Simple command", "echo hello world", envp);
	run_test("Command with options", "ls -la", envp);
	
	// Redirection tests
	run_test("Input redirection", "cat < input.txt", envp);
	run_test("Output redirection", "echo hello > output.txt", envp);
	run_test("Append redirection", "echo hello >> output.txt", envp);
	run_test("Heredoc", "cat << EOF", envp);
	run_test("Multiple redirections", "cat < in.txt > out.txt", envp);
	
	// Pipe tests
	run_test("Simple pipe", "ls | grep .txt", envp);
	run_test("Multiple pipes", "ls -la | grep .c | wc -l", envp);
	
	// Complex tests
	run_test("Complex command", "cat < file.txt
		| grep error | sort -r > output.log", envp);
	
	// Error tests
	run_test("Invalid syntax (pipe at start)", "| echo hello", envp);
	run_test("Invalid syntax (pipe at end)", "echo hello |", envp);
	run_test("Invalid syntax (consecutive pipes)", "ls | | grep", envp);
	
	return (0);
}
*/