/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:13:55 by caquinta          #+#    #+#             */
/*   Updated: 2022/08/30 10:16:01 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_error.h"
#include <stdlib.h>

void	check_error(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Número de argumentos incorrecto.\n");
		exit(1);
	}	
}
