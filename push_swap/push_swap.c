/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:55:39 by muzz              #+#    #+#             */
/*   Updated: 2025/02/11 08:59:07 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_create_stack(t_stack **a)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	if (!*a)
		ft_error(*a, NULL);
	(*a)->top = NULL;
	(*a)->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	ft_check_valid(argc, argv);
	ft_create_stack(&a);
	ft_init_stack(&a, argc, argv);
	if (!ft_is_sorted(a))
	{
		ft_create_stack(&b);
		ft_sort_stack(a, b);
	}
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
