/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:22:11 by abin-moh          #+#    #+#             */
/*   Updated: 2025/06/04 09:28:36 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_input(int argc, char **argv, t_table *table)
{
	int		i;
	long	num[5];

	i = 0;
	while (++i < argc)
	{
		if (ft_is_numeric(argv[i]) < 0)
			return (ret_error(-1, "Error: valid need numeric input", NULL));
		num[i - 1] = ft_atol(argv[i]);
		if (i == 1)
			if (!num[i - 1])
				return (ret_error(-1, "Error: please put more than 0", NULL));
	}
	if (put_value_to_table(table, num) < 0)
		return (-1);
	return (0);
}

int	put_value_to_table(t_table *table, long *num)
{
	table->num_philo = num[0];
	table->time_to_die = num[1];
	table->time_eat = num[2];
	table->time_sleep = num[3];
	if (table->num_need_eat >= 0)
	{
		table->num_need_eat = num[4];
		if (table->num_need_eat == 0)
			return (-1);
	}
	table->dead = 0;
	table->mutex_dead_init = 0;
	table->mutex_write_init = 0;
	return (0);
}

void	init_table(t_table *table, int argc)
{
	table->num_philo = 0;
	table->time_to_die = 0;
	table->time_eat = 0;
	table->time_sleep = 0;
	if (argc == 6)
		table->num_need_eat = 0;
	else
		table->num_need_eat = -1;
}
