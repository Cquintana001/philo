/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:40 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/30 08:47:26 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_DATA_H
# define FILL_DATA_H

t_table fill_table( char *args[]);
t_philo *fill_philo(t_table *table, pthread_mutex_t *m,   pthread_mutex_t *w );

#endif