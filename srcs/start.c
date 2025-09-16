/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/16 21:08:01 by dicosta-         ###   ########.fr       */
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
void	synchronize_threads(void)
{	
		mtx_handler(&table()->sync, LOCK);
		while(table()->all_sync == FALSE)
			continue;
		mtx_handler(&table()->sync, UNLOCK);
}

void	get_forks(int id)
{
	mtx_handler(&table()->philos[id].left_fork->fork, LOCK);
	print_status(table()->philos[id].id, FORK);
	mtx_handler(&table()->philos[id].right_fork->fork, LOCK);
	print_status(table()->philos[id].id, FORK);	
}

void	eat(int id)
{
	if (table()->time_to_die / 1000 - table()->philos[id].last_meal_time - table()->time_to_eat / 1000 < 0 && table()->end_simulation == 0)
	{
		mtx_handler(&table()->end, LOCK);
		table()->end_simulation = 1;
		print_status(table()->philos[id].id, EAT);
		precise_usleep(table()->time_to_die - table()->philos[id].last_meal_time * 1000);
		print_status(table()->philos[id].id, DEAD);
		error_exit(NULL);
		mtx_handler(&table()->end, UNLOCK);
	}
	print_status(table()->philos[id].id, EAT);
	precise_usleep(table()->time_to_eat);
	table()->philos[id].last_meal_time = get_time();
	table()->philos[id].meal_counter++;
}

void	put_forks(int id)
{
	mtx_handler(&table()->philos[id].left_fork->fork, UNLOCK);
	mtx_handler(&table()->philos[id].right_fork->fork, UNLOCK);
}

void	sleep_think(int id)
{
	if (table()->time_to_die - table()->time_to_sleep < 0 && table()->end_simulation == 0)
	{
		mtx_handler(&table()->end, LOCK);
		table()->end_simulation = 1;
		print_status(table()->philos[id].id, SLEEP);
		precise_usleep(table()->time_to_die);
		print_status(table()->philos[id].id, DEAD);
		mtx_handler(&table()->end, UNLOCK);
		error_exit(NULL);
	}
	print_status(table()->philos[id].id, SLEEP);
	precise_usleep(table()->time_to_sleep);
	print_status(table()->philos[id].id, THINK);
}

void	*start_dinner(void *data)
{
	int 	i;
	
	i = *(int *)data - 1;
	synchronize_threads();
	if (table()->philos[i].id % 2 != 0)
		usleep(table()->time_to_eat);
	table()->philos[i].last_meal_time = get_time();
	while (1)
	{
		table()->philos[i].last_meal_time = get_elapsed_time(table()->philos[i].last_meal_time);
		if (table()->philos[i].meal_counter != table()->max_meals)
		{
			get_forks(i);
			eat(i);
			put_forks(i);
		}
		sleep_think(i);
	}
}

void	set_philos(void)
{
	int i;

	i = -1;
	if (table()->max_meals == 0)
		return ;
	else if (table()->nbr_philo == 1)
	{
		table()->simulation_start = get_time();
		single_philo();
	}
	else
	{
		while (++i < table()->nbr_philo)
			thread_handler(&table()->philos[i].thread_id, start_dinner, (void *)&table()->philos[i].id, CREATE);
		table()->simulation_start = get_time();
		table()->all_sync = TRUE;
		i = -1;
		while (++i < table()->nbr_philo)
			thread_handler(&table()->philos[i].thread_id, NULL, NULL, JOIN);
	}
}
