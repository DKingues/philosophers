/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:21:10 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/28 18:44:59 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	philo_info(char **argv)
{
	t_data	philo;
	
	philo.n_phil = d_atoi(argv[1]);
	philo.tt_die = d_atoi(argv[2]);
	philo.tt_sleep = d_atoi(argv[3]);
	philo.tt_eat = d_atoi(argv[4]);
	if (argv[5])
		philo.number_of_meals = d_atoi(argv[5]);
	return (philo);
}