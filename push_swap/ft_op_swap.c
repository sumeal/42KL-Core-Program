/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:01:32 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:38:42 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (a->size < 2)
		return ;
	tmp = a->top;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = tmp->prev;
	tmp->prev->next = tmp2;
	tmp->prev = tmp2;
	a->top = tmp2;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int i)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (b->size < 2)
		return ;
	tmp = b->top;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = tmp->prev;
	tmp->prev->next = tmp2;
	tmp->prev = tmp2;
	b->top = tmp2;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b, int i)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
