/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:56 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 18:03:00 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dream(t_philo *philo)
{
	print_info(philo, "is sleeping");
	precise_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_info(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	mutex_manager(&philo->left_fork->fork, LOCK);
	print_info(philo, "has taken a fork");
	if (philo->table->philo_nbr == 1)
	{
		mutex_manager(&philo->left_fork->fork, UNLOCK);
		while (1)
		{
			mutex_manager(&philo->table->death_mtx, LOCK);
			if (philo->table->end_sim == 1)
				break ;
			mutex_manager(&philo->table->death_mtx, UNLOCK);
		}
		mutex_manager(&philo->table->death_mtx, UNLOCK);
		return ;
	}
	mutex_manager(&philo->right_fork->fork, LOCK);
	print_info(philo, "has taken a fork");
	philo->is_eating = 1;
	print_info(philo, "is eating");
	philo->last_meal_time = get_msecs();
	philo->meals_counter++;
	precise_usleep(philo->table->time_to_eat);
	philo->is_eating = 0;
	mutex_manager(&philo->left_fork->fork, UNLOCK);
	mutex_manager(&philo->right_fork->fork, UNLOCK);
}

void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		precise_usleep(1);
	while (42)
	{
		mutex_manager(&philo->table->death_mtx, LOCK);
		if (philo->table->end_sim == 1)
			break ;
		mutex_manager(&philo->table->death_mtx, UNLOCK);
		eat(philo);
		dream(philo);
		think(philo);
	}
	mutex_manager(&philo->table->death_mtx, UNLOCK);
    return (NULL);
}
