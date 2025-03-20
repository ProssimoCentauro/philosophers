/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:06 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:59:07 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	cycle_threads(t_table *table, t_codes code)
{
	long	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		if (thread_manager(&table->philos[i].thread_id, philo_routine,
				&table->philos[i], code))
		{
			table->force_exit = 1;
			return (1);
		}
	}
	return (0);
}

void	start_philos(t_table *table)
{
	pthread_t	monitor;

	if (thread_manager(&monitor, death_monitor, table, CREATE))
	{
		table->force_exit = 1;
		return ;
	}
	if (cycle_threads(table, CREATE))
	{
		return ;
	}
	if (thread_manager(&monitor, NULL, NULL, JOIN))
	{
		table->force_exit = 1;
		return ;
	}
	if (cycle_threads(table, JOIN))
	{
		return ;
	}
	free_and_exit(table);
}
