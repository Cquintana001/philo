/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:34:26 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/21 12:31:31 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <stdio.h>
#include <stdlib.h>

int find_min(t_philo *philosophers)
{
	printf("%d entra con %d \n", philosophers->nbr_philo, philosophers->eat);
	int min;
	int x;
	t_philo *aux;

	aux = philosophers;
	x = 1;
	min = 0;
	printf("eat_limit1 es %d\n", philosophers->eat_limit);
	while(x<aux->index)
	{
		if(aux->eat < ++aux->eat)
			min =aux->eat;
		aux++;
	}
	printf("eat_limit2 es %d\n", philosophers->eat_limit);	 
	if(  min>=philosophers->eat_limit)
	{	
		printf("Los gordos han comido %d veces y el límite era %d\n", philosophers->eat, philosophers->eat_limit);
		exit(0);
	}
	pthread_mutex_unlock(&philosophers->fork_locks);
	return(min);
}