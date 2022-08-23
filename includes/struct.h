/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:51:34 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/23 09:56:03 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <pthread.h>


typedef struct s_table{
	
	int nbr_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_limit;	
}t_table;
typedef struct s_philo{
	
	int nbr;
	long hour_to_die;	 
	int eat;
	t_table *table;
	pthread_mutex_t *fork;
	pthread_mutex_t *fork2;
} t_philo;

 

#endif