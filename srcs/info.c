/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:21:10 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/29 22:34:02 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_philo_data(char **argv)
{
	philo()->nbr_philo = ft_atol(argv[1]);
	philo()->time_to_die = ft_atol(argv[2]) * 1e3;
	philo()->time_to_sleep = ft_atol(argv[3]) * 1e3;
	philo()->time_to_eat = ft_atol(argv[4]) * 1e3;
	if (argv[5])
		philo()->max_meals = ft_atol(argv[5]);
	else
		philo()->max_meals = -1;
}