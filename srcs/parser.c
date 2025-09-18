/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/18 19:08:23 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int check_times(char **av)
{
	if (ft_patol(av[2]) < 60 || ft_patol(av[3]) < 60 || ft_patol(av[4]) < 60)
		return (FALSE);
	return (TRUE);
}

int check_intmax(char **av)
{
	int	i;
	long number;
	int len;
	
	i = 1;
	while (av[i])
	{
		len = 0;
		number = ft_patol(av[i]);
		while (number != 0)
		{
			number /= 10;
			len++;
			if (len > 10)
				return (FALSE);
		}
		if (ft_patol(av[i]) > 2147483647)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int check_digit(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while(is_space(av[i][j]))
			j++;
		if (av[i][j] == '+')
			j++;
		if (!(av[i][j] && (av[i][j] >= '0' && av[i][j] <= '9')))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int check_negatives(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		while(is_space(av[i][j]))
			j++;
		if (av[i][j] == '-')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int parse_input(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (print_error("invalid number of arguments."), FALSE);
	if (check_negatives(av) == FALSE)
		return (print_error("all values must be positive."), FALSE);
	if (check_digit(av) == FALSE)
		return (print_error("all values must be numerical."), FALSE);
	if (check_intmax(av) == FALSE)
		return (print_error("numbers cannot be higher than INT_MAX."), FALSE);
	if (check_times(av) == FALSE)
		return (print_error("times must be higher than 60ms."), FALSE);
	return (TRUE);
}
