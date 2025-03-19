/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:05 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 16:00:21 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int i)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->left_fork = &forks[i];
	if (i == 0)
		philo->right_fork = &forks[philo_nbr - 1];
	else
		philo->right_fork = &forks[i - 1];
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->last_meal_time = (size_t)get_msecs();
		philo->meals_counter = 0;
		philo->is_eating = 0;
		philo->start_time = (size_t)get_msecs();
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

void	init_table(t_table *table)
{
	long	i;

	i = -1;
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->end_sim = 0;
	mutex_manager(&table->death_mtx, INIT);
	while (++i < table->philo_nbr)
		mutex_manager(&table->forks[i].fork, INIT);
	philo_init(table);
}
