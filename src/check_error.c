/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:13:55 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/31 10:16:47 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_error.h"
#include <stdlib.h>
#include "struct.h"
#include "precise_sleep.h"

void	check_error(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Número de argumentos incorrecto.\n");
		exit(1);
	}	
}

void	one_philo(void)
{
	while (1)
		continue ;
}

void	print_forks(t_philo *philo)
{
	long	time;

	time = get_time() - philo->start;
	pthread_mutex_lock(philo->write);
	printf("%ld %d has taken a fork\n", time, philo->nbr + 1);
	pthread_mutex_unlock(philo->write);
}
