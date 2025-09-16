/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:21:10 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/16 19:59:03 by dicosta-         ###   ########.fr       */
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
		//table()->philos[i].thread_id = pthread_create(NULL, NULL, NULL, NULL);
		table()->philos[i].meal_counter = 0;
		table()->philos[i].right_fork = &table()->forks[i];
		table()->philos[i].left_fork = &table()->forks[(table()->philos[i].id) % table()->nbr_philo];
		// printf("Philo ID: %d\n", table()->philos[i].id);
		// printf("left fork ID: %d\n", table()->philos[i].left_fork->fork_id);
		// printf("right fork ID: %d\n", table()->philos[i].right_fork->fork_id);
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

void	set_table(char **argv)
{
	table()->nbr_philo = ft_patol(argv[1]);
	table()->time_to_die = ft_patol(argv[2]) * 1e3;
	table()->time_to_eat = ft_patol(argv[3]) * 1e3;
	table()->time_to_sleep = ft_patol(argv[4]) * 1e3;
	table()->forks = safe_malloc(sizeof(t_fork) * table()->nbr_philo);
	if (argv[5])
		table()->max_meals = ft_patol(argv[5]);
	else
		table()->max_meals = -1;
	table()->end_simulation = FALSE;
	table()->all_sync = FALSE;
	mtx_handler(&table()->sync, INIT);
	mtx_handler(&table()->end, INIT);
	create_forks();
	table()->philos = safe_malloc(sizeof(t_philo) * table()->nbr_philo);
	create_philos();
}
