/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/29 22:39:32 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int parse_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		error_exit("invalid number of arguments.");
	while (av[i])
	{
		if(!valid_input(av[i]))
			return (0);
		i++;
	}
	return (TRUE);
}

int valid_input(char *av)
{
	int i;
	int len;
	
	i = 0;
	len = 0;
	while (is_space(av[i]))
		i++;
	if (av[i] == '-')
		error_exit("only positive values allowed.");
	if (av[i] == '+')
		i++;
	while (av[i] >= '0' && av[i] <= '9')
	{
		i++;
		len++;
	}
	if (av[2] < 60 || av[3] < 60 || av[4] < 60)
		error_exit("times must be higher than 60ms.");
	if (len > 10)
		error_exit("a number is higher than INT_MAX.");
	return (TRUE);
}
