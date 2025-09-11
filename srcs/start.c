/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/11 17:40:39 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_philo(void)
{
	mtx_handler(&table()->philos[0].right_fork->fork, LOCK);
	print_status(table()->philos[0].id, FORK);
	usleep(table()->time_to_die);
	print_status(table()->philos[0].id, DEAD);
	error_exit("");
}

void	*start_dinner(void *data)
{
	int 	i;
	
	i = *(int *)data - 1;
	while (table()->sync == FALSE)
		continue;
	if (table()->philos[i].id % 2 != 0)
		usleep(table()->time_to_eat);
	table()->philos[i].last_meal_time = get_time();
	while (1)
	{
		table()->philos[i].last_meal_time = get_elapsed_time(table()->philos[i].last_meal_time);
		// if (table()->philos[i].last_meal_time > table()->time_to_die / 1000 && table()->philos[i].meal_counter != table()->max_meals && table()->end_simulation == 0)
		// {
		// 	table()->end_simulation = 1;
		// 	print_status(table()->philos[i].id, DEAD);
		// 	error_exit(NULL);
		// }
		if (i == -1000)
			printf("formal");
		else 
		{
			if (table()->philos[i].meal_counter != table()->max_meals)
			{
				mtx_handler(&table()->philos[i].left_fork->fork, LOCK);
				print_status(table()->philos[i].id, FORK);
				mtx_handler(&table()->philos[i].right_fork->fork, LOCK);
				print_status(table()->philos[i].id, FORK);
				if (table()->time_to_die / 1000 - table()->philos[i].last_meal_time - table()->time_to_eat / 1000 < 0 && table()->end_simulation == 0)
				{
					table()->end_simulation = 1;
					print_status(table()->philos[i].id, EAT);
					usleep(table()->time_to_die - table()->philos[i].last_meal_time * 1000);
					print_status(table()->philos[i].id, DEAD);
					error_exit(NULL);
				}
				print_status(table()->philos[i].id, EAT);
				usleep(table()->time_to_eat);
				table()->philos[i].last_meal_time = get_time();
				table()->philos[i].meal_counter++;
				mtx_handler(&table()->philos[i].right_fork->fork, UNLOCK);
				mtx_handler(&table()->philos[i].left_fork->fork, UNLOCK);
			}
			if (table()->time_to_die - table()->time_to_sleep < 0 && table()->end_simulation == 0)
			{
					table()->end_simulation = 1;
					print_status(table()->philos[i].id, SLEEP);
					usleep(table()->time_to_die);
					print_status(table()->philos[i].id, DEAD);
					error_exit(NULL);
			}
			print_status(table()->philos[i].id, SLEEP);
			usleep(table()->time_to_sleep);
			print_status(table()->philos[i].id, THINK);
		}
	}
}

void	set_philos(void)
{
	int i;

	i = 0;
	if (table()->max_meals == 0)
		return ;
	else if (table()->nbr_philo == 1)
	{
		table()->simulation_start = get_time();
		single_philo();
	}
	else
	{
		while (i < table()->nbr_philo)
		{
			thread_handler(&table()->philos[i].thread_id, start_dinner, (void *)&table()->philos[i].id, CREATE);
			i++;
		}
		table()->simulation_start = get_time();
		table()->sync = TRUE;
		i = 0;
		while (i < table()->nbr_philo)
		{
			thread_handler(&table()->philos[i].thread_id, NULL, NULL, JOIN);
			i++;
		}
	}
	table()->sync = FALSE;
}
