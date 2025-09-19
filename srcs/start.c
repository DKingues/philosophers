/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/19 18:14:21 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	single_philo(void)
{
	mtx_handler(&table()->philos[0].right_fork->fork, LOCK);
	print_status(table()->philos[0].id, FORK);
	usleep(table()->time_to_die);
	print_status(table()->philos[0].id, DEAD);
	return ;
}
// void	synchronize_threads(void)
// {	
// 	while(1)
// 	{
// 		mtx_handler(&table()->mutex, LOCK);
// 		if(table()->all_sync == true)
// 			break ;
// 		mtx_handler(&table()->mutex, UNLOCK);
// 		usleep(500);
// 	}
// 	mtx_handler(&table()->mutex, UNLOCK);
// }

void	get_forks(int id)
{
	mtx_handler(&table()->philos[id].left_fork->fork, LOCK);
	print_status(table()->philos[id].id, FORK);
	mtx_handler(&table()->philos[id].right_fork->fork, LOCK);
	print_status(table()->philos[id].id, FORK);
}

void	eat(int id)
{
	mtx_handler(&table()->end, LOCK);
	if (table()->time_to_die - table()->philos[id].last_meal_time - table()->time_to_eat < 0 && table()->end_simulation == 0)
	{
		table()->end_simulation = 1;
		print_status(table()->philos[id].id, EAT);
		precise_usleep(table()->time_to_die - table()->philos[id].last_meal_time);
		print_status(table()->philos[id].id, DEAD);
		mtx_handler(&table()->end, UNLOCK);
		put_forks(id);
	}
	mtx_handler(&table()->end, UNLOCK);
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
	mtx_handler(&table()->end, LOCK);
	if (table()->time_to_die - table()->time_to_sleep < 0 && table()->end_simulation == 0)
	{
		table()->end_simulation = 1;
		print_status(table()->philos[id].id, SLEEP);
		precise_usleep(table()->time_to_die);
		print_status(table()->philos[id].id, DEAD);
		mtx_handler(&table()->end, UNLOCK);
	}
	mtx_handler(&table()->end, UNLOCK);
	print_status(table()->philos[id].id, SLEEP);
	precise_usleep(table()->time_to_sleep);
	print_status(table()->philos[id].id, THINK);
}

void	*start_dinner(void *data)
{
	int 	i; 
	
	i = *(int *)data - 1;
	usleep(SYNCH);
	if (table()->philos[i].id % 2 != 0)
		usleep(table()->time_to_eat);
	table()->philos[i].last_meal_time = get_time();
	while (!get_value(table()->end_simulation))
	{
		table()->philos[i].last_meal_time = get_elapsed_time(table()->philos[i].last_meal_time);
		get_forks(i);
		eat(i);
		put_forks(i);
		sleep_think(i);
	}
	return (NULL);
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
		mtx_handler(&table()->mutex, LOCK);
		table()->simulation_start = get_time();
		mtx_handler(&table()->mutex, UNLOCK);
		i = -1;
		while (++i < table()->nbr_philo)
			thread_handler(&table()->philos[i].thread_id, NULL, NULL, JOIN);
	}
}
