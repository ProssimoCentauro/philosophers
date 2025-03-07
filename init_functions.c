#include "philo.h"


void    init_table(t_table *table)
{
    long i;

    i = 0;
    table->forks = safe_malloc(sizeof(t_fork) * philo_nbr);
    table->philos = safe_malloc(sizeof(t_philo) * philo_nbr);
}
