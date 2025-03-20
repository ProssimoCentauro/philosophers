/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:14 by rtodaro           #+#    #+#             */
/*   Updated: 2025/03/19 15:58:15 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_manager(pthread_mutex_t *mtx, t_codes code)
{
	int	ret;

	ret = 1;
	if (code == INIT)
		ret = pthread_mutex_init(mtx, NULL);
	else if (code == DESTROY)
		ret = pthread_mutex_destroy(mtx);
	else if (code == LOCK)
		ret = pthread_mutex_lock(mtx);
	else if (code == UNLOCK)
		ret = pthread_mutex_unlock(mtx);
	if (ret != 0)
		return (exit_error("\nMUTEX ERROR!\n", NULL, ret, 1));
    return (ret);
}

int	thread_manager(pthread_t *thread, void *(*f)(void *), void *arg,
		t_codes code)
{
	int	ret;

	ret = 1;
	if (code == CREATE)
		ret = pthread_create(thread, NULL, f, arg);
	else if (code == DETACH)
		ret = pthread_detach(*thread);
	else if (code == JOIN)
		ret = pthread_join(*thread, NULL);
	if (ret != 0)
		return (exit_error("\nTHREAD ERROR!\n", NULL, ret, 1));
    return (ret);
}
