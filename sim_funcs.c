#include "philo.h"

void	start_philos(t_table *table)
{
	long		i;
	pthread_t	monitor;

	i = -1;
	thread_manager(&monitor, dead_monitor, table, CREATE);
	while (++i < table->philo_nbr)
	{
		thread_manager(&table->philos[i].thread_id, philo_routine,
			&table->philos[i], CREATE);
	}
	i = -1;
	thread_manager(&monitor, NULL, NULL, JOIN);
	while (++i < table->philo_nbr)
	{
		thread_manager(&table->philos[i].thread_id, NULL, NULL, JOIN);
	}
	free_and_exit(table);
}
