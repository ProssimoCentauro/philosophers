#include "philo.h"

static void    *test(void *arg)
{
    int *id = arg;
    printf("philo %d started\n", *id);
    precise_usleep(1000000);
    return (NULL);
}

void    start_philos(t_table *table)
{
    long i;

    i = -1;
    while (++i < table->philo_nbr)
    {
        thread_manager(&table->philos[i].thread_id, test,
                &table->philos->id, CREATE);
    }
    i = -1;
    while (++i < table->philo_nbr)
    {
        thread_manager(&table->philos[i].thread_id, NULL, NULL, JOIN);
    }
}
