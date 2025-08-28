/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:14 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/28 19:11:32 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_struct()
{
	printf("Number of Philosophers: [%d]\n", philo()->n_phil);
	printf("Time to die: [%d]\n", philo.tt_die);
	printf("Time to sleep: [%d]\n", philo.tt_sleep);
	printf("Time to eat: [%d]\n", philo.tt_eat);
	if (philo.number_of_meals)
		printf("Number of meals: [%d]\n", philo.number_of_meals);
}
int	main(int argc, char	**argv)
{
	if (parsing(argc, argv) == TRUE)
	{
		philo_info(argv);
	}
	return (0);
}
t_data *philo()
{
	t_data	s_philo;
	return (&s_philo);
}