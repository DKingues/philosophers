/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:14:51 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/01 15:21:34 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long ft_atol(const char *str)
{
	int		i;
	long	number;
	
	i = 0;
	number = 0;
	while (is_space(str[i]))
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


