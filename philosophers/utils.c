/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:29:10 by abin-moh          #+#    #+#             */
/*   Updated: 2025/06/04 09:29:45 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(philo->mutex_dead);
	status = *(philo->dead);
	pthread_mutex_unlock(philo->mutex_dead);
	return (status);
}

void	*special_case(t_philo *philo)
{
	print_status(philo, "is thinking", 0);
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork", 0);
	ft_usleep(philo->table->time_to_die, philo);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

int	check_dead(t_table *table, int i)
{
	pthread_mutex_lock(&table->philo[i].mutex_meal);
	if ((get_time_in_ms() - table->philo[i].last_meal_time)
		>= table->time_to_die)
	{
		pthread_mutex_lock(&table->mutex_dead);
		table->dead = 1;
		pthread_mutex_unlock(&table->mutex_dead);
		pthread_mutex_lock(&table->mutex_write);
		printf("%ld ", get_time_in_ms() - table->time_start);
		printf("%d died\n", table->philo[i].id);
		pthread_mutex_unlock(&table->mutex_write);
		pthread_mutex_unlock(&table->philo[i].mutex_meal);
		return (-1);
	}
	pthread_mutex_unlock(&table->philo[i].mutex_meal);
	return (1);
}

int	check_all_finished(t_table *table)
{
	int	finished_count;
	int	i;

	finished_count = 0;
	i = -1;
	while (++i < table->num_philo)
	{
		pthread_mutex_lock(&table->philo[i].mutex_meal);
		if (table->philo[i].meals_eaten >= table->num_need_eat)
			finished_count++;
		pthread_mutex_unlock(&table->philo[i].mutex_meal);
	}
	return (finished_count);
}

void	all_philo_is_full(t_table *table)
{
	pthread_mutex_lock(&table->mutex_write);
	pthread_mutex_lock(&table->mutex_dead);
	table->dead = 1;
	pthread_mutex_unlock(&table->mutex_dead);
	pthread_mutex_unlock(&table->mutex_write);
}
