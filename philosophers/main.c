/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:46 by abin-moh          #+#    #+#             */
/*   Updated: 2025/05/30 14:23:00 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_in_ms(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}

void	ft_usleep(long time_sleep, t_philo *philo)
{
	long	start;
	long	now;

	start = get_time_in_ms();
	while (1)
	{
		now = get_time_in_ms();
		if ((now - start) >= time_sleep)
			break ;
		if (is_dead(philo))
			break ;
		usleep(500);
	}
}

int	ret_error(int ret, char *s, char *var)
{
	printf("%s", s);
	if (var)
		printf(" %s", var);
	printf("\n");
	return (ret);
}

void	print_status(t_philo *philo, char *status, int time)
{
	long	now;

	pthread_mutex_lock(philo->mutex_write);
	now = get_time_in_ms() - philo->table->time_start;
	if (time)
		now = time;
	if (!is_dead(philo))
		printf("%ld %d %s\n", now, philo->id, status);
	pthread_mutex_unlock(philo->mutex_write);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		init_table(&table, argc);
		if (parsing_input(argc, argv, &table) < 0)
			return (1);
		if (init_philo(&table) < 0)
			return (ret_and_free(1, &table));
		if (init_mutex(&table) < 0)
			return (ret_and_free(1, &table));
		if (init_thread(table.philo) < 0)
			return (ret_and_free(1, &table));
		if (init_monitor_thread(&table) < 0)
		{
			wait_thread(table.philo);
			return (ret_and_free(1, &table));
		}
		wait_thread(table.philo);
		free_thread(&table);
	}
	else
		printf("Error: Wrong format\n");
	return (0);
}
