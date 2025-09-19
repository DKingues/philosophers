/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:00:56 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/19 17:36:35 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval tv;

	if(gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (long)1e3 + (tv.tv_usec / 1e3));
}

void precise_usleep(long time)
{
	long start;
	start = get_time();
	while (get_elapsed_time(start) < (time - 190))
		usleep(10);
}
 
long	get_elapsed_time(long time)
{
	long curr_time;
	
	mtx_handler(&table()->mutex, LOCK);
	curr_time = get_time();
	mtx_handler(&table()->mutex, UNLOCK);
	return ((curr_time - time) * 1000);
}