#include "philo.h"

void	precise_usleep(size_t milliseconds)
{
	size_t	start;

    start = (size_t)get_secs;
    while (((size_t)get_secs - start) < milliseconds)
        usleep (500);
}

size_t	get_secs()
{
	struct	timeval	time;
    size_t  res;

	gettimeofday(&time, NULL);
	res  = time.tv_sec;
    return (time.tv_sec);
}
