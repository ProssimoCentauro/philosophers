#include "philo.h"

static void print_meals(t_table *table)
{
    int i = -1;
    t_philo *philos = table->philos;
    while (++i < table->philo_nbr)
    {
        printf("philo %d, %ld meals\n", philos[i].id,
                philos[i].meals_counter);
    }
}

static int check_all_ate(t_table *table)
{
    long    i;
    t_philo *philos;

    i = -1;
    philos = table->philos;
    if (table->limit_meals == -1)
        return (0);
    while (++i < table->philo_nbr)
    {
        if (philos[i].meals_counter < table->limit_meals)
            return (0);
    }
    //print_meals(table);
    return (1);
}

static int check_death(t_table *table)
{
    long    t_d;
    int i;
    t_philo *philos;

    t_d = table->time_to_die;
    i = -1;
    philos = table->philos;
    while (++i < table->philo_nbr)
    {
        if (get_msecs() - philos[i].last_meal_time >= t_d &&
                philos[i].is_eating == 0)
        {
            print_info(&philos[i], "died");
            return (1);
        }
    }
    return (0);
}

static  void    free_and_exit(t_table *table)
{
    int i;
    t_philo    *philos;
    t_fork     *forks;

    i = -1;
    philos = table->philos;
    forks = table->forks;
    /*while (++i < table->philo_nbr)
    {
        //thread_manager(&philos[i].thread_id, NULL, NULL, DETACH);
        mutex_manager(&forks[i].fork, DESTROY);
    }*/
    free(table->forks);
    free(table->philos);
    printf("free and exit\n");
    exit(0);
}

void    *dead_monitor(void *arg)
{
    t_table *table = (t_table *)arg;
    printf("MONITOR STARTED!\n");
    while (42)
    {
        if (check_death(table) || check_all_ate(table))
            free_and_exit(arg);
            //exit(0);
    }
    return (NULL);
}
