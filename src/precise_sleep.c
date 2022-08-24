/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:46:45 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/24 14:02:25 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <struct.h>
 
long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000; 
    return (milliseconds);
}









int ft_precise_sleep(t_philo *philo, int state)
{
     int milliseconds;
    long start_time;
    start_time = get_time();
     
    if(state == 1)
        milliseconds = philo->table->time_to_sleep;
    else
     milliseconds = philo->table->time_to_eat;
    while (get_time() - start_time < milliseconds )
    {      
        if(get_time()  > philo->hour_to_die)
        { 
            pthread_mutex_lock(philo->write);
            *(philo->is_dead) = 1;
            printf("%ld %d has died2\n", get_time(), philo->nbr);
            pthread_mutex_unlock(philo->write);
            return(0);
        }      
    	usleep(1 * 1500);		 
    } 
    if(*(philo->is_dead) >0)
        return(0);
    return(1);	 
}
int is_eating(t_philo *philo)
{    
    philo->hour_to_die = get_time() + philo->table->time_to_die;
	philo->eat = philo->eat +1;
 
	printf("%ld %d has taken a fork\n",get_time(), philo->nbr);
    printf("%ld %d is eating\n",get_time(), philo->nbr);
 
    if(ft_precise_sleep(philo, 2))
        return(1);
    return(0);
}
int is_sleeping(t_philo *philo)
{
 
    printf("%ld %d is sleeping\n",get_time(), philo->nbr);
 
    if(ft_precise_sleep(philo, 1))
        return(1);
    return(0);
}