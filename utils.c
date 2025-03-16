#include "philo.h"

void	print_info(t_philo *philo, char *str)
{
    size_t  time;
    time = get_msecs() - philo->start_time;
    printf("%lu philo number %d %s\n", time, philo->id, str);
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
