/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:21:01 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/30 14:23:04 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ret_and_free(int ret, t_table *table)
{
	free_thread(table);
	return (ret);
}

void	destroy_a_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		printf("Failed to destroy mutex");
}

void	free_thread(t_table *table)
{
	int	i;

	if (table->philo)
	{
		i = -1;
		while (++i < table->num_philo)
		{
			if (table->philo[i].mutex_meal_init)
				destroy_a_mutex(&table->philo[i].mutex_meal);
		}
		free(table->philo);
	}
	if (table->forks)
	{
		i = -1;
		while (++i < table->num_philo)
			destroy_a_mutex(&table->forks[i]);
		free(table->forks);
	}
	if (table->mutex_write_init)
		destroy_a_mutex(&table->mutex_write);
	if (table->mutex_dead_init)
		destroy_a_mutex(&table->mutex_dead);
}
