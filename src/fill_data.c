/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:59:42 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/23 11:57:52 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fill_data.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include "precise_sleep.h"
#include <pthread.h>
#include <stdio.h>
 
t_table fill_table( char *args[])
{
	t_table table;

		table.nbr_of_philos = ft_atoi(args[1]);
		table.time_to_die = ft_atoi(args[2]);
		 
		table.time_to_eat = ft_atoi(args[3]);
		table.time_to_sleep =  ft_atoi(args[4]);
		if(args[5])
			table.eat_limit = ft_atoi(args[5]);
		else
			table.eat_limit = -1;
 
	return(table);	
}

t_philo *fill_philo(t_table *table, pthread_mutex_t *m )
{
	t_philo *philos;
	philos =(t_philo*) malloc((sizeof(t_philo)*  table->nbr_of_philos + 1));
	int x;

	x = 0;	 
		while(x<table->nbr_of_philos)
		{	
			philos[x].nbr = x;
			philos[x].eat = 0;
			philos[x].hour_to_die =   get_time() + table->time_to_die;
			philos[x].table = table;
			philos[x].fork = &m[x];
			if(table->nbr_of_philos ==1)
				philos[x].fork2= NULL;
			else
				philos[x].fork2= &m[(x+1)%table->nbr_of_philos];
			x++;
		}
		return(philos);
}
	 
