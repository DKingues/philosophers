/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:14 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/10 14:31:06 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_struct()
{
	int i;

	i = 0;
	printf("Number of Philosophers: [%d]\n", table()->nbr_philo);
	printf("Time to die: [%ld]\n", table()->time_to_die);
	printf("Time to sleep: [%ld]\n", table()->time_to_sleep);
	printf("Time to eat: [%ld]\n", table()->time_to_eat);
	printf("Number of meals: [%d]\n", table()->max_meals);
	printf("NOW SET TABLE\n");
	while (i < table()->nbr_philo)
	{
		printf("Philos ID: %d\n", table()->philos[i].id);
		//printf("Philos thread_ID: %ld\n", table()->philos[i].thread_id);
		printf("Philos last meal: %ld\n", table()->philos[i].last_meal_time);
		printf("Philos meal counter: %d\n", table()->philos[i].meal_counter);
		printf("Philos left fork: %d\n", table()->philos[i].left_fork->fork_id);
		printf("Philos right fork: %d\n", table()->philos[i].right_fork->fork_id);
		i++;
	}
}
int	main(int ac, char **av)
{
	/*
	1. Parse input: 5-6 args, no negatives, no alphabetical, check min time values
	*/

	if (parse_input(ac, av) == TRUE)
	{
		set_table(av);
		//print_struct();
		set_philos();
	}

	/*
	2. Organize input into structures.
	*/

	/*
	3. Start the feast
	*/

	/*
	4. Close, clean and cover leaks
	*/
	return (0);
}
