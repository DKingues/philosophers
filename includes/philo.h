/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:56:49 by dicosta-          #+#    #+#             */
/*   Updated: 2025/09/06 17:17:55 by dicosta-         ###   ########.fr       */
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

# define EPERM 1
# define ESRCH 3
# define EAGAIN 11
# define ENOMEN 12
# define EBUSY 16
# define EINVAL 22
# define EDEADLK 35
# define NOCLR "\033[0m"
# define RED "\033[1;31m"
# define ERR "\033[1;31m""Error: ""\033[0m"
# define TRUE 1
# define FALSE 0

/* STRUCTURES */

typedef	enum	s_statuscode
{
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_statuscode;

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

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				fork_id;
} t_fork;

typedef struct	s_philo
{
	int			id;
	long		last_meal_time;
	int			meal_counter;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
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
	t_fork	*forks;
	t_philo	*philos;
} t_data;

/* FUNCTIONS */

// parser.c

int parse_input(int argc, char **args);
int valid_parameter(char *av);
void	set_philos(void);
// helper.c

int		is_space(char c);
long	ft_patol(const char *str);

// utils.c

t_data *table();
void	error_exit(char *error_message);
void	*safe_malloc(size_t bytes);
void 	print_status(int id, t_statuscode status);

// info.c

void	set_table(char **argv);

// thread_utils.c

void	thread_handler(pthread_t thread, void *(*func)(void *), void *data, t_opcode opcode);
void	mtx_handler(pthread_mutex_t *mutex, t_opcode opcode);

#endif