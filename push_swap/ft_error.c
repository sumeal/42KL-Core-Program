/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:12:41 by muzz              #+#    #+#             */
/*   Updated: 2025/02/10 20:33:17 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->top = NULL;
}

static void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_free_stack_nodes(stack_a);
	if (stack_b)
		ft_free_stack_nodes(stack_b);
	free(stack_a);
	free(stack_b);
}

void	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stacks(stack_a, stack_b);
	write(1, "Error\n", 6);
	exit(1);
}
