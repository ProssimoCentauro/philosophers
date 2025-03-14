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
}   t_codes;

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					status;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					has_eaten;
	long				meals_counter;
	long				last_meal_time;
	size_t	start_time;
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
	size_t	start_time;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

void    set_the_table(t_table   *table, char **args);
void    exit_error(char *str);
void    init_table(t_table *table);
void    mutex_manager(pthread_mutex_t *mtx, t_codes code);
void    thread_manager(pthread_t *thread, void *(*f)(void *),
        void *arg, t_codes code);
void    *safe_malloc(size_t bytes);

void    precise_usleep(size_t milliseconds);
size_t  get_msecs();
void    start_philos(t_table *table);


#endif
