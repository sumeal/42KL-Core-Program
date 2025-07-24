/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:06 by abin-moh          #+#    #+#             */
/*   Updated: 2025/06/04 09:06:13 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			num_philo;
	long			time_to_die;
	long			time_eat;
	long			time_sleep;
	long			num_need_eat;
	pthread_mutex_t	mutex_write;
	int				mutex_write_init;
	pthread_mutex_t	mutex_dead;
	int				mutex_dead_init;
	pthread_mutex_t	*forks;
	int				dead;
	long			time_start;
	t_philo			*philo;
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal_time;
	long			meals_eaten;
	pthread_mutex_t	mutex_meal;
	int				mutex_meal_init;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*mutex_write;
	int				*dead;
	pthread_mutex_t	*mutex_dead;
	t_table			*table;
}	t_philo;

/*libft.c*/
int		ft_isdigit(int c);
int		ft_is_numeric(char *s);
long	ft_atol(const char *nptr);
int		ft_strcmp(char *old, char *new);

/*init.c*/
int		init_fork_mutex(t_table *table);
int		init_philo(t_table *table);
int		init_mutex(t_table *table);
int		init_thread(t_philo *philo);
int		init_monitor_thread(t_table *table);

/*routine.c*/
void	start_delay(long start_time);
void	*routine(void *arg);
void	*monitor_routine(void *arg);
void	wait_thread(t_philo *philo);

/*parsing.c*/
int		parsing_input(int argc, char **argv, t_table *table);
int		put_value_to_table(t_table *table, long *num);
void	init_table(t_table *table, int argc);

/*activities.c*/
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	unlock_both_forks(t_philo *philo);
void	thinking(t_philo *philo);

/*utils.c*/
int		is_dead(t_philo *philo);
void	*special_case(t_philo *philo);
int		check_dead(t_table *table, int i);
int		check_all_finished(t_table *table);
void	all_philo_is_full(t_table *table);

/*main.c*/
long	get_time_in_ms(void);
void	ft_usleep(long time_sleep, t_philo *philo);
int		ret_error(int ret, char *s, char *var);
void	print_status(t_philo *philo, char *s, int time);

/*free.c*/
int		ret_and_free(int ret, t_table *table);
void	destroy_a_mutex(pthread_mutex_t *mutex);
void	free_thread(t_table *table);

#endif
