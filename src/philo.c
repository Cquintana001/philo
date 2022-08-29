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
   
void print_function(t_philo *philos)
{
	int x = 0;
	int i = philos[0].table->nbr_of_philos;
	printf("valor de i %d\n", i);
	printf("time to die %d\n", philos[0].table->time_to_die);
	while(x<i)
	{	
		printf("nbr_philos es %d\n", philos[x].table->nbr_of_philos);
		printf("time_to_die es %d\n", philos[x].table->time_to_die);
		printf("time_to_eat es %d\n", philos[x].table->time_to_eat); 
		printf("time_to_sleep es %d\n", philos[x].table->time_to_sleep);
		printf("eat_limit es %d\n", philos[x].table->eat_limit);
		printf("index es %d\n", philos[x].nbr);
		printf("fork es %p\n", philos[x].fork);
		printf("fork2 es %p\n", philos[x].fork2);
		printf("eat es %d\n", philos[x].eat);
		printf("hour_to_die es %ld\n", philos[x].hour_to_die);
		printf("is_dead es %p\n", philos[x].is_dead);
		printf("\n\n\n");
		 
		x++;
	}	
} 
void *philo_state(void *arg)
{	
	 
	t_philo *philo = (t_philo*) arg;
	 
	pthread_mutex_lock(philo->write);
	philo->start_time = get_time();
	philo->hour_to_die = get_time() + philo->table->time_to_eat;
	pthread_mutex_unlock(philo->write);
	if(philo->nbr%2 == 1)
		usleep(philo->table->time_to_eat + 20);
	while(1)
	{	 	 
		while(1)
		{
			if(philo->philo_fork == 0)
			{	pthread_mutex_lock(philo->fork);
				philo->philo_fork =1;
			 
				if(*(philo->philo_fork2) == 0)
				{	pthread_mutex_lock(philo->fork2);
					*(philo->philo_fork2) = 1;
					break;
				}		 
			else
			{	
				philo->philo_fork =0;
				pthread_mutex_unlock(philo->fork);
			}
			}
			if((get_time()>philo->hour_to_die))
        	{				 	
					pthread_mutex_lock(philo->write);
					printf("%ld %d has died1\n", get_time() - philo->start_time, philo->nbr);
					*(philo->is_dead) = 1;
        		return(0);
        	}
		}
		is_eating(philo);
		is_sleeping(philo);
		pthread_mutex_lock(philo->write);
		printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->nbr);
		pthread_mutex_unlock(philo->write);
	}  
	 
}

 






int main(int argc, char *argv[])
{
	t_philo *global;
	int x = 0;
	int a =ft_atoi(argv[1]);
	pthread_mutex_t write;
	pthread_mutex_t fork_locks[a];
 
	int is_dead;

	pthread_mutex_init(&write, NULL);
 
	is_dead = 0;
	 
	while(x<a)
	{
		pthread_mutex_init(&fork_locks[x], NULL); 
		x++;
	}
	check_error(argc);
	t_table table = fill_table(argv);
	global = fill_philo(&table, fork_locks, &is_dead, &write);
		x = 0;
	pthread_t threads[a];
	pthread_mutex_lock(&write);
	while(x<a)
	{		  	 
		pthread_create(&threads[x], NULL, &philo_state, global);
		pthread_detach(threads[x]);
 
		 
		global++;
		x++;
		 
	}
	pthread_mutex_unlock(&write);
 	  
	while(is_dead==0)
	{
 
	}
 
	return (0);
}