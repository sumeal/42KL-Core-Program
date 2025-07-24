/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:59:11 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:27:14 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*prepare_sorted_array(t_stack *a, long *offset)
{
	long	*arr;
	long	min_value;

	arr = malloc(sizeof(long) * a->size);
	if (!arr)
		return (NULL);
	copy_stack_to_array(a, arr);
	min_value = find_min_value(arr, a->size);
	if (min_value < 0)
		*offset = -min_value;
	adjust_array_values(arr, a->size, *offset);
	bubble_sort(arr, a->size);
	return (arr);
}

void	assign_stack_indices(t_stack *a, long *arr, long offset)
{
	t_node	*current;
	int		i;
	int		j;

	i = 0;
	current = a->top;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (current->num + offset == arr[j])
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
}

void	assign_indices(t_stack *a)
{
	long	*arr;
	long	offset;

	offset = 0;
	arr = prepare_sorted_array(a, &offset);
	if (!arr)
		return ;
	assign_stack_indices(a, arr, offset);
	free(arr);
}
