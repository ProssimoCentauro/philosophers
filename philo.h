#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define USAGE_ERROR "USAGE: ./philo 5 800 200 300 [5]"

typedef enum    e_codes
{
    CREATE,
    DETACH,
    JOIN,
    INIT,
    DESTROY,
    LOCK,
    UNLOCK,
}   t_mutex

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_counter;
	int					has_eated;
	long				last_meal_time;
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
	long				start_sim;
	long				end_sim;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;
#endif
