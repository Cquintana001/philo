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
#include "find_min.h" 
  

void *philo_state(void *arg)
{	 
	t_philo *philosopher = (t_philo*)arg;
	 pthread_mutex_unlock(&philosopher->fork_locks);
	  while(1)
	 {
	 
	 	if(philosopher->fork2 != NULL && *(philosopher->fork2)==0 && philosopher->fork == 0 )				 
		{	
	 		pthread_mutex_lock(&philosopher->fork_locks);
			*(philosopher->fork2)= 1;
			philosopher->fork = 1;
			printf("%ld %d has taken a fork\n",get_time(), philosopher->nbr_philo);

			philosopher->hour_to_die = get_time() + philosopher->time_to_die;
			pthread_mutex_unlock(&philosopher->fork_locks);
			printf("%ld %d is eating\n",get_time(), philosopher->nbr_philo);
			ft_precise_sleep(philosopher->time_to_eat,philosopher->hour_to_die, philosopher->nbr_philo);			 
			 pthread_mutex_lock(&philosopher->fork_locks);
			philosopher->eat +=1;		 
			*(philosopher->fork2)= 0;
			philosopher->fork = 0;
			pthread_mutex_unlock(&philosopher->fork_locks);
			printf("%ld %d is sleeping\n",get_time(), philosopher->nbr_philo);
			ft_precise_sleep(philosopher->time_to_sleep,philosopher->hour_to_die,philosopher->nbr_philo);
		}
		else
		{	
			 
			printf("%ld %d is thinking\n",get_time(), philosopher->nbr_philo);
		 	while(philosopher->fork2 == NULL|| *(philosopher->fork2)==1 || philosopher->fork == 1)
			{ 
				if(get_time()>philosopher->hour_to_die )
        		{
            		printf("%ld %d has died after %d dinners\n", get_time(), philosopher->nbr_philo, philosopher->eat);

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
	pthread_mutex_t fork_locks = PTHREAD_MUTEX_INITIALIZER;	
	pthread_mutex_init(&fork_locks, NULL); 
	check_error(argc);
	philos = fill_data(argv[1],argv[2],argv[3],argv[4], &fork_locks);
	if(argv[5])
	{	x = ft_atoi(argv[5]);
	}
	else
		x = -1;
	philos = fill_data_second(philos,a,x);	 
	printf("x es %d\n", philos->eat_limit);
		x = 0;
	pthread_t threads[a];
	while(x<a)
	{
		  
		pthread_mutex_lock(&fork_locks);
		pthread_create(&threads[x], NULL, &philo_state, philos);
		 
		philos++; 
		x++;
		pthread_mutex_unlock(&fork_locks); 
	}
	x = 0;
	  
	while(x<a)
	{
		pthread_join(threads[x], NULL);
		x++;
	}

	return (0);
}