/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:51:34 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/24 12:02:15 by caquinta         ###   ########.fr       */
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
	
	int *is_dead;
	int nbr;
	long hour_to_die;	 
	int eat;
	int philo_fork;
	int *philo_fork2;
	t_table *table;
	pthread_mutex_t *write;
	pthread_mutex_t *fork;
	pthread_mutex_t *fork2;
} t_philo;

 

#endif