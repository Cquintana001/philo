/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:46:45 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/17 14:34:19 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

 
long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000; 
    return (milliseconds);
}

 
void ft_precise_sleep(int milliseconds)
{
    long start_time;
	long curr_time;
 
    start_time = get_time();
	curr_time = start_time;
    while (1)
    { 	 
			if(get_time() - curr_time < milliseconds)
        		usleep(1 * 1500);  
			else
			{	
        		printf("%ld\n", get_time() - start_time);
				curr_time = get_time();
			} 
    }
}