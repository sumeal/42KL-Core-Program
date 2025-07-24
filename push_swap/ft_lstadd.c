/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:10:48 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:39:11 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_stack **a, t_node *new)
{
	t_node	*last;

	if (!(*a)->top)
	{
		(*a)->top = new;
		new->next = new;
		new->prev = new;
		(*a)->size = 1;
	}
	else
	{
		last = (*a)->top->prev;
		last->next = new;
		new->prev = last;
		new->next = (*a)->top;
		(*a)->top->prev = new;
		(*a)->size++;
	}
}
