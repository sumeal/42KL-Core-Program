/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:16:39 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:33:07 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_pop(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size == 0)
		return (NULL);
	tmp = stack->top;
	stack->top = tmp->next;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		stack->top->prev = tmp->prev;
		tmp->prev->next = stack->top;
	}
	stack->size--;
	return (tmp);
}

static void	ft_push(t_stack *stack, t_node *tmp)
{
	if (stack->size == 0)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		stack->top = tmp;
	}
	else
	{
		tmp->next = stack->top;
		tmp->prev = stack->top->prev;
		stack->top->prev->next = tmp;
		stack->top->prev = tmp;
		stack->top = tmp;
	}
	stack->size++;
}

void	ft_pa(t_stack *a, t_stack *b, int i)
{
	t_node	*tmp;

	tmp = ft_pop(b);
	if (!tmp)
		return ;
	ft_push(a, tmp);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b, int i)
{
	t_node	*tmp;

	tmp = ft_pop(a);
	if (!tmp)
		return ;
	ft_push(b, tmp);
	if (i == 1)
		write(1, "pb\n", 3);
}
