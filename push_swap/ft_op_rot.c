/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:33:03 by muzz              #+#    #+#             */
/*   Updated: 2025/01/09 09:36:32 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int i)
{
	a->top = a->top->next;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, int i)
{
	b->top = b->top->next;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, int i)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
