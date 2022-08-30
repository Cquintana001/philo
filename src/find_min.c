/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:34:26 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/30 11:33:10 by caquinta         ###   ########.fr       */
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
	x = 1;
	min = 0;
	 
	while(x<aux->table->nbr_of_philos)
	{
		if(aux->eat < ++aux->eat)
			min =aux->eat;
		aux++;
		x++;
	}
	pthread_mutex_lock(philosophers->write);
	printf("el primer min es %d\n", min); 	
	pthread_mutex_unlock(philosophers->write); 
	if(min>=philosophers->table->eat_limit)	 
	{	
	 
		return(0);

	}
	else
		return(1);
} 