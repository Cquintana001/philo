/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:51:34 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/20 14:17:14 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philo{
	
	int nbr_philo;
	int time_to_die;
	long hour_to_die;
	int time_to_eat;
	int time_to_sleep;
	int thinking;

	int fork;
	int *fork2;
} t_philo;

 
#endif