/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:46:45 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/20 10:02:59 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precise_sleep.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
long    get_time(void)
{
    struct timeval  tp;
    long            milliseconds;

    gettimeofday(&tp, NULL);
    milliseconds = tp.tv_sec * 1000;
    milliseconds += tp.tv_usec / 1000; 
    return (milliseconds);
}



long ft_precise_sleep(int milliseconds, long h_die, int index)
{
     
    long start_time;
    start_time = get_time();
     
    while (get_time() - start_time < milliseconds)
    {
        
        if(get_time()  > h_die)
        {
            printf("%ld %d has died\n", get_time(), index);
            exit(0);
        }
       
    	usleep(1 * 1500);		 
  
    } 
    return(start_time = get_time());	 
}

/* void ft_precise_sleep(int milliseconds)
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
} */