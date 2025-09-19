/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:54:52 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/19 18:07:51 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long ft_patol(const char *str)
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

void	print_error(char *error_message)
{
	if (error_message)
	{
		printf(ERR);
		printf(NOCLR"%s\n", error_message);
	}
}

int		get_value(int value)
{
	int	swapper;
	mtx_handler(&table()->mutex, LOCK);
	swapper = value;
	mtx_handler(&table()->mutex, UNLOCK);
	return (swapper);	
}

void print_status(int id, t_statuscode status)
{
	long time;

	time = get_time();
	mtx_handler(&table()->print, LOCK);
	if (table()->end_simulation == 0)
	{

		if (status == FORK)
		printf("%ld %d has taken a fork\n", time - table()->simulation_start, id);
		else if (status == EAT)
		printf("%ld %d is eating\n", time - table()->simulation_start, id);
		else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time - table()->simulation_start, id);
		else if (status == THINK)
		printf("%ld %d is thinking\n", time - table()->simulation_start, id);
	}
	else if (status == DEAD)
		printf("%ld %d died\n", time - table()->simulation_start, id);
	mtx_handler(&table()->print, UNLOCK);
}
