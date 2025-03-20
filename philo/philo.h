/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:57:15 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:57:24 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define USAGE_ERROR "USAGE: ./philo 5 800 200 300 [5]"

typedef enum e_codes
{
	CREATE,
	DETACH,
	JOIN,
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}						t_codes;

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					is_eating;
	long				meals_counter;
	size_t				last_meal_time;
	size_t				start_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				limit_meals;
	int				end_sim;
    int force_exit;
	size_t				start_time;
	pthread_mutex_t		death_mtx;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

int					exit_error(char *str, void (*f)(void),
        int code, int print);
void					print_usage_error(void);

void					set_the_table(t_table *table, char **args);
int					init_table(t_table *table);
int					mutex_manager(pthread_mutex_t *mtx, t_codes code);
int					thread_manager(pthread_t *thread, void *(*f)(void *),
							void *arg, t_codes code);
void					*safe_malloc(size_t bytes);

void					precise_usleep(size_t milliseconds);
size_t					get_msecs(void);
void					start_philos(t_table *table);

void					print_info(t_philo *philo, char *str);

void					*death_monitor(void *arg);

void					dream(t_philo *philo);
void					think(t_philo *philo);

void					*philo_routine(void *philosopher);

void					free_and_exit(t_table *table);

int						check_args(char **args);
#endif
