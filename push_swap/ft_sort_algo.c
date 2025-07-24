/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:58:50 by muzz              #+#    #+#             */
/*   Updated: 2025/02/11 09:23:18 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (size > 0)
	{
		max_bits++;
		size >>= 1;
	}
	return (max_bits);
}

void	push_elements_based_on_bit(t_stack *a, t_stack *b, int size, int i)
{
	int		j;
	t_node	*current;

	j = 0;
	while (j < size)
	{
		current = a->top;
		if (((current->index >> i) & 1) == 0)
			ft_pb(a, b, 1);
		else
			ft_ra(a, 1);
		j++;
	}
}

void	push_elements_back(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		ft_pa(a, b, 1);
}

void	ft_sort_algo(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	size;

	size = a->size;
	i = 0;
	assign_indices(a);
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		if (ft_is_sorted(a))
			break ;
		push_elements_based_on_bit(a, b, size, i);
		push_elements_back(a, b);
		i++;
	}
}
