/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:34:26 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/30 17:46:51 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int find_min(t_philo *philosophers)
{
	 
	int min;
	int x;
	t_philo *aux;

	aux = philosophers;
	x = 0;
	min = 0;
 
	while(x<(aux->table->nbr_of_philos-1))
	{
		if(aux[x].eat < aux[x+1].eat)
			min =aux->eat;
 
		x++;
	}
	if(min>=philosophers->table->eat_limit)	
	{ 	pthread_mutex_lock(philosophers->write);
		x = 0;
		while(x<philosophers->table->nbr_of_philos)
		{
			printf("philo %d ha comido %d veces.\n", philosophers[x].nbr, philosophers[x].eat);
			x++;
		} 
		return(0);
	}

	else
		return(1);
} 