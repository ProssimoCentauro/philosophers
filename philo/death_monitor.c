/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:57:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 17:52:06 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_ate(t_table *table)
{
	long	i;
	t_philo	*philos;

	i = -1;
	philos = table->philos;
	if (table->limit_meals == -1)
		return (0);
	while (++i < table->philo_nbr)
	{
		if (philos[i].meals_counter < table->limit_meals)
			return (0);
	}
	return (1);
}

static int	check_death(t_table *table)
{
	size_t	t_d;
	int		i;
	t_philo	*philos;

	t_d = table->time_to_die;
	i = -1;
	philos = table->philos;
	while (++i < table->philo_nbr)
	{
		mutex_manager(&table->death_mtx, LOCK);
		if (get_msecs() - philos[i].last_meal_time >= t_d
			&& philos[i].is_eating == 0)
		{
			mutex_manager(&table->death_mtx, UNLOCK);
			print_info(&philos[i], "died");
			return (1);
		}
		mutex_manager(&table->death_mtx, UNLOCK);
	}
	return (0);
}

void	free_and_exit(t_table *table)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = table->forks;
	while (i < table->philo_nbr)
	{
		mutex_manager(&forks[i].fork, DESTROY);
		i++;
	}
	free(table->forks);
	free(table->philos);
}

void	*death_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (42)
	{
		if (table->force_exit == 1)
		{
			table->end_sim = 1;
			return (NULL);
		}
		if (check_death(table) || check_all_ate(table))
		{
			mutex_manager(&table->death_mtx, LOCK);
			table->end_sim = 1;
			mutex_manager(&table->death_mtx, UNLOCK);
			break ;
		}
	}
	return (NULL);
}
