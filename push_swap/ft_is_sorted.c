/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:17:02 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:38:12 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_node	*current;
	long	i;

	i = (a)->size;
	current = a->top;
	i--;
	while (i--)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
