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

/*
static  int start_threads(t_table *table)
{

}*/

void	start_philos(t_table *table)
{
	long		i;
	pthread_t	monitor;

	i = -1;
	if (thread_manager(&monitor, death_monitor, table, CREATE))
    {
        table->force_exit = 1;
        return ; 
    }
    while (++i < table->philo_nbr)
	{
		if (thread_manager(&table->philos[i].thread_id,
                    philo_routine, &table->philos[i], CREATE))
        {
            table->force_exit = 1;
            return ;
        }
    }
	i = -1;
	if (thread_manager(&monitor, NULL, NULL, JOIN))
    {
        table->force_exit = 1;
        return ;
    }
	while (++i < table->philo_nbr)
	{
		if (thread_manager(&table->philos[i].thread_id,
                    NULL, NULL, JOIN))
        {
            table->force_exit = 1;
            return ;
        }
	}
	free_and_exit(table);
}
