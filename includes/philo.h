/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:56:49 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/28 18:39:58 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

/* LIBRARIES */

#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free
#include <string.h>    // memset
#include <unistd.h>    // write, usleep
#include <sys/time.h>  // gettimeofday
#include <pthread.h>   // pthread_* functions and pthread_mutex_*

/* ALIAS */

# define NOCLR "\033[0m"
# define RED "\033[1;31m"
# define ERR "\033[1;31m""Error: ""\033[0m"
# define TRUE 1
# define FALSE 0

/* STRUCTURES */

typedef struct s_data
{
	int	n_phil;
	int tt_die;
	int tt_sleep;
	int tt_eat;
	int number_of_meals;
} t_data;

/* FUNCTIONS */

// parser.c

int parsing(int argc, char **args);

// helper.c

int	d_atoi(const char *str);

// info.c

t_data	philo_info(char **argv);

#endif