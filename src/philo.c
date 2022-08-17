/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:49:09 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/17 15:40:22 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include "struct.h"
#include "check_error.h"
#include "../libft/libft.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "fill_data.h"
  
pthread_mutex_t fork_locks = PTHREAD_MUTEX_INITIALIZER;	
 void *is_eating(t_philo *philo)
{
	*(philo->fork2)= 1;
		philo->fork = 1;
		printf("%d is eating\n", philo->nbr_philo);
		ft_precise_sleep(philo->time_to_eat);
		*(philo->fork2)= 0;
		philo->fork = 0;
		return 0;
} 
void *philo_state(void *arg)
{
	 
	t_philo *philosopher = (t_philo*) arg;
 pthread_mutex_lock(&fork_locks);
	printf("%d\n", philosopher->nbr_philo);
	pthread_mutex_unlock(&fork_locks);
 
	// while(1)
	// {
	// 	pthread_mutex_lock(&fork_locks);
	// 	if(*(philosopher->fork2)==0 && philosopher->fork == 0)
	// 	{			
	// 		is_eating(philosopher);
	// 	}
	// 	pthread_mutex_unlock(&fork_locks);
	// }
	return 0;
}
 
 


int main(int argc, char* argv[])
{
	check_error(argc);
	t_philo *philos;
 
	
	int x = 0;
	philos = fill_data(argv[1],argv[2],argv[3],argv[4]);
	pthread_t threads[ft_atoi(argv[1])];
	pthread_mutex_init(&fork_locks, NULL);
	while(x<(ft_atoi(argv[1])))
	{
 
	 
		pthread_create(&threads[x], NULL, philo_state, (void*)&philos[x]);
	 
		x++;
	 
	 
	}
		 
	 

	return (0);
}