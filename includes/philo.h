/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:56:49 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/27 18:04:02 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// Helper Libraries

#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free
#include <string.h>    // memset
#include <unistd.h>    // write, usleep
#include <sys/time.h>  // gettimeofday
#include <pthread.h>   // pthread_* functions and pthread_mutex_*

// Alias

#define TRUE 1
#define FALSE 1

// Functions

int	parsing(char **args);

#endif