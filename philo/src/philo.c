/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:18:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/09/02 07:31:08 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include "struct.h"
#include "check_error.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill_data.h"
#include <unistd.h>
#include "find_min.h"

int	ft_thread_checker(t_philo *aux, pthread_mutex_t *write)
{
	int		x;
	long	time;
	t_philo	*min;

	min = aux;
	while (1)
	{
		x = 0;
		while (x < aux->table->nbr_of_philos)
		{
			if (min->table->eat_limit > 0 && !find_min(min))
				return (0);
			if (aux[x].hour_to_die < get_time())
			{
				pthread_mutex_lock(write);
				time = get_time() - aux[x].start;
				printf("%ld %d died\n", time, aux[x].nbr + 1);
				return (0);
			}
			x++;
		}
	}
}

void	*philo_state(void *arg)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->write);
	philo->start = get_time();
	philo->hour_to_die = get_time() + philo->table->time_to_die;
	pthread_mutex_unlock(philo->write);
	if (philo->nbr % 2 == 1)
		usleep((philo->table->time_to_eat - 20) * 1000);
	while (1)
	{	
		pthread_mutex_lock(philo->fork);
		print_forks(philo);
		if (philo->fork2 == NULL)
			one_philo();
		pthread_mutex_lock(philo->fork2);
		is_eating(philo);
		is_sleeping(philo);
		time = get_time() - philo->start;
		pthread_mutex_lock(philo->write);
		printf("%ld %d is thinking\n", time, philo->nbr + 1);
		pthread_mutex_unlock(philo->write);
	}
}

void	init(int l, t_philo *g, pthread_t *th, pthread_mutex_t *fork)
{
	int	x;

	x = 0;
	while (x < l)
	{
		pthread_mutex_init(&fork[x], NULL);
		pthread_create(&th[x], NULL, &philo_state, g);
		pthread_detach(th[x]);
		g++;
		x++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo			*global;
	t_table			table;
	pthread_mutex_t	write;
	pthread_mutex_t	*f;
	pthread_t		*threads;

	f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	threads = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!check_error(argc, argv))
		return (0);
	table = fill_table(argv);
	global = fill_philo(&table, f, &write);
	pthread_mutex_init(&write, NULL);
	pthread_mutex_lock(&write);
	init(ft_atoi(argv[1]), global, threads, f);
	pthread_mutex_unlock(&write);
	ft_thread_checker(global, &write);
	free(threads);
	free(f);
	free(global);
	return (0);
}
