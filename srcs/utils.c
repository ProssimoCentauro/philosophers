/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:13 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:59:14 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_philo *philo, char *str)
{
	size_t	time;

	time = get_msecs() - philo->start_time;
	mutex_manager(&philo->table->death_mtx, LOCK);
	if (philo->table->end_sim == 1)
	{
		mutex_manager(&philo->table->death_mtx, UNLOCK);
		return ;
	}
	mutex_manager(&philo->table->death_mtx, UNLOCK);
	printf("%lu philo %d %s\n", time, philo->id, str);
}

void	precise_usleep(size_t milliseconds)
{
	size_t	start;

	start = (size_t)get_msecs();
	while (((size_t)get_msecs() - start) < milliseconds)
		usleep(100);
}

size_t	get_msecs(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
