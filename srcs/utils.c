/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:54:52 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/06 16:33:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data *table(void)
{
	static t_data	table;
	return (&table);
}

void	error_exit(char *error_message)
{
	printf(ERR);
	printf(NOCLR"%s\n", error_message);
	exit(EXIT_FAILURE);
}

__uint64_t	get_time()
{
	struct timeval tv;

	if(gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_usec / 1000);
}

void print_status(int id, t_statuscode status)
{
	long time;

	time = get_time();
	if (status == EAT)
		printf("[%ld] - %d is eating.\n", time, id);
	else if (status == SLEEP)
		printf("[%ld] - %d is sleeping.\n", time, id);
	else if (status == THINK)
		printf("[%ld] - %d is thinking.\n", time, id);
	else if (status == DEAD)
		printf("[%ld] - %d died.\n", time, id);
}
void	*safe_malloc(size_t bytes)
{
	void *alloc;
	
	alloc = malloc(bytes);
	if (!alloc)
		error_exit("memory allocation fail.");
	return (alloc);
}