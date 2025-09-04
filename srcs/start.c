/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/04 17:26:21 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_philo()
{
	/*1 grab fork*/
	/*mf dead*/
}

void	start_dinner()
{
	if (table()->philos->id % 2 != 0)
		mtx_handler(table()->philos->right_fork, LOCK);
	else
		mtx_handler(table()->philos->left_fork, LOCK);
	
}

void	set_philos()
{
	int i;

	i = 0;
	if (table()->max_meals == 0)
		return ;
	else if (table()->nbr_philo == 1)
		//single_philo()
		;
	else
	{
		while (i < table()->nbr_philo)
		{
			thread_handler(table()->philos[i].thread_id, start_dinner, NULL, CREATE);
			i++;
		}
	}
}
