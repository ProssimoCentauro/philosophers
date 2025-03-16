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
    print_meals(table);
    return (1);
}

static int check_death(t_table *table)
{
    long    t_d = table->time_to_die;
    t_philo *philos;
    int i;

    i = -1;
    philos = table->philos;
    while (++i < table->philo_nbr)
    {
        if (get_msecs() - table->philos[i].last_meal_time >= t_d)
            return (1);
    }
    return (0);
}

void    *dead_monitor(void *arg)
{
    t_table *table = (t_table *)arg;
    printf("MONITOR STARTED!\n");
    while (42)
    {
    /*    if (check_death(table) || check_all_ate(table))
            exit(0);*/
        /*print_meals(table);
        precise_usleep(2000);*/
        if (check_all_ate(table))
        {
            printf("All the philos have eaten!\n");
            exit(0);
        }
    }
    return (NULL);
}
