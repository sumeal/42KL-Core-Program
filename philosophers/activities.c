/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:25:35 by abin-moh          #+#    #+#             */
/*   Updated: 2025/06/04 08:51:05 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork", 0);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->mutex_meal);
	philo->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&philo->mutex_meal);
	print_status(philo, "is eating", 0);
	ft_usleep(philo->table->time_eat, philo);
	pthread_mutex_lock(&philo->mutex_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_meal);
	unlock_both_forks(philo);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping", 0);
	ft_usleep(philo->table->time_sleep, philo);
}

void	unlock_both_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	thinking(t_philo *philo)
{
	long	time_since_last_meal;
	long	time_to_think;

	pthread_mutex_lock(&philo->mutex_meal);
	time_since_last_meal = get_time_in_ms() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->mutex_meal);
	time_to_think = (philo->table->time_to_die
			- time_since_last_meal - philo->table->time_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	else if (time_to_think > 200)
		time_to_think = 200;
	print_status(philo, "is thinking", 0);
	if (time_to_think > 0)
		ft_usleep(time_to_think, philo);
}
