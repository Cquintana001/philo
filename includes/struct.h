/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:51:34 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/21 07:35:15 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <pthread.h>

typedef struct s_philo{
	
	int nbr_philo;
	int time_to_die;
	long hour_to_die;
	int time_to_eat;
	int time_to_sleep;
	int thinking;
	pthread_mutex_t fork_locks;
	int fork;
	int *fork2;
} t_philo;

 
#endif