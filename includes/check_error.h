/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:14:25 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/31 11:00:51 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include "struct.h"

void	check_error(int argc);
void	print_forks(t_philo *philo);
void	one_philo(void);
int		ft_atoi(const char *nptr);

#endif