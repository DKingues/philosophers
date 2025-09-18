/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:54:52 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/18 19:16:01 by dicosta-         ###   ########.fr       */
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
	if (error_message)
	{
		printf(ERR);
		printf(NOCLR"%s\n", error_message);
		exit(1);
	}
	exit(1);
}

void	print_error(char *error_message)
{
	if (error_message)
	{
		printf(ERR);
		printf(NOCLR"%s\n", error_message);
	}
}
long	get_time(void)
{
	struct timeval tv;

	if(gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (long)1000 + (tv.tv_usec / 1000));
}

 void precise_usleep(long time)
 {
 	long start;
	
	start = get_time();
	while (get_elapsed_time(start) < (time - 190) / 1e3)
		usleep(10);
 }

long	get_elapsed_time(long time)
{
	long curr_time;
	long elapsed;
	
	mtx_handler(&table()->mutex, LOCK);
	curr_time = get_time() - table()->simulation_start;
	elapsed = time - table()->simulation_start;
	mtx_handler(&table()->mutex, UNLOCK);
	return (curr_time - elapsed);
}

int		get_bool(int value)
{
	int	swapper;
	mtx_handler(&table()->mutex, LOCK);
	swapper = value;
	mtx_handler(&table()->mutex, UNLOCK);
	return (swapper);	
}

void print_status(int id, t_statuscode status)
{
	long time = get_time();
	//printf("time: %ld\t simstart: %ld\n", time, table()->simulation_start);
	mtx_handler(&table()->print, LOCK);
	if (table()->end_simulation == 0)
	{

		if (status == FORK)
		printf("%ld %d has taken a fork\n", time - table()->simulation_start, id);
		else if (status == EAT)
		printf("%ld %d is eating\n", time - table()->simulation_start, id);
		else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time - table()->simulation_start, id);
		else if (status == THINK)
		printf("%ld %d is thinking\n", time - table()->simulation_start, id);
	}
	else if (status == DEAD)
		printf("%ld %d died\n", time - table()->simulation_start, id);
	mtx_handler(&table()->print, UNLOCK);
}
void	*safe_malloc(size_t bytes)
{
	void *alloc;
	
	alloc = malloc(bytes);
	if (!alloc)
		error_exit("memory allocation fail.");
	return (alloc);
}