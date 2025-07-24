/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:26:26 by muzz              #+#    #+#             */
/*   Updated: 2025/01/10 11:39:39 by muzz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack_to_array(t_stack *a, long *arr)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a->top;
	while (i < a->size)
	{
		arr[i] = current->num;
		current = current->next;
		i++;
	}
}

long	find_min_value(long *arr, int size)
{
	long	min_value;
	int		i;

	i = 0;
	min_value = arr[0];
	while (i < size)
	{
		if (arr[i] < min_value)
			min_value = arr[i];
		i++;
	}
	return (min_value);
}

void	adjust_array_values(long *arr, int size, long offset)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] += offset;
		i++;
	}
}

void	bubble_sort(long *arr, int size)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
