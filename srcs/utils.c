/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:54:52 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/01 16:59:43 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data *philo(void)
{
	static t_data	philo;
	return (&philo);
}

void	error_exit(char *error_message)
{
	printf(ERR);
	printf(NOCLR"%s\n", error_message);
	exit(EXIT_FAILURE);
}



void	*safe_malloc(size_t bytes)
{
	void *alloc;
	
	alloc = malloc(bytes);
	if (!alloc)
		error_exit("memory allocation fail.");
	return (alloc);
}