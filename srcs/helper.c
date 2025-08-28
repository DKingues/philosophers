/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:14:51 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/27 18:47:14 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/philo.h"
#include <stdio.h>

int	d_atoi(const char *str)
{
	int	i;
	int	number;
	
	i = 0;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	return (number);
}

"12312" 
