/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/06 17:26:59 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_philo()
{
	/*1 grab fork*/
	/*mf dead*/
}

void	start_dinner(void *data)
{
	int id;

	id = *(int *)data;
	while(1)
	{
		if (table()->philos[id].id % 2 != 0)
		{
			usleep(table()->time_to_eat);
		}
		printf("PHILO ID: %d\n", table()->philos[id].id);
		if (table()->philos[id].id % 2 == 0)
		{
			usleep(table()->time_to_eat);
		}
		printf("PHILO ID: %d\n", table()->philos[id].id);
	}
	return ;
}

void	set_philos(void)
{
	int i;

	i = 0;
	if (table()->max_meals == 0)
		return ;
	else if (table()->nbr_philo == 1)
		i = 0;
	else
	{
		while (i < table()->nbr_philo)
		{
			thread_handler(table()->philos[i].thread_id, (void *)start_dinner, (void *)(&i), CREATE);
			i++;
		}
	}
	i = 0;
	while (i < table()->nbr_philo)
	{
		thread_handler(table()->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
}
