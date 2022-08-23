/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 08:57:10 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/22 08:59:32 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
void print_function(t_philo *aux)
{
	int x = 0;
	while(x<aux->index)
	{
		printf("nbr_philo es %d\n", aux->nbr_philo);
		printf("time_to_die es %d\n", aux->time_to_die);
		printf("hour_to_die es %ld\n", aux->hour_to_die);
		printf("time_to_eat es %d\n", aux->time_to_eat);
		printf("time_to_sleep es %d\n", aux->time_to_sleep);
		printf("fork es %d\n", aux->fork);
		printf("eat_limit es %d\n", aux->eat_limit);
		printf("eat es %d\n", aux->eat);
		printf("index es %d\n", aux->index);
		printf("\n\n\n");
		aux++;
		x++;
	}	
} 