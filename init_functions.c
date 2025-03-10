#include "philo.h"

static	void	assign_forks(t_philo *philo,
		t_fork *forks, int	philo_pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;

	philo->right_fork = &forks[(philo_pos + 1) % philo_nbr];
	philo->left_fork = &forks[philo_pos];
	if (philo->id % 2)
	{
		philo->right_fork = &forks[philo_pos];
		philo->left_fork = &forks[(philo_pos + 1) % philo_nbr];
	}
}

static	void	philo_init(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->has_eaten = 0;
		philo->meals_counter = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

void    init_table(t_table *table)
{
    long i;

    i = -1;
    table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
    table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);

    while (++i < table->philo_nbr)
    {
	    mutex_manager(&table->forks[i].fork, INIT);
	    table->forks[i].fork_id = i;
    }
}
