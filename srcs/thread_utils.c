/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:23:01 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/18 19:15:07 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	thread_err_check(int error)
{
	if (error == 0)
		return ;
	else if (error == EAGAIN)
		error_exit("Resource temporarily unavailable.");
	else if (error == EINVAL)
		error_exit("Invalid argument.");
	else if (error == ESRCH)
		error_exit("No such process.");
	else if (error == EDEADLK)
		error_exit("Resource deadlock avoided");
	else if (error == EPERM)
		error_exit("Operation not permitted.");
			
}

void	thread_handler(pthread_t *thread, void *(*func)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		thread_err_check(pthread_create(thread, NULL, func, data));
	else if (opcode == JOIN)
		thread_err_check(pthread_join(*thread, NULL));
	else if (opcode == DETACH)
		thread_err_check(pthread_detach(*thread));
}

static void	mtx_err_check(int error)
{
	if (error == 0)
		return ;
	else if (error == EINVAL)
		error_exit("The mutex has not been properly initialized.");
	else if (error == ENOMEN)
		error_exit ("Resource temporarily unavailable.");
	else if (error == EDEADLK)
		error_exit("The mutex is already locked by the calling thread.");
	else if (error == EBUSY)
		error_exit("The mutex could not be acquired because it was currently locked.");
	else if (error == EPERM)
		error_exit("The calling thread does not own the mutex.");
}

void	mtx_handler(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == INIT)
		mtx_err_check(pthread_mutex_init(mutex, NULL));
	else if (opcode == LOCK)
		mtx_err_check(pthread_mutex_lock(mutex));
	else if (opcode == UNLOCK)
		mtx_err_check(pthread_mutex_unlock(mutex));
	else if (opcode == DESTROY)
		mtx_err_check(pthread_mutex_destroy(mutex));
}