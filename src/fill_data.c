/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:59:42 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/20 15:03:38 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fill_data.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include "precise_sleep.h"

t_philo *fill_data( char *x, char *i,char *j, char *h)
{
	t_philo *philos;
	int f;
	
	f= 0;
	philos =(t_philo*) malloc((sizeof(t_philo)* ft_atoi(x) + 1));
	while(f<ft_atoi(x))
	{	philos[f].nbr_philo = f;
		philos[f].time_to_die = ft_atoi(i);
		philos[f].hour_to_die =   get_time() + philos[f].time_to_die;
		philos[f].time_to_eat = ft_atoi(j);
		philos[f].time_to_sleep =  ft_atoi(h);
		philos[f].fork = 0;
		 
		  if(f==0)
			philos[f].fork2 =  &philos[ft_atoi(x) - 1].fork;
		else
			philos[f].fork2 = &philos[f - 1].fork;
		f++;
	}
	return(philos);	
}	