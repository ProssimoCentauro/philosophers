#include "philo.h"

void	precise_usleep(size_t milliseconds)
{
	size_t	start;


}

size_t	get_timestamp()
{
	struct	timeval	time;

	gettimeofday(&time, NULL);
//	return (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time.tv_usec);
}
/*
void    start_simulation(t_table *table)
{
    mutex_manager()
}*/
