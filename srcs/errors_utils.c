#include "philo.h"

void	exit_error(char *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		write(2, str, i);
	}
	exit(EXIT_FAILURE);
}
