/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:37:02 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:34:18 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int i)
{
	a->top = a->top->prev;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, int i)
{
	b->top = b->top->prev;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, int i)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
