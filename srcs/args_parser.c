#include "philo.h"

/*
 * ./philo number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 * */

int	check_args(char **args)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] == ' ' || args[i][j] == '\t')
			j++;
		if (args[i][j] == '-' || args[i][j] == '+')
		{
			if (args[i][j] == '-')
				return (0);
			j++;
		}
		if (args[i][j] <= '0' && args[i][j] >= '9')
			return (0);
		while (args[i][j] >= '0' && args[i][j] <= '9' && args[i][j] != '\"')
			j++;
		if (args[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while (*str)
	{
		num *= 10;
		num += (*str - '0');
		str++;
	}
	return (num * sign);
}

void	set_the_table(t_table *table, char **args)
{
	table->philo_nbr = ft_atol(args[1]);
	table->time_to_die = ft_atol(args[2]);
	table->time_to_eat = ft_atol(args[3]);
	table->time_to_sleep = ft_atol(args[4]);
	if (args[5])
		table->limit_meals = ft_atol(args[5]);
	else
		table->limit_meals = -1;
	table->start_time = get_msecs();
}
