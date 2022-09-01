/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:14:25 by caquinta          #+#    #+#             */
/*   Updated: 2022/09/01 11:58:24 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include "struct.h"

int		check_error(int argc, char*argv[]);
void	print_forks(t_philo *philo);
void	one_philo(void);
int		ft_atoi(const char *nptr);

#endif