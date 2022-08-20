/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:07:59 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/19 11:02:32 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECISE_SLEEP_H
# define PRECISE_SLEEP_H

long    get_time(void);
long ft_precise_sleep(int milliseconds, long h_die, int index);

#endif