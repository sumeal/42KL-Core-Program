/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:17 by muzz              #+#    #+#             */
/*   Updated: 2025/02/11 15:00:20 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_init_stack(t_stack **a, int argc, char **argv)
{
	char	**str;
	int		i;

	i = 0;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str || !str[0])
			ft_error(*a, NULL);
		while (str[i])
		{
			ft_lstadd(a, ft_lstnew(ft_atoi(str[i]), i));
			i++;
		}
		ft_free_split(str);
	}
	else
	{
		while (++i < argc)
			ft_lstadd(a, ft_lstnew(ft_atoi(argv[i]), (i - 1)));
	}
}
