/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:14 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/01 16:03:43 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_struct()
{
	printf("Number of Philosophers: [%d]\n", philo()->nbr_philo);
	printf("Time to die: [%ld]\n", philo()->time_to_die);
	printf("Time to sleep: [%ld]\n", philo()->time_to_sleep);
	printf("Time to eat: [%ld]\n", philo()->time_to_eat);
	if (philo()->max_meals)
		printf("Number of meals: [%d]\n", philo()->max_meals);
}
int	main(int ac, char	**av)
{
	/*
	1. Parse input: 5-6 args, no negatives, no alphabetical, check min time values
	*/

	if (parse_input(ac, av) == TRUE)
	{
		get_philo_data(av);
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
	print_struct();
	return (0);
}
