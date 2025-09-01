/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:56:49 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/01 17:23:58 by dicosta-         ###   ########.fr       */
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

typedef	enum	s_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef struct	s_philo
{
	int		id;
	long	last_meal_time;
	int		meal_counter;
	
} t_philo;

typedef struct s_data
{
	int		nbr_philo;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
	int		max_meals;
	long	simulation_start;
	int		end_simulation;
} t_data;

/* FUNCTIONS */

// parser.c

int parse_input(int argc, char **args);
int valid_parameter(char *av);

// helper.c
long ft_atol(const char *str);

// utils.c

int		is_space(char c);
void	error_exit(char *error_message);
t_data *philo();

// info.c

void	get_philo_data(char **argv);

#endif