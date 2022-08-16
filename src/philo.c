/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:49:09 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/16 14:13:54 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include "struct.h"
#include "check_error.h"
#include "../Libft/libft.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
  


t_philo *fill_data( char *x, char *i,char *j, char *h)
{
	t_philo *philos;
	int f;
	
	f= 0;
	philos =(t_philo*) malloc((sizeof(t_philo)* ft_atoi(x) + 1));
	while(f<ft_atoi(x))
	{	philos[f].nbr_philo = f;
		philos[f].time_to_die = ft_atoi(i);
		philos[f].time_to_eat = ft_atoi(j);
		philos[f].time_to_sleep =  ft_atoi(h);
		philos[f].fork1 = f;
		if(f==0)
			philos[f].fork2 = ft_atoi(x) - 1;
		else
			philos[f].fork2 = f - 1;
		f++;
	}
 
	return(philos);	
}	
 


int main(int argc, char* argv[])
{
	check_error(argc);
	t_philo *philos;
	pthread_mutex_t *fork_locks;
	
	int x = 0;
	while(x<ft_atoi(argv[1]))
	{
		fork_locks = PTHREAD_MUTEX_INITIALIZER;
		fork_locks++;
		x++;
	}
	philos = fill_data(argv[1],argv[2],argv[3],argv[4]);
	/* pthread_t threads[argv[1]];
	
	while(x<(argv[1])
	{
		time
		pthread_create(&threads[x], NULL, philo_state, NULL);
		x++;
	}
		 */
	return (0);
}