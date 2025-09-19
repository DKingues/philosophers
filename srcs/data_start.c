/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:21:10 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/19 17:54:22 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	create_philos()
{
	int	i;

	i = 0;
	while (i < table()->nbr_philo)
	{
		table()->philos[i].id = i + 1;
		table()->philos[i].last_meal_time = get_time();
		table()->philos[i].meal_counter = 0;
		table()->philos[i].right_fork = &table()->forks[i];
		table()->philos[i].left_fork = &table()->forks[(table()->philos[i].id) % table()->nbr_philo];
		i++;
	}
}

static void	create_forks()
{
	int	i;

	i = 0;
	while (i < table()->nbr_philo)
	{
		mtx_handler(&table()->forks[i].fork, INIT);
		table()->forks[i].fork_id = i;
		i++;
	}
}

int	set_table(char **argv)
{
	table()->nbr_philo = ft_patol(argv[1]);
	table()->time_to_die = ft_patol(argv[2]) * 1e3;
	table()->time_to_eat = ft_patol(argv[3]) * 1e3;
	table()->time_to_sleep = ft_patol(argv[4]) * 1e3;
	table()->forks = malloc(sizeof(t_fork) * table()->nbr_philo);
	table()->philos = malloc(sizeof(t_philo) * table()->nbr_philo);
	if (!table()->forks || !table()->philos)
		return (0);
	if (argv[5])
		table()->max_meals = ft_patol(argv[5]);
	else
		table()->max_meals = -1;
	table()->end_simulation = 0;
	mtx_handler(&table()->sync, INIT);
	mtx_handler(&table()->end, INIT);
	mtx_handler(&table()->mutex, INIT);
	create_forks();
	create_philos();
	return (1);
}

void	thread_handler(pthread_t *thread, void *(*func)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(thread, NULL, func, data);
	else if (opcode == JOIN)
		pthread_join(*thread, NULL);
	else if (opcode == DETACH)
		pthread_detach(*thread);
}

void	mtx_handler(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
}
