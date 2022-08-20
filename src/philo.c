/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:49:09 by caquinta          #+#    #+#             */
	/*   Updated: 2022/08/18 07:39:11 by caquinta         ###   ########.fr       */
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
#include <unistd.h>
  
pthread_mutex_t fork_locks = PTHREAD_MUTEX_INITIALIZER;	
 /* void *is_eating(t_philo *philo)
{
	*(philo->fork2)= 1;
		philo->fork = 1;
		pthread_mutex_unlock(&fork_locks);
		printf("%d is eating\n", philo->nbr_philo);
		ft_precise_sleep(philo->time_to_eat);
		*(philo->fork2)= 0;
		philo->fork = 0;
		  
		return 0;
}  */

void *philo_state(void *arg)
{	 
	t_philo *philosopher = (t_philo*)arg;
	 pthread_mutex_unlock(&fork_locks);
	 
	 printf("soy el filósofo %d\n", philosopher->nbr_philo);
	 	 pthread_mutex_lock(&fork_locks);
	  while(1)
	 {
	 
	 	if(*(philosopher->fork2)==0 && philosopher->fork == 0)				 
		{	
			*(philosopher->fork2)= 1;
			philosopher->fork = 1;
			printf("%ld %d has taken a fork\n",get_time(), philosopher->nbr_philo);
			philosopher->hour_to_die = get_time() + philosopher->time_to_die;
			 		 
			printf("%ld %d is eating\n",get_time(), philosopher->nbr_philo);
			ft_precise_sleep(philosopher->time_to_eat,philosopher->hour_to_die, philosopher->nbr_philo); 
		 
			*(philosopher->fork2)= 0;
			philosopher->fork = 0;
			pthread_mutex_unlock(&fork_locks);
			printf("%ld %d is sleeping\n",get_time(), philosopher->nbr_philo);
			ft_precise_sleep(philosopher->time_to_sleep,philosopher->hour_to_die,philosopher->nbr_philo);
		}
		else
		{	
			pthread_mutex_unlock(&fork_locks);	
			printf("%d is waiting\n", philosopher->nbr_philo);
		 	while(*(philosopher->fork2)==1 || philosopher->fork == 1)
			{ 
				if(get_time()>philosopher->hour_to_die)
        		{
            		printf("%ld %d has died\n", get_time(), philosopher->nbr_philo);
            		exit(0);
        		}
			}
		}	 	
	}  
	return 0;
}

 






int main(int argc, char *argv[])
{
	t_philo *philos;
	int x = 0;
	int a =ft_atoi(argv[1]);
 
	check_error(argc);
	philos = fill_data(argv[1],argv[2],argv[3],argv[4]);
	pthread_t threads[a];
	pthread_mutex_init(&fork_locks, NULL);
	while(x<a)
	{
		  
		pthread_mutex_lock(&fork_locks);
		pthread_create(&threads[x], NULL, &philo_state, philos);
		 
		pthread_mutex_lock(&fork_locks);
		philos++; 
		pthread_mutex_unlock(&fork_locks);
		x++;
		//pthread_mutex_unlock(&fork_locks);	 
	}
	x = 0;
	  
	while(x<a)
	{
		pthread_join(threads[x], NULL);
		x++;
	}
	printf("saliendo por main\n"); 
	//pthread_mutex_destroy(&fork_locks);

	return (0);
}