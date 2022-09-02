/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:34:26 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/31 07:50:37 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <unistd.h>

int	find_min(t_philo *philo)
{
	int		x;
	t_philo	*aux;

	aux = philo;
	x = 0;
	while (x < (aux->table->nbr_of_philos))
	{
		if (aux[x].eat < aux->table->eat_limit)
			return (1);
		x++;
	}
	pthread_mutex_lock(philo->write);
	return (0);
}
	/* x = 0;
	printf("limite de comidas es %d.\n", philo[x].table->eat_limit);
	while (x < philo->table->nbr_of_philos)
	{
		printf("philo %d ha comido %d veces.\n", philo[x].nbr, philo[x].eat);
		x++;
	} */