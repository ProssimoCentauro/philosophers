#include "philo.h"
/*
static void    *test(void *philoper)
{
	t_philo	*philo = (t_philo *)philoper;
    int *id = &philo->id;
    size_t	start_time = philo->table->start_time;
    start_time = (size_t)get_msecs() - start_time;
    printf("%lu philo %d started\n", start_time, *id);
    precise_usleep(1000);
    return (NULL);
}*/
/*
static	void	*test(void *philosopher)
{
	t_philo	*philo = (t_philo *)philosopher;
	int	id = philo->id;
	//printf("%lu philo %d start\n", time, id);
	printf("start time: %lu\n", philo->start_time);
	printf("curr  time: %lu\n", get_msecs());
	printf("salv  time: %lu\n", time);
	printf("      time: %lu\n\n",get_msecs() - philo->start_time);
	return (NULL);
}*/


static  void    *test(void  *philosopher)
{
    t_philo *philo = (t_philo *)philosopher;
    dream(philo);
    think(philo);
    /*print_info(philo, "Has taken a fork");
    precise_usleep(5000);
    print_info(philo, "Is thinking");
*/
    //printf("%p\n", philo->left_fork);
    //printf("%p\n\n", philo->right_fork);
    
}

void    start_philos(t_table *table)
{
    long i;
    pthread_t   monitor;

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
    //while (42)
    //    dead_monitor(table);
    //thread_manager(&monitor, NULL, NULL, JOIN);
}
