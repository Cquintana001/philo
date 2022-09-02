/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:07:59 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/31 10:37:31 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECISE_SLEEP_H
# define PRECISE_SLEEP_H
# include "struct.h"

long	get_time(void);
int		ft_precise_sleep(t_philo *philo, int state);
int		is_sleeping(t_philo *philo);
int		is_eating(t_philo *philo);
#endif